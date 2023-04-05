/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:02:12 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/05 14:12:46 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T & a, T & b)
{
	T tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min(T const & a, T const & b)
{
	if (a >= b)
		return b;
	return a;
}

template<typename T>
T max(T const & a, T const & b)
{
	if (a > b)
		return a;
	return b;
}

#endif