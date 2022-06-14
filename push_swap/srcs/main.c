/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:25:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/14 17:20:28 by ngrenoux         ###   ########.fr       */
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
    t_stack *b;
    t_stack *keep;

    i = 2;
    first = lstnew(av[1]);
    b = NULL;
    while (i < ac)
    {
        first = addback(first, lstnew(av[i]));
        i++;
    }
    ft_affiche(first);
    ft_printf("stack\n");
    first = swap(first);
    ft_affiche(first);
    ft_printf("swap\n");
    first = rotate(first);
    ft_affiche(first);
    ft_printf("rotate\n");
    first = reverse(first);
    ft_affiche(first);
    ft_printf("reverse\n");
    keep = first->next;
    b = push(first, b);
    first = keep;
    ft_affiche(first);
    ft_printf("\n");
    ft_affiche(b);
    ft_printf("push\n");
}