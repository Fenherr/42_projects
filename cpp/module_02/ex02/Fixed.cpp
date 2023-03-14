/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/14 15:43:18 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//=============================================================================

//Constructeur par defaut
Fixed::Fixed()
{
	this->_fixedNumber = 0;
}

//Copie du constructeur
Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

//Surcharges du constructeur
Fixed::Fixed(int const int_num)
{
	this->_fixedNumber = int_num << _bits;
}

Fixed::Fixed(float const float_num)
{
	this->_fixedNumber = roundf(float_num * (1 << _bits));
}

//Destructeur
Fixed::~Fixed()
{
}

//=============================================================================

//Surcharge sur l'opérateur '='
Fixed&	Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fixedNumber = rhs.getRawBits();
	return *this;
}

//Surcharge sur l'opérateur '<<'
std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

//=============================================================================

//Fonctions membres
void	Fixed::setRawBits(int const raw)
{
	this->_fixedNumber = raw;
}

int		Fixed::getRawBits(void) const
{
	return this->_fixedNumber;
}

float	Fixed::toFloat(void) const
{
	return this->_fixedNumber * ft_pow(2, -this->_bits);
}

int		Fixed::toInt(void) const
{
	return this->_fixedNumber * ft_pow(2, -this->_bits);
}

//=============================================================================

//Fonction utile
float	ft_pow(float base, int exp)
{
	float	res;
	
	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	res = base;
	while (--exp)
		res *= base;
	return (res);
}

//=============================================================================