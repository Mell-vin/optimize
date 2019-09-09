/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:14:16 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/09 15:56:21 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

void		ra_rb_sa_sb(struct p_l **stack_a)
{
	if (*stack_a)
	{
		swap_ra_rb(stack_a);
		if (((*stack_a)->elem) > (((*stack_a)->next)->elem))
			swap_sa_sb(stack_a);
	}
}

void		rra_sa_sb(struct p_l **stack_a)
{
	if (*stack_a)
	{
		swap_rra(stack_a);
		if (((*stack_a)->elem) > (((*stack_a)->next)->elem))
		{
			swap_sa_sb(stack_a);
		}
	}
}

void		new_min(struct p_l **stack_a, struct p_l **stack_b, struct p_l **smallest)
{
	if (*stack_a && *smallest)
	{
		swap_pa_pb(stack_a, stack_b);
		if (*stack_a)
			small(stack_a, smallest);
		/*if (((*stack_b)->elem) < (((*stack_b)->next)->elem))
		{
			printf("new_min 2\n");
			swap_sa_sb(stack_b);
		}*/
	}
}


