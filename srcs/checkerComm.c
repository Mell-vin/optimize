/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerComm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:44:23 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/11 08:16:02 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Comm_sa_ch(t_stacks *stacks)
{
	int tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
}

void	Comm_sb_ch(t_stacks *stacks)
{
	int tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
}

void	Comm_ss_ch(t_stacks *stacks)
{
	int tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = tmp;
	}
	if (stacks->size_b > 1)
	{
		tmp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = tmp;
	}
}

void	Comm_pa_ch(t_stacks *stacks)
{
	int i;

	if (stacks->size_b == 0)
		return ;
	i = stacks->size_a;
	while (i--)
		stacks->stack_a[i + 1] = stacks->stack_a[i];
	stacks->stack_a[0] = stacks->stack_b[0];
	i = 0;
	while (i++ <= stacks->size_b)
		stacks->stack_b[i - 1] = stacks->stack_b[i];
	stacks->size_a++;
	stacks->size_b--;
}

void	Comm_pb_ch(t_stacks *stacks)
{
	int i;

	if (stacks->size_a == 0)
		return ;
	i = stacks->size_b;
	while (i--)
		stacks->stack_b[i + 1] = stacks->stack_b[i];
	stacks->stack_b[0] = stacks->stack_a[0];
	i = 0;
	while (i++ <= stacks->size_a)
		stacks->stack_a[i - 1] = stacks->stack_a[i];
	stacks->size_b++;
	stacks->size_a--;
}
