/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:57:49 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/16 14:46:33 by lgumede          ###   ########.fr       */
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
void		pb(struct p_l **stack_a, struct p_l **stack_b);
void		sa(struct p_l **head);
void		sb(struct p_l **head);
void		pa(struct p_l **stack_b, struct p_l **stack_a);
void		rra(struct p_l **head);
void		rrb(struct p_l **head);
void		rb(struct p_l **head);
void		ra(struct p_l **head);
void		display(struct p_l *list);
void		swap_2(struct p_l **head);
void		stack_a(int *nbr, int size, struct p_l **stack_a);
void		fitter(struct p_l **stack_a, struct p_l **stack_b,
		struct p_l **fit);
void		Orderlist(struct p_l **stack_a, struct p_l **quar, int
		count);
void		last_node(struct p_l **head, struct p_l **tail);
int		*arr_maker(char **str, size_t size);
int		compare(struct p_l **stack_a, struct p_l **quar);
int		digi_check(char **str);
int		is_duplicate(struct p_l *head);
int		is_sorted(struct p_l *head);
int		av(struct p_l *head);
int		counter(struct p_l *head);
int		above(struct p_l *link, struct p_l *mid);
void		large(struct p_l **head, struct p_l **largest);
void		small(struct p_l **head, struct p_l **smallest);
void		mid(struct p_l **head, struct p_l **mid);
void		swap_sa_sb(struct p_l **head);
void		sorter(struct p_l **stack_a, struct p_l **stack_b,
		struct p_l ** midst, struct p_l **fit, struct p_l **smallest);
void		ra_rb_sa_sb(struct p_l **stack_a);
void		rra_sa_sb(struct p_l **stack_a);
void		new_min(struct p_l **stack_a, struct p_l **stack_b,
		struct p_l **smallest);
int		sa_check(struct p_l *head);
int		sb_check(struct p_l *head);

#endif
