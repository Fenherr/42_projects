/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:38:45 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/03 11:20:49 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>
#include <iomanip>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define LITERAL 5
#define STRING 6

class ScalarConverter
{
	public:
		static void convert(std::string const convertStr);
};

#endif