/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:25:27 by lgumede           #+#    #+#             */
/*   Updated: 2019/08/30 14:46:30 by lgumede          ###   ########.fr       */
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

	if (*head)
	{
		current = (*head);
		(*largest) = current;
		while (current->next)
		{
			if ((current->next)->elem > current->elem)
				(*largest) = current->next;
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

void		mid(struct p_l **head, struct p_l **mid, int size)
{
	size_t count;
	size_t new_size;

	if (head)
	{
		count = 1;
		new_size = size;
		(*mid) = (*head);
		//if ((size % 2) == 1)
		//	new_size += 1;
		while (count <= (new_size/2))
		{
			(*mid) = (*mid)->next;
			count++;
		}
	}
}
