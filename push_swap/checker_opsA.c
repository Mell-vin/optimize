/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:22:34 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/16 14:01:14 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "../libft/libft.h"

void checker_sa(struct p_l **head)
{
	struct p_l *current;

	if (*head)
	{
		current = (*head);
		if ((current->next) == NULL)
			return;
		else if (((current->next)->next) == NULL)
		{
			swap_2(head);
			return;
		}
		else if (current->next)
		{
			current->prev = current->next;
			current->next = (current->next)->next;
			current = current->prev;
			current->next = current->prev;
			current->prev = NULL;
			current = (current->next)->next;
			current->prev = (current->prev)->next;
			(*head) = (current->prev)->prev;
		}
	}
	return;
}

void checker_pb(struct p_l **stack_a, struct p_l **stack_b)
{
	struct p_l *current;

	if (*stack_a)
	{
		current = (*stack_a);
		(*stack_a) = current->next;
		current->prev = NULL;
		current->next = (*stack_b);
		if ((*stack_b))
			(*stack_b)->prev = current;
		(*stack_b) = current;
	}
}

void checker_ra(struct p_l **head)
{
	struct p_l *current;
	struct p_l *last;
	if (*head)
	{
		current = (*head);
		if ((current->next) == NULL)
			return;
		else if (((current->next)->next) == NULL)
			swap_2(head);
		else
		{
			last_node(head, &last);
			current->prev = last;
			last->next = current;
			(*head) = current->next;
			current->next = NULL;
		}
	}
}

void checker_rra(struct p_l **head)
{
	struct p_l *current;
	struct p_l *last;

	if (*head)
	{
		current = (*head);
		if ((current->next) == NULL)
			return;
		else if (((current->next)->next) == NULL)
			swap_2(head);
		else
		{
			last = NULL;
			last_node(head, &last);
			(last->prev)->next = NULL;
			last->prev = NULL;
			last->next = (*head);
			current->prev = last;
			(*head) = last;
		}
	}
}

void checker_ss(struct p_l **stack_a, struct p_l **stack_b)
{
	if (*stack_a && *stack_b)
	{
		checker_sa(stack_a);
		checker_sb(stack_b);
	}
}