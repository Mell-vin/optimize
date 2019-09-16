/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:37:54 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/16 15:45:23 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int			counter(struct p_l *head)
{
	int counter;
	struct p_l *curr;

	counter = 0;
	if (head)
	{
	curr = head;
	while (curr)
		{
			counter++;
			curr = curr->next;
		}
	}
	return (counter);
}

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
		//if (sa_check(*stack_a))
		//	swap_sa_sb(stack_a);
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

void		finish(struct p_l **stack_a, struct p_l **stack_b,struct p_l **mid)
{
	struct p_l *max;

	large(stack_b, &max);
	while (max != (*stack_b))
	{
		if (above(max, *mid) == 1)
			rb(stack_b);
		else if (above(max, *mid) == 0)
			rrb(stack_b);
		large(stack_b, &max);
	}
	while (*stack_b)
	{
		pa(stack_b, stack_a);
	}
}

void		sorter(struct p_l **stack_a, struct p_l **stack_b, struct
			p_l **mid, struct p_l **fit, struct p_l **min)
{
	while (*stack_a)
	{
		if (counter(*stack_b) < 2)
			pb(stack_a, stack_b);
		if (counter(*stack_b) == 2)
		{
		//	ft_putendl("here");
			if ((*stack_b)->elem < ((*stack_b)->next)->elem)
			{
				//ft_putendl("here");
				sb(stack_b);
				//ft_putendl("here");
			}
		}
		if (counter(*stack_b) >= 2)
		{
			ft_putendl("here");
			small(stack_b, min);
			if ((*stack_a)->elem < (*min)->elem)
			{
				ft_putendl("here");
				pb(stack_a, stack_b);   //fix error here. it only pushes once if at all, then loops at two foreverrrrrrr
				rb(stack_b);
			}
			else
			{
				fitter(stack_a, stack_b, fit);
				while ((*fit) != (*stack_b))
				{
					if (above(*fit, *mid) == 1)
						rb(stack_b);
					else if (above(*fit, *mid) == 0)
						rrb(stack_b);
					fitter(stack_a, stack_b, fit);
				}
			}
		}
	}
}
