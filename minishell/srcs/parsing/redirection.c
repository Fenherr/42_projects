/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:51:43 by aderouba          #+#    #+#             */
/*   Updated: 2022/12/09 13:17:39 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_file_next2(char **tmp, char **split_res, int i)
{
	if (ft_strstr(split_res[i], ">>") != NULL && split_res[i][0] == '>'
		&& split_res[i][1] == '>')
	{
		*tmp = ft_substr(split_res[i], 2, ft_strlen(split_res[i]));
		return (4);
	}
	else if (is_in_str(split_res[i], '<') && split_res[i][0] == '<')
	{
		*tmp = ft_substr(split_res[i], 1, ft_strlen(split_res[i]));
		return (1);
	}
	else if (is_in_str(split_res[i], '>') && split_res[i][0] == '>')
	{
		*tmp = ft_substr(split_res[i], 1, ft_strlen(split_res[i]));
		return (3);
	}
	return (10);
}

int	get_file_next(char **tmp, char **split_res, int i)
{
	if (ft_strcmp(split_res[i], "<") == 0)
		return (1);
	else if (ft_strcmp(split_res[i], "<<") == 0)
		return (2);
	else if (ft_strcmp(split_res[i], ">") == 0)
		return (3);
	else if (ft_strcmp(split_res[i], ">>") == 0)
		return (4);
	else if (ft_strstr(split_res[i], "<<") != NULL && split_res[i][0] == '<'
		&& split_res[i][1] == '<')
	{
		*tmp = ft_substr(split_res[i], 2, ft_strlen(split_res[i]));
		return (2);
	}
	else
		return (get_file_next2(tmp, split_res, i));
}

char	*final_check_and_return(int file_next, char **split_res, char *res)
{
	ft_lstr_free(split_res);
	if (file_next != 0 && file_next != 10)
	{
		free(res);
		ft_printf_fd("Error: syntax error near", 2);
		ft_printf_fd(" unexpected token `newline'\n", 2);
		return (NULL);
	}
	return (res);
}

char	*tmp_gestion(char *tmp, char *name, int file_next)
{
	if (!tmp && file_next > 0 && file_next < 10)
		return (ft_strdup(name));
	return (tmp);
}

char	*interprete_redirection(t_data *data, t_cmd *cmd, char *input)
{
	char	**split_res;
	char	*res;
	char	*tmp;
	int		i;
	int		file_next;

	res = ft_calloc(sizeof(char), 1);
	split_res = ft_split_redirection(input);
	i = 0;
	file_next = 0;
	tmp = NULL;
	while (res && split_res && split_res[i])
	{
		tmp = tmp_gestion(tmp, split_res[i], file_next);
		if (file_next > 0 && file_next < 10)
			file_next = get_fd(data, cmd, &tmp, file_next);
		else
			file_next = get_file_next(&tmp, split_res, i);
		if (cmd->fd_in == -1 || cmd->fd_out == -1 || file_next == -1)
			return (error_file(cmd, res, split_res));
		else if (file_next == 10)
			res = ft_strsuperjoin_free_1st_p(res, split_res[i], " ");
		i += (tmp == NULL && file_next >= 0);
	}
	return (final_check_and_return(file_next, split_res, res));
}
