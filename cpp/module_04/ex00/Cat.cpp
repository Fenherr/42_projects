/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:20:27 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/23 14:24:58 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//=============================================================================

Cat::Cat()
{
	std::cout << "A demon euh... a cat appeared" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "The little devil (the cat) walks away with contempt" << std::endl;
}

//=============================================================================

void	Cat::makeSound() const
{
	std::cout << this->_type << ": Nyanyajyuu nyanya do no " << std::flush;
	std::cout << "nyarabi de nyaku nyaku inyanyaku nyanyahan " << std::flush;
	std::cout << "nyanyadai nyan nyaku nyarabete nyaganyagame !" << std::endl;
}

std::string	Cat::getType() const
{
	return this->_type;
}

//=============================================================================

Cat & Cat::operator=(Cat const & rhs)
{
	this->_type = rhs._type;
	return *this;
}

//=============================================================================