/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:12:15 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/04 14:26:42 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	int content;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

t_stack *lstnew(int value);
t_stack *lstlast(t_stack *lst);
int is_dup(t_stack *stack);
int error(char *arg);
int lstsize(t_stack *lst);
int check_if_first_is_min(t_stack *lst);
void swap(int *a, int *b);
void swap_elm(t_stack *lst);
void addback(t_stack *lst, t_stack *new);
void addfront(t_stack **dest, t_stack *new);
void rotate(t_stack *lst);
void reverse(t_stack *lst);
void push(t_stack **src, t_stack **dest);
void sort(t_stack *lst);
void sort3(t_stack *lst);
void sort5(t_stack *lst);

#endif