/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:16:31 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/08/29 16:16:01 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	*tmp_tab;
	int	*index_tab;
	int	len_a;
	int	len_b;
}	t_stack;

t_stack	*init(int ac, char *av);
int		check_space(char *arg);
int		is_sorted(t_stack *lst);
void	error(char *arg);
void	is_dup(t_stack *lst);
void	filling_stack(t_stack *lst, int ac, char **av);
void	free_stack(t_stack *lst);
void	swap_a(t_stack *lst);
void	swap_b(t_stack *lst);
void	push_a(t_stack *lst);
void	push_b(t_stack *lst);
void	reverse_rot_a(t_stack *lst);
void	reverse_rot_b(t_stack *lst);
void	rotate_a(t_stack *lst);
void	rotate_b(t_stack *lst);
void	sort(t_stack *lst);
void	sort3(t_stack *lst);
void	sort5(t_stack *lst);
void	sort_more(t_stack *lst);
void	min_to_first_pos(t_stack *lst, int len);
void	filling_index(t_stack *lst);
void	lstaff(t_stack *lst);

#endif