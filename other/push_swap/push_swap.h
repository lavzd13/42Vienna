/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:38:15 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/18 18:35:42 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <limits.h>

int		stacklen(t_list **stack);
void	sa(t_list **astack);
void	sb(t_list **bstack);
void	ss(t_list **astack, t_list **bstack);
void	pb(t_list **astack, t_list **bstack);
void	pa(t_list **astack, t_list **bstack);
void	ra(t_list **astack);
void	rb(t_list **bstack);
void	rr(t_list **astack, t_list **bstack);
void	rra(t_list **astack);
void	rrb(t_list **bstack);
void	rrr(t_list **astack, t_list **bstack);
t_list	*putnum(int number, t_list **astack, t_list **bstack);
void	freestack(t_list **stack);
int		checkinput(char **argv);
t_list	*makelist(char **argv, int argc, t_list **astack, t_list **bstack);
void	algothree(t_list **astack);
void	algofive(t_list **astack, t_list **bstack);
int		checkletter(char **argv);
int		findmin(t_list **stack);
void	algobig(t_list **astack, t_list **bstack);
int		finpos(t_list **stack, int lowmax);
int		biggest(t_list **bstack, int current);
int		lowest(t_list **bstack, int current);
int		findlower(t_list **bstack, int current);
int		bcalc(t_list **bstack, int pos, int content);
int		acalc(t_list **astack, int content);
void	moving(t_list **astack, t_list **bstack, int num, int bmax);
int		bposcalc(t_list **bstack, int pos, int content);
int		findhigher(t_list **bstack, int current);
int		checkdescending(t_list **stack);
void	amoving(t_list **astack, t_list **bstack, int content);
int		checkascending(t_list **stack);
int		findmax(t_list **stack);

#endif
