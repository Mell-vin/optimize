/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgumede  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 09:49:09 by lgumede           #+#    #+#             */
/*   Updated: 2019/09/11 08:53:09 by lgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483648

typedef struct	s_stacks
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
}				t_stacks;

typedef	struct	s_moves
{
	int			aComm;
	int			bComm;
	int			cComm;
	int			total;
	int			elem;
	char		*rot_a;
	char		*rot_b;
	char		*rot_c;
}				t_moves;


void			check_args(t_stacks *stacks, char **av, int ac);

int				is_sorted(int *stack, int size);
void			free_stacks(t_stacks **stacks);
void			free_moves(t_moves **moves);

void			sort(t_stacks *stacks);

void			bigStack(t_stacks *stacks);

void			Comm_sa(t_stacks *stacks);
void			Comm_sb(t_stacks *stacks);
void			Comm_ss(t_stacks *stacks);
void			Comm_pa(t_stacks *stacks);
void			Comm_pb(t_stacks *stacks);

void			Comm_sa_ch(t_stacks *stacks);
void			Comm_sb_ch(t_stacks *stacks);
void			Comm_ss_ch(t_stacks *stacks);
void			Comm_pa_ch(t_stacks *stacks);
void			Comm_pb_ch(t_stacks *stacks);

int				find_max(int *stack, int size);
int				find_min(int *stack, int size);
void			min_first(t_stacks *stacks);

void			Comm_ra(t_stacks *stacks);
void			Comm_rb(t_stacks *stacks);
void			Comm_rr(t_stacks *stacks);

void			Comm_rra(t_stacks *stacks);
void			Comm_rrb(t_stacks *stacks);
void			Comm_rrr(t_stacks *stacks);

void			Comm_ra_ch(t_stacks *stacks);
void			Comm_rb_ch(t_stacks *stacks);
void			Comm_rr_ch(t_stacks *stacks);

void			Comm_rra_ch(t_stacks *stacks);
void			Comm_rrb_ch(t_stacks *stacks);
void			Comm_rrr_ch(t_stacks *stacks);

int				find_rot_a(int len, int pos, char **rot);
int				find_rot_b(int len, int pos, char **rot);

t_moves			*least_moves_a_to_b(t_stacks *stacks);

#endif
