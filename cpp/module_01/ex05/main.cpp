/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:36:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/10 13:40:56 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl		harl;
	std::string	str;

	std::cout << "Select one level:" << std::endl;
	std::cout << "DEBUG - INFO - WARNING - ERROR - ALL" << std::endl;
	std::cout << "If you want quit, write exit." << std::endl;

	while (str.compare("exit"))
	{
		std::cout << "> " << std::flush;
		std::cin >> str;
		if (str.compare("ALL") == 0)
		{
			std::cout << "Harl Debug" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
			std::cout << "Harl Info" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
			std::cout << "Harl Warning" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
			std::cout << "Harl Error" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
		}
		else
			harl.complain(str);
	}
}