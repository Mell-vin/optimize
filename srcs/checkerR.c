/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerR.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:46:21 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/11 08:20:53 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Comm_ra_ch(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->size_a < 2)
		return ;
	i = 1;
	tmp = stacks->stack_a[0];
	while (i < stacks->size_a)
	{
		stacks->stack_a[i - 1] = stacks->stack_a[i];
		i++;
	}
	stacks->stack_a[i - 1] = tmp;
}

void	Comm_rb_ch(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->size_b < 2)
		return ;
	i = 1;
	tmp = stacks->stack_b[0];
	while (i < stacks->size_b)
	{
		stacks->stack_b[i - 1] = stacks->stack_b[i];
		i++;
	}
	stacks->stack_b[i - 1] = tmp;
}

void	Comm_rr_ch(t_stacks *stacks)
{
	int i;
	int tmp;

	if (stacks->size_a > 1)
	{
		i = 0;
		tmp = stacks->stack_a[0];
		while (++i < stacks->size_a)
			stacks->stack_a[i - 1] = stacks->stack_a[i];
		stacks->stack_a[i - 1] = tmp;
	}
	if (stacks->size_b > 1)
	{
		i = 0;
		tmp = stacks->stack_b[0];
		while (++i < stacks->size_b)
			stacks->stack_b[i - 1] = stacks->stack_b[i];
		stacks->stack_b[i - 1] = tmp;
	}
}
