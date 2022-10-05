/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:36:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/10/05 13:41:18 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// void	test(void)
// {
// 	int	fd;
// 	int	count_line;
// 	char	*line;
	
// 	count_line = 0;
// 	fd = open("./maps/map1.ber", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		count_line++;
// 		ft_printf("%d caractères dans la ligne : ", ft_strlen(line));
// 		ft_printf("%s", line);
// 	}
// 	ft_printf("Nombre de lignes : %d\n", count_line);
// 	close(fd);
// }

void	ft_init(t_data *data, char *map_name)
{
	data->exit = 0;
	data->item = 0;
	data->player = 0;
	data->map_width = 0;
	data->map_length = 0;
	data->map_name = ft_strjoin("./maps/", map_name);
	//data->map = malloc(sizeof());
}