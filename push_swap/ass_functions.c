/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:25:28 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/16 14:34:39 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

void		fitter(struct p_l **stack_a, struct p_l **stack_b,
			struct p_l **fit)
{
	struct p_l *curr;

	last_node(stack_b, fit);
	if ((*stack_a)->elem > (*stack_b)->elem &&
		(*stack_a)->elem < (*fit)->elem)
	{
		(*fit) = (*stack_b);
		return ;
	}
	else
	{
		(*fit) = (*stack_b);
		curr = (*stack_b);
		while (curr && curr->next)
		{
			if ((*stack_a)->elem < curr->elem &&
				((*stack_a)->elem > curr->next->elem))
			{
				(*fit) = curr->next;
				return ;
			}
			curr = curr->next;
		}
	}
}

void		last_node(struct p_l **head, struct p_l **tail)
{
	if (*head)
	{
		(*tail) = (*head);
		while ((*tail)->next)
			(*tail) = (*tail)->next;
	}
}


void			display(struct p_l *list)
{
	struct p_l *point;

	if (list)
	{
		point = list;
		while (point != NULL)
		{
			ft_putnbr(point->elem);
			ft_putendl(" ");
			point = point->next;
		}
		return ;
	}
	ft_putendl("Nothing to print");
}

int			sa_check(struct p_l *head)
{
	if (head && head->next)
	{
		if (head->elem > (head->next)->elem)
			return (1);
	}
	return (0);
}

int			sb_check(struct p_l *head)
{
	if (head && head->next)
	{
		if (head->elem < (head->next)->elem)
			return (1);
	}
	return (0);
}
