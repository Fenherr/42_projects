/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:34:27 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/07/21 16:07:35 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**check_format(char *av)
{
	char	**arr;
	if (ft_strchr(av, ' '))
		arr = ft_split(av, ' ');
	return (arr);
}