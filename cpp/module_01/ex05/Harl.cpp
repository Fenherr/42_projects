/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:36:20 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/10 13:28:24 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "DEBUG: This is a debug alert." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: This is a info alert." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: This is a warning alert." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: This is a error alert." << std::endl;
}

void	Harl::complain(std::string level)
{
	ptrFunc		tabFunc[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int			i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*tabFunc[i])();
}