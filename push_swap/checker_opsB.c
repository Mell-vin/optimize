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

void		checker_sb(struct p_l **head)
{
	struct p_l *current;

	if (*head)
	{
		current = (*head);
		if ((current->next) == NULL)
			return ;
		else if (((current->next)->next) == NULL)
		{
			swap_2(head);
			return ;
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
}

void		checker_pa(struct p_l **stack_b, struct p_l **stack_a)
{
        struct p_l *current;

        if (*stack_b)
        {
                current = (*stack_b);
                (*stack_b) = current->next;
				current->prev = NULL;
                current->next = (*stack_a);
                if ((*stack_a))
                        (*stack_a)->prev = current;
                (*stack_a) = current;
        }
}

void		checker_rb(struct p_l **head)
{
	struct p_l *current;
	struct p_l *last;
	if (*head)
	{
		current = (*head);
		if ((current->next) == NULL)
			return ;
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

void		checker_rrb(struct p_l **head)
{
	struct p_l *current;
	struct p_l *last;

	if (*head)
	{
		current = (*head);
		if ((current->next) == NULL)
			return ;
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

void        checker_rr(struct p_l **stack_a, struct p_l **stack_b)
{
    if ((*stack_a) && (*stack_b))
    {
        checker_ra(stack_a);
        checker_rb(stack_b);
    }
}

void        checker_rrr(struct p_l **stack_a, struct p_l **stack_b)
{
    if ((*stack_a) && (*stack_b))
    {
        checker_rra(stack_a);
        checker_rrb(stack_b);
    }
}