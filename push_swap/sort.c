/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:41:11 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/05 15:01:37 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void		swap_pb(struct p_l **stack_b, struct p_l **stack_a)
{
	struct p_l *current;

	if (*stack_b)
	{
		printf("swap_pa\n");
		current = (*stack_b);
		(*stack_b) = current->next;
		current->prev = NULL;
		current->next = (*stack_a);
		if ((*stack_a))
			(*stack_a)->prev = current;
		(*stack_a) = current;
	}

}

void		pb_sb(struct p_l **stack_a, struct p_l **stack_b)
{
	if (*stack_a)
	{
		swap_pa_pb(stack_a, stack_b);
		if ((*stack_b)->next)
		{
			if ((*stack_b)->elem < ((*stack_b)->next)->elem)
				swap_sa_sb(stack_b);	
		}
	}
}

int			av(struct p_l *head)
{
	int average;
	int counter;
	struct p_l *curr;

	counter = 0;
	average = 0;
	curr = head;
	while (curr)
	{
		average += curr->elem;
		counter++;
		curr = curr->next;
	}
	average /= counter;
	return (average);
}

void		sorter(struct p_l **stack_a, struct p_l **stack_b)
{
	int avg;

	avg = av((*stack_a));
	while (is_sorted(*stack_a) == 0)
	{
		//counter
		if ((*stack_a)->elem < avg)
		{
			printf("entry\n");
			pb_sb(stack_a, stack_b);
			printf("exit\n");
		}
		printf("here\n");
		swap_ra_rb(stack_a);
		if ((*stack_b) && (*stack_b)->elem < ((*stack_b)->next)->elem)
		{
			printf("here\n");
			swap_sa_sb(stack_b);
		}
	}
	while ((*stack_b))
	{
		printf("here\n");
		swap_pb(stack_b, stack_a);
	}
}
