/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:44:40 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 13:45:18 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//=============================================================================

Dog::Dog()
{
	std::cout << "A good doggo come !" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "You can't play anymore. Good bye little boy (the dog) !" << std::endl;
}

//=============================================================================

void	Dog::makeSound() const
{
	std::cout << this->_type << ": Bark bark !" << std::endl;
}

std::string	Dog::getType() const
{
	return this->_type;
}

//=============================================================================