/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:37:34 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/15 13:11:17 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//=============================================================================

//Constructeurs
Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const n1, float const n2) : _x(n1), _y(n2)
{
}

//Constructeur de copie
Point::Point(Point const &copy) : _x(copy._x), _y(copy._y)
{
}

//Destructeur
Point::~Point()
{
}

//=============================================================================

//Getters
Fixed	Point::getX() const
{
	return this->_x;
}

Fixed	Point::getY() const
{
	return this->_y;
}

//=============================================================================

//Surcharge opérateur
Point & Point::operator=(Point const & rhs)
{
	if (this != &rhs)
	{
		(Fixed) this->_x = rhs.getX();
		(Fixed) this->_y = rhs.getY();
	}
	return *this;
}

//=============================================================================