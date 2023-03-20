/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:04:37 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 14:34:00 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//=============================================================================

Animal::Animal()
{
	std::cout << "A curious creature appeared" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(Animal const &copy)
{
	std::cout << "The curious creature duplicate itself." << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "The curious creature disappeared" << std::endl;
}

//=============================================================================

Animal & Animal::operator=(Animal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

//=============================================================================

void	Animal::makeSound() const
{
	std::cout << this->_type << ": \e[3munknown noise\e[0m" << std::endl;
}

std::string	Animal::getType() const
{
	return this->_type;
}
//=============================================================================