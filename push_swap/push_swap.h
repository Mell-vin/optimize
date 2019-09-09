/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:57:49 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/09 16:23:58 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

struct p_l
{
	int elem;
	struct p_l *next;
	struct p_l *prev;
};
void		swap_pa_pb(struct p_l **stack_a, struct p_l **stack_b);
void		swap_rra(struct p_l **head);
void		swap_ra_rb(struct p_l **head);
void		last_node(struct p_l **head, struct p_l **tail);
void		display(struct p_l *list);
void		swap_2(struct p_l **head);
void		swap_pb(struct p_l **stack_a, struct p_l **stack_b);
void		stack_a(int *nbr, int size, struct p_l **stack_a);
//int		doop(int *nbr, size_t size);
int		*arr_maker(char **str, size_t size);
int		digi_check(char **str);
int		is_duplicate(struct p_l *head);
int		is_sorted(struct p_l *head);
int		av(struct p_l *head);
int		above(struct p_l *link, struct p_l *mid);
void		large(struct p_l **head, struct p_l **largest);
void		small(struct p_l **head, struct p_l **smallest);
void		mid(struct p_l **head, struct p_l **mid, int size);
void		swap_sa_sb(struct p_l **head);
void		sorter(struct p_l **stack_a, struct p_l **stack_b,
			struct p_l **largest);
void		ra_rb_sa_sb(struct p_l **stack_a);
void		rra_sa_sb(struct p_l **stack_a);
void		new_min(struct p_l **stack_a, struct p_l **stack_b,
		struct p_l **small);
int		sa_check(struct p_l *head);
int		sb_check(struct p_l *head);
#endif
