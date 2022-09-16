/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:56:43 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/09/16 11:04:47 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	
	pipex = ft_init(ac, av, envp);
	ft_printf("%s\n", get_cmd("ls", &pipex));
	//Ne pas oublier de free get_cmd
	
	return (0);
}