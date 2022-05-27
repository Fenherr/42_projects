/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:57:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/05/25 14:04:12 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int		value;
}t_stack;

typedef struct s_lst
{
	t_stack	*first;
}t_lst;

t_lst	*init(int val);
t_stack	*lastelm(t_lst *lst);
int	error(char *arg);
void	add_back(t_lst *lst, int val);
void	add_front(t_lst *lst, int val);
void	print_stack(t_lst *lst);
void	lstswap(t_lst *lst);
void	swap(int *a, int *b);
void	double_swap(t_lst *a, t_lst *b);
void	rotate(t_lst *lst);
void	double_rotate(t_lst *a, t_lst *b);
void	reverse_rotate(t_lst *lst);
void	delelm(t_lst *lst);

#endif
