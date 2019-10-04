/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
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

int			main(int ac, char **av)
{
	int *arr;
	struct p_l *smallest;
	struct p_l *head;
	struct p_l *head2;
	struct p_l *midst;
	//struct p_l *largest;
	struct p_l *fit;

	//i  = 1;
	if (ac > 1)
	{
		//while (av[i])
		//	i++;
		if (digi_check(av))
		{

			arr = arr_maker(av, (size_t)(ac) - 1);
			head = NULL;
			head2 = NULL;
			midst = NULL;
			//largest = NULL;
			fit = NULL;
			smallest = NULL;
			stack_a(arr, ac - 1, &head);
			small(&head, &smallest);
			//large(&head, &largest);
			mid(&head, &midst, ac - 1);
			sorter(&head, &head2, &midst, &fit, &smallest);
		}
		//display(head);
	}
	return (0);
}
