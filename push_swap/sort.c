/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:41:11 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/09 16:23:55 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void		swap_pa(struct p_l **stack_b, struct p_l **stack_a)
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

void		sorter_b(struct p_l **stack_a, struct p_l **stack_b,
			struct p_l **largest)
{
	large(stack_b, largest);
	display(*largest);
	printf("\n\n\n");
	display(*stack_b);
	return ;
	while ((*stack_b))
	{
		large(stack_b, largest);
		while ((*stack_b) != (*largest))
			swap_ra_rb(stack_b);
		if ((*stack_b) == (*largest))
			swap_pa(stack_b, stack_a);
	}
	display(*stack_a);
}

void		sorter(struct p_l **stack_a, struct p_l **stack_b,
			struct p_l **largest)
{
	int avg;
	//int counter;
	//int pbcount;

	//pbcount = 0;
//	counter = 0;
	while ( (*stack_a) && is_sorted(*stack_a) == 0 /*&& counter <= 15*/)
	{
	//	counter++;
		avg = av((*stack_a));
		//printf("\t\t\t\t\t AVG: %d\n", avg);
		//if ((sa_check(*stack_a) == 1))
		//	swap_sa_sb(stack_a);
		if ((*stack_a)->elem < avg)
		{
			//printf("entry\n");
			//pbcount++;
			//printf("pb count:\t\t\t%d\n", pbcount);
			pb_sb(stack_a, stack_b);
			//printf("exit\n");
		}
		else
			swap_ra_rb(stack_a);
		if ((*stack_b) && ((*stack_b)->next) &&
		((*stack_b)->elem < ((*stack_b)->next)->elem))
		{
				//printf("heren\n");
				swap_ra_rb(stack_b);
		}
	}
	display(*stack_b);
	printf("\n\n\n");
	sorter_b(stack_b, stack_a, largest);
}
