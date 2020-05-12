/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:37:54 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/17 15:01:34 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include "stdlib.h"
#include <stdio.h>

void sort_3(struct p_l **stack_a, struct p_l **stack_b,
			struct p_l **min)
{
	small(stack_a, min);
	while (!(is_sorted(*stack_a)))
	{
		if ((*min) == (*stack_a))
		{
			pb(stack_a, stack_b);
			sa(stack_a);
			pb(stack_b, stack_a);
		}
		else if ((*min) == (*stack_a)->next)
		{
			if ((*stack_a)->elem > (*stack_a)->next->next->elem)
				ra(stack_a);
			else
				sa(stack_a);
		}
		else if ((*min) == (*stack_a)->next->next)
		{
			if ((*stack_a)->elem > (*stack_a)->next->elem)
			{
				sa(stack_a);
				rra(stack_a);
			}
			else
				rra(stack_a);
		}
	}
}

void sort_5(struct p_l **stack_a, struct p_l **stack_b, struct p_l **midst, struct p_l **smallest)
{
	while (is_sorted(*stack_a) == 0)
	{
		small((stack_a), (smallest));
		mid(stack_a, midst);
		if (sa_check(*stack_a))
		{
			//printf("\n1)\n");
			sa(stack_a);
		}
		if ((*smallest) != (*stack_a))
		{
			if (above(*smallest, *midst) == 1)
			{
				//printf("\n2)\n");
				ra(stack_a);
			}
			else if (above(*smallest, *midst) == 0)
			{
				//printf("\n3)\n");
				rra(stack_a);
			}
		}
		else if ((*smallest) == (*stack_a) && (((*stack_a)->next)->next != NULL))
		{
			//printf("\n4)\n");
			pb(stack_a, stack_b);
		}
	}
	while (*stack_b != NULL)
		pa(stack_b, stack_a);
}

void finish(struct p_l **stack_a, struct p_l **stack_b,
			struct p_l **mid)
{
	struct p_l *max;
	struct p_l *fit;

	large(stack_b, &max);
	while (max != (*stack_b))
	{
		if (above(max, *mid) == 1)
			rb(stack_b);
		else if (above(max, *mid) == 0)
			rrb(stack_b);
		large(stack_b, &max);
	}
	fitter(stack_b, stack_a, &fit);
	while (fit != (*stack_a))
	{
		if (above(fit, *mid) == 1)
			ra(stack_a);
		else if (above(fit, *mid) == 0)
			rra(stack_a);
	}
	while (*stack_b)
	{
		pa(stack_b, stack_a);
	}
	return;
}

void sorter(struct p_l **stack_a, struct p_l **stack_b, struct p_l **midst, struct p_l **fit, struct p_l **quar)
{
	int loops;
	struct p_l *max;
	struct p_l *min;
	struct p_l *curr;

	loops = 0;
	curr = *quar;
	while (curr && (*stack_a))
	{
		printf("hau2\n");
		if ((*stack_a)->elem == curr->elem)
		{
			fitter(stack_a, stack_b, fit);
			large(stack_b, &max);
			small(stack_b, &min);
			mid(stack_b, midst);
			if (loops < 2)
			{
				if ((*stack_b) == NULL)
				{
					printf("\n1\n");
					pb(stack_a, stack_b);
				}
				else if ((*stack_a)->elem <
						 (*stack_b)->elem)
				{
					printf("\n2\n");
					pb(stack_a, stack_b);
					printf("\n3\n");
					sb(stack_b);
				}
				else
				{
					printf("\n4\n");
					pb(stack_a, stack_b);
				}
			}
			else if ((*stack_a)->elem < (min)->elem)
			{
				while (max != (*stack_b))
				{
					if (above(max, *midst) == 1)
					{
						printf("\n5\n");
						rb(stack_b);
					}
					else if (above(max, *midst) == 0)
					{
						printf("\n5\n");
						rrb(stack_b);
					}
				}
				printf("\n6\n");
				pb(stack_a, stack_b);
				printf("\n7\n");
				rb(stack_b);
			}
			else if ((*stack_a)->elem > max->elem)
			{
				while (max != (*stack_b))
				{
					if (above(max, *midst) == 1)
					{
						printf("\n8\n");
						rb(stack_b);
					}
					else if (above(max, *midst) == 0)
					{
						printf("\n9\n");
						rrb(stack_b);
					}
				}
				printf("\n10\n");
				pb(stack_a, stack_b);
			}
			else if ((*fit) == (*stack_b))
			{
				printf("\n11\n");
				pb(stack_a, stack_b);
			}
			else if (above((*fit), (*midst)) == 1)
			{
				while ((*fit) != (*stack_b))
				{
					printf("\n12\n");
					rb(stack_b);
				}
				printf("\n13\n");
				pb(stack_a, stack_b);
			}
			else if (above((*fit), (*midst)) == 0)
			{
				while ((*fit) != (*stack_b))
				{
					printf("\n14\n");
					rrb(stack_b);
				}
				printf("\n15\n");
				pb(stack_a, stack_b);
			}
			loops++;
			printf("\nloop growth: %d\n", loops);
			curr = *quar;
		}
		else
		{
			curr = curr->next;
			printf("\n16\n");
			ra(stack_a);
		}
	}
	printf("\n17\n");
	finish(stack_a, stack_b, midst);
	return;
}
