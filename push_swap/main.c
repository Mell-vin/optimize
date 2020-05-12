/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
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

int main(int ac, char **av)
{
	int *arr;
	struct p_l *head;
	struct p_l *head2;
	//struct p_l *quar;
	struct p_l *midst;
	struct p_l *fit;

	if (ac > 1 && digi_check(av))
	{
		arr = arr_maker(av, (size_t)(ac)-1);
		head = NULL;
		//quar = NULL;
		midst = NULL;
		fit = NULL;
		head2 = NULL;
		//quar = NULL;
		stack_a(arr, ac - 1, &head);
		//Orderlist(&head, &quar, ac - 1);
		sort_5(&head, &head2, &midst, &fit);
		//display(head);
	}
	return (0);
}