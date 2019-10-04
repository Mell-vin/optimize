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
		p_l **midst, struct p_l **fit, struct p_l **min)
{
	int		count;
	int		loops;
	struct p_l	*max;
	struct p_l	*quar;
	struct p_l	*curr;

	large(stack_a, &max);
	count = counter((*stack_a)) / 4;
	quarter_list(stack_a, &max, &quar, min, count);
	loops = 0;
	while ((*stack_a) && loops <= count)
	{
		curr = quar;
		found = 0;
		while (curr)
		{
			if ((*stack_a)->elem == curr->elem)
			{
				fitter(stack_a, stack_b, fit);
				large(stack_b, &max);
				small(stack_b, min);
				mid(stack_b, midst, count);
				if (loops <= 2)
				{
					if ((*stack_b) == NULL)
						pb(stack_a, stack_b);
					else if ((*stack_a)->elem <
						(*stack_b)->elem)
					{
						pb(stack_a, stack_b);
						sb(stack_b);
					}
					else
						pb(stack_a, stack_b);
				}
				else if ((*stack_a)->elem < (*min)->elem)
				{
					while (max != (*stack_b))
					{
						if (above(max, *midst) == 1)
						{
							rb(stack_b);
						}
						else if (above(max, *midst) == 0)
						{
							rrb(stack_b);
						}
					}
					pb(stack_a, stack_b);
					rb(stack_b);
				}
				else if ((*stack_a)->elem > max->elem)
				{
					while (max != (*stack_b))
					{
						if (above(max, *midst) == 1)
						{
							rb(stack_b);
						}
						else if (above(max, *midst) == 0)
						{
							rrb(stack_b);
						}
					}
					pb(stack_a, stack_b);
				}
				else if ((*fit) == (*stack_b))
				{
					pb(stack_a, stack_b);
				}
				else if (above((*fit), (*midst)) == 1)
				{
					while ((*fit) != (*stack_b))
					{
						rb(stack_b);
					}
					pb(stack_a, stack_b);
				}
				else if (above((*fit), (*midst)) == 0)
				{
					while ((*fit) != (*stack_b))
					{
						rrb(stack_b);
					}
					pb(stack_a, stack_b);
				}
				loops++;
				found = 1;
			}
			curr = curr->next;
		}
		if (found == 0)
			ra(stack_a);
	}
	finish(stack_a, stack_b, midst);
}
