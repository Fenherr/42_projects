/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:51:43 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/13 12:57:39 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	len_word_redirection(char const *s, char *sep, int *i)
{
	int		len;
	char	quote;

	len = 0;
	quote = '\0';
	quote = quote_gestion(s[*i], quote);
	while (quote == '\0' && (s[*i + len] == '<' || s[*i + len] == '>')
		&& s[*i + len] != '\0')
	{
		len++;
		quote = quote_gestion(s[*i + len], quote);
	}
	while ((quote != '\0' || !is_in_str(sep, s[*i + len]))
		&& s[*i + len] != '\0')
	{
		len++;
		quote = quote_gestion(s[*i + len], quote);
	}
	return (len);
}

char	**ft_split_redirection(char *s)
{
	int		i;
	int		len;
	char	**res;

	if (s == NULL)
		return (NULL);
	res = malloc(sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[0] = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		while (is_in_str(" \t", s[i]))
			i++;
		if (s[i] == '\0')
			break ;
		len = len_word_redirection(s, " \t<>", &i);
		res = ft_add_str(res, ft_substr(s, i, len));
		i += len;
	}
	return (res);
}

int	is_pipe_error(t_data *data, int *only_space, int *nb_cmd)
{
	if (*only_space)
	{
		data->pipe_error = *nb_cmd;
		g_exit_status = 2;
		ft_printf_fd("Error: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	(*nb_cmd)++;
	*only_space = 1;
	return (0);
}

void	pipe_error(t_data *data, char *buf)
{
	int		i;
	int		nb_cmd;
	int		only_space;
	char	quote;

	data->pipe_error = -1;
	if (!is_in_str(buf, '|'))
		return ;
	i = 0;
	nb_cmd = 0;
	only_space = 1;
	quote = '\0';
	while (buf[i])
	{
		quote = quote_gestion(buf[i], quote);
		if (quote == '\0' && buf[i] == '|'
			&& is_pipe_error(data, &only_space, &nb_cmd))
			return ;
		else if (buf[i] != ' ' && buf[i] != '\t')
			only_space = 0;
		i++;
	}
	if (is_pipe_error(data, &only_space, &nb_cmd))
		return ;
}
