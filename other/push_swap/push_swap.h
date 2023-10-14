/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:38:15 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/14 20:32:44 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <limits.h>

int		stacklen(t_list *stack);
void	sa(t_list *astack);
void	sb(t_list *bstack);
void	ss(t_list *astack, t_list *bstack);
void	pb(t_list **astack, t_list **bstack);
void	pa(t_list **astack, t_list **bstack);
void	ra(t_list *astack);
void	rb(t_list *bstack);
void	rr(t_list *astack, t_list *bstack);
void	rra(t_list *astack);
void	rrb(t_list *bstack);
void	rrr(t_list *astack, t_list *bstack);
t_list	*putnum(int number, t_list *astack, t_list *bstack);
void	freestack(t_list *stack);
int		checkinput(char **argv);
t_list	*makelist(char **argv, int argc, t_list *astack, t_list *bstack);
void	algothree(t_list *astack);
void	algofive(t_list **astack, t_list **bstack);
int		checkletter(char **argv);
int		findmin(t_list **stack);
void	algobig(t_list **astack, t_list **bstack);

#endif
