/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:20:39 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 14:11:57 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//=============================================================================

WrongAnimal::WrongAnimal()
{
	std::cout << "A factice creature appeared" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "The factice creature disappeared." << std::endl;
}

//=============================================================================

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

//=============================================================================

void	WrongAnimal::makeSound() const
{
	std::cout << this->_type << ": \e[3munknown noise\e[0m" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}
//=============================================================================