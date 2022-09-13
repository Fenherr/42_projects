/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:11:43 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/13 16:07:02 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*ft_search_env_path(char **envp)
{
	char	*env_path;
	int		i;

	i = 0;
	env_path = NULL;
	while (envp[i])
	{
		env_path = ft_strnstr(envp[i], "PATH=", 5);
		if (env_path)
		{
			env_path = ft_substr(envp[i], 5, ft_strlen(env_path));
			break;
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
		free(tmp);
		i++;
	}
	return (path);
}

static char	**ft_usable_path(char **path, char **envp)
{
	char	*env_path;
	
	env_path = ft_search_env_path(envp);
	if (!env_path)
	{
		perror("Environment path error");
		exit(0);
	}
	path = ft_split(env_path, ':');
	if (!path)
	{
		perror("Path error");
		exit(0);
	}
	path = ft_path_with_slash(path);
	free(env_path);
	return (path);
}

void	test(char **envp, t_pipex *pipex)
{
	char **path;

	path = pipex->path;
	path = ft_usable_path(path, envp);
	ft_printf("%s\n", path);
}