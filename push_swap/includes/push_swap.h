/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:12:15 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/20 13:51:44 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	long long content;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

t_stack *lstnew(char *value);
t_stack *addback(t_stack *lst, t_stack *new);
t_stack *addfront(t_stack *lst, t_stack *new);
t_stack *lstlast(t_stack *lst);
t_stack *swap(t_stack *lst);
t_stack *rotate(t_stack *lst);
t_stack *reverse(t_stack *lst);
t_stack *push(t_stack *a, t_stack *b);
t_stack *sort3(t_stack *lst);
int is_dup(t_stack *stack);
int error(char *arg);

#endif