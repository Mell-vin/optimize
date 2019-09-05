/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:25:28 by lgumede           #+#    #+#             */
/*   Updated: 2019/08/13 14:12:20 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

void		last_node(struct p_l **head, struct p_l **tail)
{
	if (*head)
	{
		(*tail) = (*head);
		while ((*tail)->next)
			(*tail) = (*tail)->next;
	}
}

size_t			link_size(struct p_l *head)
{
	size_t count;
	struct p_l *current;

	if (head)
	{
		current = head;
		count = 1;
		while (current->next)
		{
			current = current->next;
			count++;
		}
		return (count);
	}
	return (0);
}

void			display(struct p_l *list)
{
	struct p_l *point;

	if (list)
	{
		point = list;
		while (point != NULL)
		{
			printf("%d\n", point->elem);
			point = point->next;
		}
		return ;
	}
	printf("Nothing to print\n");
}

int			sa_check(struct p_l *head)
{
	if (head->elem > (head->next)->elem)
		return (1);
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
