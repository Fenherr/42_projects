/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:21:58 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/01 14:43:03 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	int *stack_a;
	int *stack_b;
	int len_a;
	int len_b;
} t_stack;

t_stack *init(int ac);
int error(char *arg);
int search_pos_min(t_stack *lst);
char **check_format(char *av);
void is_dup(t_stack *lst);
void swap_a(t_stack *lst);
void swap_b(t_stack *lst);
void rotate_a(t_stack *lst);
void rotate_b(t_stack *lst);
void reverse_rot_a(t_stack *lst);
void reverse_rot_b(t_stack *lst);
void push_a(t_stack *lst);
void push_b(t_stack *lst);
void sort(t_stack *lst);
void sort3(t_stack *lst);
void sort4(t_stack *lst);
void sort5(t_stack *lst);
void min_to_first_pos(t_stack *lst);
void sort_more(t_stack *lst);

#endif