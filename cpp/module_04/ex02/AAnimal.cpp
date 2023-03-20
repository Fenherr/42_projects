/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:04:37 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 16:22:08 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//=============================================================================

AAnimal::AAnimal()
{
	std::cout << "A curious creature appeared" << std::endl;
	this->_type = "Animal";
}

AAnimal::AAnimal(AAnimal const &copy)
{
	std::cout << "The curious creature duplicate itself." << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "The curious creature disappeared" << std::endl;
}

//=============================================================================

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

//=============================================================================

void	AAnimal::makeSound() const
{
	std::cout << this->_type << ": \e[3munknown noise\e[0m" << std::endl;
}

std::string	AAnimal::getType() const
{
	return this->_type;
}
//=============================================================================