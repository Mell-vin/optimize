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
#include <stdio.h>

void		sort_3(struct p_l **stack_a, struct p_l **stack_b,
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

/*void		sort_5(struct p_l **stack_a, struct p_l **stack_b, struct
		p_l **mid, struct p_l **smallest)
{
	while (is_sorted(*stack_a) == 0)
	{
		small((stack_a), (smallest));
		if (sa_check(*stack_a))
			swap_sa_sb(stack_a);
		small(stack_a, smallest);
		if ((*smallest) != (*stack_a))
		{
			if (above(*smallest, *mid) == 1)
				ra(stack_a);
			else if (above(*smallest, *mid) == 0)
			{
				rra(stack_a);
			}
		}
		else if ((*smallest) == (*stack_a) && (((*stack_a)->next)->next != NULL))
			new_min(stack_a, stack_b, smallest);
	}
	while (*stack_b != NULL)
		pa(stack_b, stack_a);
}*/

void		finish(struct p_l **stack_a, struct p_l **stack_b,
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
	while(fit != (*stack_a))
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
}

void		sorter(struct p_l **stack_a, struct p_l **stack_b, struct
		p_l **midst, struct p_l **fit, struct p_l **quar)
{
	int		loops;
	int		found;
	struct p_l	*max;
	struct p_l	*min;
	struct p_l	*curr;
	printf("Stack-A******************************************\n\n");
	display(*stack_a);
	printf("quar*********************************************\n\n");
	display(*quar);

	loops = 0;
	//while (loops < 25)
	//{
		printf("\n\nLoops: %d\n\n", loops);
		curr = *quar;
		while (curr && (*stack_a))
		{
			found = 0;
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
						printf("\n0\n");
						pb(stack_a, stack_b);
					}
					else if ((*stack_a)->elem <
							(*stack_b)->elem)
					{
						printf("\n1\n");
						pb(stack_a, stack_b);
						printf("\n2\n");
						sb(stack_b);
					}
					else
					{
						printf("\n3\n");
						pb(stack_a, stack_b);
					}
				}
				else if ((*stack_a)->elem < (min)->elem)
				{
					while (max != (*stack_b))
					{
						if (above(max, *midst) == 1)
						{
							printf("\n4\n");
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
						printf("\n15\n");
						rrb(stack_b);
					}
					printf("\n16\n");
					pb(stack_a, stack_b);
				}
				loops++;
				found = 1;
			}
			if (found == 1)
			{
				printf("\nfrom the top of quar\n");
				curr = *quar;
			}
			else
			{
				printf("\nNext quar\n");
				curr = curr->next;
			}
		}
		if (found == 0)
		{
			printf("\n17\n");
			ra(stack_a);
		}
	//}
	printf("Finisher\n");
	finish(stack_a, stack_b, midst);
}
