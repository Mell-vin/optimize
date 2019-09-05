/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:34:56 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/05 14:37:03 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

void		swap_2(struct p_l **head)
{
	struct p_l *current;

	if (*head)
	{
		current = (*head);
		current->prev = current->next;
		(current->next)->next = (current->next)->prev;
		current->next = NULL;
		(current->prev)->prev = NULL;
		(*head) = current->prev;
	}
}

void		swap_sa_sb(struct p_l **head)
{
	struct p_l *current;

	if (*head)
	{
		printf("swap_sa_sb\n");
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
	return ;
}


void            swap_pa_pb(struct p_l **stack_a, struct p_l **stack_b)
{
        struct p_l *current;

        if (*stack_a)
        {
				printf("swap_pb\n");
                current = (*stack_a);
                (*stack_a) = current->next;
				current->prev = NULL;
                current->next = (*stack_b);
                if ((*stack_b))
                        (*stack_b)->prev = current;
                (*stack_b) = current;
        }
}

void		swap_ra_rb(struct p_l **head)
{
	struct p_l *current;
	struct p_l *last;
	if (*head)
	{
		printf("swap_ra_rb\n");
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

void		swap_rra(struct p_l **head)
{
	struct p_l *current;
	struct p_l *last;

	if (*head)
	{
		printf("swap_rra\n");
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
