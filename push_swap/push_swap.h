/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:29:46 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/10 13:19:49 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack *next;
	int content;
} t_stack;

t_stack *init(int value);
t_stack *delelm(t_stack *lst);
t_stack *rotate(t_stack *lst);
t_stack *lastelm(t_stack *lst);
t_stack *reverse_rotate(t_stack *lst);
t_stack *push(t_stack *lst, t_stack *lst2);
void add_back(t_stack *lst, int value);
void print_stack(t_stack *a, t_stack *b);
void swap(int *a, int *b);
void lst_swap(t_stack *lst);
void sort(t_stack *a, t_stack *b);
void sort3(t_stack *lst);
int is_dup(t_stack *stack);
int error(char *arg);
#endif
