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

int checker(struct p_l **stack_a, struct p_l **stack_b, char *comm)
{
    if (!ft_strcmp(comm, "sa"))
        checker_sa(stack_a);
    else if (!ft_strcmp(comm, "sb"))
        checker_sb(stack_b);
    else if (!ft_strcmp(comm, "ss"))
        checker_ss(stack_a, stack_b);
    else if (!ft_strcmp(comm, "pa"))
        checker_pa(stack_b, stack_a);
    else if (!ft_strcmp(comm, "pb"))
        checker_pb(stack_a, stack_b);
    else if (!ft_strcmp(comm, "ra"))
        checker_ra(stack_a);
    else if (!ft_strcmp(comm, "rb"))
        checker_rb(stack_b);
    else if (!ft_strcmp(comm, "rr"))
        checker_rr(stack_a, stack_b);
    else if (!ft_strcmp(comm, "rra"))
        checker_rra(stack_a);
    else if (!ft_strcmp(comm, "rrb"))
        checker_rrb(stack_b);
    else if (!ft_strcmp(comm, "rrr"))
        checker_rrr(stack_a, stack_b);
    else
    {
        ft_putendl("Error");
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
    char *comm;
    int i;
    int *arr = arr_maker(av, (size_t)(ac)-1);
    int err;
    struct p_l *head_a = NULL;
    struct p_l *head_b = NULL;

    err = 0;
    stack_a(arr, ac - 1, &head_a);
    i = get_next_line(0, &comm);
    while (is_sorted(head_a) != 1 && i > 0)
    {
        err = checker(&head_a, &head_b, comm);
        if (!err)
        {
            free(comm);
            close(0);
            return (0);
        }
        i = get_next_line(0, &comm);
    }
    free(comm);
    close(0);
    return (0);
}