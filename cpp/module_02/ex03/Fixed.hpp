/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:04:24 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/15 10:53:55 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		//Attributs membres
		int					_fixedNumber;
		static int const	_bits = 8;

	public:
		//Constructeur
		Fixed();

		//Copie du constructeur
		Fixed(Fixed const & src);
		
		//Constructeurs surchargés
		Fixed(int const int_num);
		Fixed(float const float_num);

		//Destructeur
		~Fixed();

		//Surcharge de l'opérateur '='
		Fixed &	operator=(Fixed const & rhs);

		//Surcharge des opérateurs de comparaison
		bool	operator>(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;

		//Surcharge des opérateurs arithmétique
		Fixed	operator+(Fixed const & rhs);
		Fixed	operator-(Fixed const & rhs);
		Fixed	operator*(Fixed const & rhs);
		Fixed	operator/(Fixed const & rhs);

		//Surcharge des opérateurs d'incrémentation et de décrémentation
		Fixed &	operator++();		//Prefixe
		Fixed	operator++(int);	//Postfix
		Fixed &	operator--();		//Prefixe
		Fixed	operator--(int);	//Postfix

		//Fonctions membres
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed	min(Fixed & nb1, Fixed & nb2);
		static Fixed	min(Fixed const & nb1, Fixed const & nb2);
		static Fixed	max(Fixed & nb1, Fixed & nb2);
		static Fixed	max(Fixed const & nb1, Fixed const & nb2);
};

float	ft_pow(float base, int exp);

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif