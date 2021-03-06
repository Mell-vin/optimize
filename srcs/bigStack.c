/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigStack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:37:49 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/11 08:36:54 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_place_in_a(int *stack, int size, int elem, char **rot_type)
{
	int i;
	int place;

	i = 0;
	place = 0;
	if (size == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (size == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max(stack, size)] ||
			elem < stack[find_min(stack, size)])
		place = find_min(stack, size);
	else
		while (i < size)
		{
			if (elem > stack[i] && ((i + 1 < size && elem < stack[i + 1]) ||
							(i + 1 == size && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_rot_a(size, place, rot_type));
}

static void	push_back(t_stacks *stacks)
{
	int		rotn;
	char	*rot_type;

	rotn = 0;
	rot_type = ft_strnew(3);
	while (stacks->size_b)
	{
		rotn = find_place_in_a(stacks->stack_a, stacks->size_a,
				stacks->stack_b[0], &rot_type);
		while (rotn > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				Comm_ra(stacks);
			else
				Comm_rra(stacks);
			rotn--;
		}
		Comm_pa(stacks);
	}
	min_first(stacks);
	free(rot_type);
}

static void	push_remainder(t_stacks *stacks)
{
	int i;

	i = 0;
	while (stacks->size_a > 2)
	{
		i = find_min(stacks->stack_a, stacks->size_a);
		if (i == 0)
			Comm_pb(stacks);
		else if (i <= stacks->size_a / 2)
			Comm_ra(stacks);
		else if (i > stacks->size_a / 2)
			Comm_rra(stacks);
	}
}

static void	do_moves(t_moves *moves, t_stacks *stacks)
{
	while (moves->aComm)
	{
		if (ft_strequ(moves->rot_a, "ra"))
			Comm_ra(stacks);
		else
			Comm_rra(stacks);
		moves->aComm--;
	}
	while (moves->bComm)
	{
		if (ft_strequ(moves->rot_b, "rb"))
			Comm_rb(stacks);
		else
			Comm_rrb(stacks);
		moves->bComm--;
	}
}

void		bigStack(t_stacks *stacks)
{
	t_moves *best_moves;
	int		optimal;

	optimal = (stacks->size_a > 200) ? 50 : 2;
	while (stacks->size_b != 2)
		Comm_pb(stacks);
	while (stacks->size_a > optimal)
	{
		best_moves = least_moves_a_to_b(stacks);
		while (best_moves->cComm)
		{
			if (ft_strequ(best_moves->rot_c, "rr"))
				Comm_rr(stacks);
			else
				Comm_rrr(stacks);
			best_moves->cComm--;
		}
		do_moves(best_moves, stacks);
		Comm_pb(stacks);
		free_moves(&best_moves);
	}
	push_remainder(stacks);
	push_back(stacks);
}
