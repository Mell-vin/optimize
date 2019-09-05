/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:35:02 by lgumede           #+#    #+#             */
/*   Updated: 2019/07/24 14:56:53 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/* ft_isnumCount checks if all arguments are valid numbers, and
 * counts the number of arguments and returns 'count'*/

size_t			ft_isnumCount(char const **str)
{
	size_t i;
	size_t j;
	size_t count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				j++;
			if (!ft_isdigit(str[i][j]))
				return(0);
			j++;
		}
		i++;
		count++;
	}
	return (count);
}

/*stack_a_create allocates memory for the args in struct 'p_l' for stack a, and returns
 * the new struct with memory for *nbr */

static p_l		stack_a_create(size_t size)
{
	p_l new;

	new->nbr = (size_t *)malloc(sizeof(size_t) * size);
	if (!(new->nbr))
		return (NULL);
	new->size = size;
	return (new);
}

/*stack_b_create does the same as stack_a_create, with the exception that size is initialised to zero to help us know exactly how many numbers are in the stack after each operation*/

static p_l		stack_b_create(size_t size)
{
	p_l new;

	new.nbr = (size_t *)malloc(sizeof(size_t) * size);
	if (!new->nbr)
		return (NULL);
	new->size = 0;
	ft_bzero((size_t *)(new->nbr), size);
	return (new);
}
/*arg_put converts the char strings to int using atoi and stores them in the int * nbr of
 * the new p_l typedef struct created, and returns the new struct*/

p_l				arg_put(char const **str)
{
	p_l		*new;
	int		*hold;
	size_t	i;

	new = stack_a_create(ft_isnumCount(str));
	if (!new)
		return (NULL);
	hold = new->nbr;
	i = 1;
	while (str[i])
	{
		hold = ft_atoi(str[i]);
		*hold++;
		i++;
	}
	new->size = ft_isnumCount(str);
	return (new);
}
/* the void function 'option' takes the number of args to be sorted, and then calls
 * a function to sort that range of a number of args*/

void			option(p_l *pile_a,p_l *pile_b, size_t count)
{
if (count == 0)
	return ;
else if (count == 1)
	res_display(&pile);
else if (count == 2)
	swap_2(&pile);
else if (count >= 3)
	swap_3(&pile);
else
	swap_pile(&pile_a, &pile_b);
}
