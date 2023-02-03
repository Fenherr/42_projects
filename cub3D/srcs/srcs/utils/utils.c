/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:57:06 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/03 15:01:10 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

char	*ft_clean_dup(char *str)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '\n')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_realloc_tab_char(char **tab, char *str)
{
	int		i;
	char	**new_tab;

	i = 0;
	while (tab && tab[i] != NULL)
		i++;
	new_tab = malloc(sizeof(char *) * (i + 2));
	if (!new_tab)
		return (NULL);
	new_tab[i + 1] = NULL;
	i = 0;
	while (tab && tab[i] != NULL)
	{
		new_tab[i] = tab[i];
		i++;
	}
	if (tab)
		free(tab);
	new_tab[i] = str;
	return (new_tab);
}
