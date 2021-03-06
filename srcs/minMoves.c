/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minMoves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:49:53 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/11 08:45:10 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_place_b(int *stack, int size, int elem, char **rot)
{
	int i;
	int place;

	i = 0;
	place = 0;
	if (size == 2 && elem > stack[0] && elem < stack[1])
		place = 0;
	else if (size == 2 && elem < stack[0] && elem > stack[1])
		place = 1;
	else if (elem > stack[find_max(stack, size)] ||
			elem < stack[find_min(stack, size)])
		place = find_max(stack, size);
	else
		while (i < size)
		{
			if (elem < stack[i] && ((i + 1 < size && elem > stack[i + 1]) ||
						(i + 1 == size && elem > stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_rot_b(size, place, rot));
}

static int		find_common(t_moves *moves)
{
	int c;

	c = 0;
	if ((ft_strequ(moves->rot_a, "rra") && (ft_strequ(moves->rot_b, "rrb"))) ||
			(ft_strequ(moves->rot_a, "ra") && (ft_strequ(moves->rot_b, "rb"))))
	{
		c = (moves->aComm > moves->bComm ? moves->bComm : moves->aComm);
		if (c)
		{
			moves->rot_c = ft_strcpy(moves->rot_c, moves->rot_a);
			moves->rot_c[ft_strlen(moves->rot_c) - 1] = 'r';
			moves->bComm = moves->bComm - c;
			moves->aComm = moves->aComm - c;
		}
	}
	return (c);
}

static t_moves	*calcComm_a_to_b(t_stacks *stacks, int pos)
{
	t_moves *moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->rot_a = ft_strnew(3);
	moves->rot_b = ft_strnew(3);
	moves->rot_c = ft_strnew(3);
	moves->elem = stacks->stack_a[pos];
	moves->aComm = find_rot_a(stacks->size_a, pos, &(moves->rot_a));
	moves->bComm = find_place_b(stacks->stack_b, stacks->size_b,
			stacks->stack_a[pos], &(moves->rot_b));
	moves->cComm = find_common(moves);
	moves->total = moves->aComm + moves->bComm + moves->cComm + 1;
	return (moves);
}

t_moves			*least_moves_a_to_b(t_stacks *stacks)
{
	int		i;
	t_moves *least;
	t_moves *moves;

	i = 0;
	while (i < stacks->size_a)
	{
		moves = calcComm_a_to_b(stacks, i);
		if (i == 0)
			least = moves;
		else if (least->total > moves->total)
		{
			free_moves(&least);
			least = moves;
		}
		else
			free_moves(&moves);
		i++;
	}
	return (least);
}
