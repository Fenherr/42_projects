/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:04:24 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/14 14:22:10 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedNumber;
		static int const	_bits = 8;

	public:
		Fixed();
		Fixed(Fixed const & src);
		Fixed(int const int_num);
		Fixed(float const float_num);
		~Fixed();

		Fixed &	operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

float	ft_pow(float base, int exp);

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif