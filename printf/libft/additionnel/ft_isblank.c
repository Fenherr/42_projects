/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:09:01 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/04/12 11:18:10 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_isblank(int c)
{
	return (c == 32 || c == 9);
}