/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:11:43 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/18 20:27:36 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*ft_search_env_path(char **envp)
{
	char	*env_path;
	int		i;

	i = 0;
	env_path = NULL;
	while (envp[i] != NULL && envp[i][0] != '\0')
	{
		env_path = ft_strnstr(envp[i], "PATH=", 5);
		if (env_path)
		{
			env_path = ft_substr(env_path, 5, ft_strlen(env_path));
			break ;
		}
		i++;
	}
	return (env_path);
}

static char	**ft_path_with_slash(char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		ft_free(tmp, NULL);
		i++;
	}
	return (path);
}

static char	**ft_usable_path(char **envp)
{
	char	*env_path;
	char	**path;

	env_path = ft_search_env_path(envp);
	if (!env_path)
		return (NULL);
	path = ft_split(env_path, ':');
	ft_free(env_path, NULL);
	if (!path)
		return (NULL);
	path = ft_path_with_slash(path);
	if (!path)
		return (NULL);
	return (path);
}

static char	*get_cmd_path(char *cmd, char **path)
{
	int		i;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], cmd);
		if (!cmd_path)
		{
			ft_free(NULL, path);
			ft_error(error_msg("unexpected error", "", "", 1), NULL);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		ft_free(cmd_path, NULL);
		i++;
	}
	return (NULL);
}

char	*get_cmd(char *cmd, t_pipex *data)
{
	char	**env_path;
	char	*cmd_path;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	env_path = ft_usable_path(data->envp);
	if (!env_path)
		return (NULL);
	cmd_path = get_cmd_path(cmd, env_path);
	if (!cmd_path)
		error_msg("command nor found", ": ", data->av[data->child + 2], 1);
	ft_free(NULL, env_path);
	return (cmd_path);
}
