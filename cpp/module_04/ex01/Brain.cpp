/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:01:19 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/22 13:25:14 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//=============================================================================

Brain::Brain()
{
	std::cout << "Brain: Hi ! I'm here !" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain: Say hello to my little copy !" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain: Goodbye !" << std::endl;
}

//=============================================================================

Brain & Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	return *this;
}

//=============================================================================

std::string Brain::getIdea(int index) const
{
	return this->_ideas[index];
}

void Brain::setIdea(int index, std::string idea)
{
	this->_ideas[index] = idea;
}

//=============================================================================