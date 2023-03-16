/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/15 11:13:38 by ngrenoux         ###   ########.fr       */
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

//Surcharge de l'opérateur '='
Fixed&	Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fixedNumber = rhs.getRawBits();
	return *this;
}

//Surcharge de l'opérateur '<<'
std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

//Surcharge des opérateurs de comparaison
bool	Fixed::operator>(Fixed const & rhs) const
{
	return this->toFloat() > rhs.toFloat();
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return this->toFloat() < rhs.toFloat();
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return this->toFloat() == rhs.toFloat();
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return this->toFloat() != rhs.toFloat();
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return this->toFloat() >= rhs.toFloat();
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return this->toFloat() <= rhs.toFloat();
}

//Surcharge des opérateurs arithmétique
Fixed	Fixed::operator+(Fixed const & rhs)
{
	Fixed	res = (this->toFloat() + rhs.toFloat());
	return res;
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	Fixed	res = (this->toFloat() - rhs.toFloat());
	return res;
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	Fixed	res = (this->toFloat() * rhs.toFloat());
	return res;
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	Fixed	res = (this->toFloat() / rhs.toFloat());
	return res;
}

//Surcharge des opérateurs d'incrémentation et de décrémentation
Fixed & Fixed::operator++()
{
	++this->_fixedNumber;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	value = *this;
	++this->_fixedNumber;
	return value;
}

Fixed & Fixed::operator--()
{
	--this->_fixedNumber;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	value = *this;
	--this->_fixedNumber;
	return value;
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

Fixed	Fixed::min(Fixed & nb1, Fixed & nb2)
{
	if (nb1 < nb2)
		return nb1;
	return nb2;
}

Fixed	Fixed::min(Fixed const & nb1, Fixed const & nb2)
{
	if (nb1 < nb2)
		return nb1;
	return nb2;
}

Fixed	Fixed::max(Fixed & nb1, Fixed & nb2)
{
	if (nb1 > nb2)
		return nb1;
	return nb2;
}

Fixed	Fixed::max(Fixed const & nb1, Fixed const & nb2)
{
	if (nb1 > nb2)
		return nb1;
	return nb2;
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