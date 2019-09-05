/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:09:12 by lgumede           #+#    #+#             */
/*   Updated: 2019/08/29 14:53:52 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

/* digi_check checks the arguments to ensure that they are all valid numbers.
 * if valid, it returns 1, else 0 */

int			digi_check(char **str)
{
	size_t i;
	size_t j;

	if (str)
	{
		i = 1;
		while (str[i])
		{
			j = 0;
			while (str[i][j])
			{
				if (str[i][j] == '-' || str[i][j] == '+')
					j++;
				if (!ft_isdigit(str[i][j]))
				{
					ft_putendl("error");
					return (0);
				}
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

/* arr_maker takes a char ** arg, checks for invalid input, then mallocs space to temprarily
 * store the numbers that it returns for checkinf of duplicate numbers later */


int			*arr_maker(char **str, size_t size)
{
	int *nbr;
	size_t i;
	size_t j;

	if (str && digi_check(str))
	{
		nbr = (int *)malloc(sizeof(int) * size);
		if (nbr)
		{
			i = 1;
			j = 0;
			while (str[i])
			{
				nbr[j] = ft_atoi(str[i]);
				j++;
				i++;
			}
		}
		return (nbr);
	}
	return (NULL);
}

/* doops takes an int arrar and removes all the duplicating numbers, and returns its new size*/

int			doop(int *nbr, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	if (nbr && size)
	{
		i = 0;
		while (i < size)
		{
			j = i + 1;
			while (j < size)
			{
				if (nbr[i] == nbr[j])
				{
					k = j;
					while (k < size)
					{
						nbr[k] = nbr[k + 1];
						k++;
					}
					size--;
					j--;
				}
				j++;
			}
			i++;
		}
		return (size - 1);
	}
	return (0);
}

void		stack_a(int *nbr, int size, struct p_l **stack_a)
		
{
	struct p_l *current;
	struct p_l *new_;
	int i;

	if (nbr && size)
	{
		i = 0;
		(*stack_a) = (struct p_l *)malloc(sizeof(struct p_l));
		if (*stack_a)
		{
			current = (*stack_a);
			current->next = NULL;
			current->elem = nbr[i];
			current->prev = NULL;
			while (i + 1 < size)
			{
				new_ = (struct p_l *)malloc(sizeof(struct p_l));
				if (new_)
				{
					new_->prev = current;
					current->next = new_;
					current = current->next;
					current->elem = nbr[i + 1];
					current->next = NULL;
				}
				i++;
			}
		}
	}
}
