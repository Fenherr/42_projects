/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:54:49 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/09 14:15:37 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av)
{
	if (ac == 4)
		replace(av[1], av[2], av[3]);
	else
		std::cout << "Usage: ./sed filename s1 s2" << std::endl;
}