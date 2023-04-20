/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:32:00 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/20 10:08:21 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "Error: arguments not found." << std::endl;
	else if (ac == 2)
		std::cout << "Error: insufficient arguments." <<std::endl;
	else if (ac > 3001)
		std::cout << "Error: too many arguments" << std::endl;
	else
	{
		PmergeMe arr;
		
		try
		{
			for (int i = 1; i < ac; i++)
				arr.fillArray(av[i]);
			arr.execute();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}