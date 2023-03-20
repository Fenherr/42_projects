/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:23:26 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 13:48:17 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//=============================================================================

WrongCat::WrongCat()
{
	std::cout << "What is it ? A cat ? Here ?" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "That's not a cat ! Where is it ?" << std::endl;
}

//=============================================================================

void	WrongCat::makeSound() const
{
	std::cout << this->_type << ": Nyanyajyuu nyanya do no " << std::flush;
	std::cout << "nyarabi de nyaku nyaku inyanyaku nyanyahan " << std::flush;
	std::cout << "nyanyadai nyan nyaku nyarabete nyaganyagame !" << std::endl;
}

std::string	WrongCat::getType() const
{
	return this->_type;
}

//=============================================================================