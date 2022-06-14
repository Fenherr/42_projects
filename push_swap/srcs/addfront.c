/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addfront.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:08:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/06/14 17:10:30 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *addfront(t_stack *lst, t_stack *new)
{
    if (!lst || !new)
        return (NULL);
    new->next = lst;
    new->prev = NULL;
    lst->prev = new;
    return (new);
}