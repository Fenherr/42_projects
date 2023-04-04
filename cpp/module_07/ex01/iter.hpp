/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:05:55 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/04 15:08:16 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, size_t arrSize, void (*f)(T &))
{
	for (size_t i = 0; i < arrSize; i++)
		f(array[i]);
}

template<typename T>
void print(T &something)
{
	std::cout << something << std::endl;
}

#endif