/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:21:23 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/06 14:46:02 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
void easyfind(T & ref, int occur)
{
	if (std::find(ref.begin(), ref.end(), occur) != ref.end())
		std::cout << "Occurrence found !" << std::endl;
	else
		std::cout << "Occurence not found..." << std::endl;
}

#endif
