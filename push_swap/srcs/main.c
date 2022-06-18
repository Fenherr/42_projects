/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:25:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/18 08:48:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_affiche(t_stack *lst)
{
    while (lst)
    {
        ft_printf("%d\n", lst->content);
        lst = lst->next;
    }
}

int main(int ac, char **av)
{
    int i;
    t_stack *first;

    i = 2;
    first = lstnew(av[1]);
    if (error(av[1]) == 1)
        exit(0);
    while (i < ac)
    {
        if (error(av[i]) == 1)
            exit(0);
        else
            first = addback(first, lstnew(av[i]));
        i++;
    }
    is_dup(first);
}