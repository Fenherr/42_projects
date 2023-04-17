/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:05:10 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/17 17:00:54 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Error: invalid argument. We need one and only one inverted Polish mathematical expression." << std::endl;
	else
	{
		RPN rpn;
		try
		{
			rpn.execute(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}
}