/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:56:49 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/09 16:27:03 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*interprete_quote(char *str)
{
	char	*res;
	char	quote;
	int		i;

	if (!str)
		return (str);
	res = ft_calloc(sizeof(char), 1);
	if (!res)
		return (str);
	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (str[i] == quote)
			quote = '\0';
		else if (str[i] == '"' && quote == '\0')
			quote = '"';
		else if (str[i] == '\'' && quote == '\0')
			quote = '\'';
		else
			res = add_char(res, str[i]);
		i++;
	}
	free(str);
	return (res);
}
