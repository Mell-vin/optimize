/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:25:27 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/09 15:55:39 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		is_sorted(struct p_l *head)
{
	struct p_l *current;
	if (head)
	{
		current = head;
		while (current->next)
		{
			if (current->elem > (current->next)->elem)
				return (0);
			current = current->next;
		}
		return (1);
	}
	return (-1);
}

int		is_duplicate(struct p_l *head)
{
	struct p_l *current;
	if (head)
	{
		current = head;
		while (current->next)
		{
			if (current->elem == (current->next)->elem)
				return (0);
			current = current->next;
		}
		return (1);
	}
	return (-1);
}


int		above(struct p_l *link, struct p_l *mid)
{
	struct p_l *current;

	if (link && mid)
	{
		current = link;
		while (current->next)
		{
			if (current == mid)
				return (1);
			current = current->next;
		}
		return (0);
	}
	return (-1);
}

void		large(struct p_l **head, struct p_l **largest)
{
	struct p_l *current;

	if ((*head))
	{
		(*largest) = (*head);
		current = (*largest)->next;
		while (current)
		{
			if (((*largest)->elem < current->elem))
			{
				(*largest) = current;
			}
			current = current->next;
		}
	}
}


void            small(struct p_l **head, struct p_l **smallest)
{
	struct p_l *current;

	if (*head)
	{
		(*smallest) = (*head);
		current = (*smallest)->next;
		while (current)
		{
			if (((*smallest)->elem > current->elem))
			{
				(*smallest) = current;
			}
			current = current->next;
		}
	}
}

void		mid(struct p_l **head, struct p_l **mid)
{
	size_t count;
	size_t new_size;

	if ((*head) && (*head)->next)
	{
		count = 1;
		new_size = counter((*head));
		(*mid) = (*head);
		while (count <= (new_size/2))
		{
			(*mid) = (*mid)->next;
			count++;
		}
	}
}
