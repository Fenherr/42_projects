/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:51:13 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/28 13:50:24 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(std::string const str)
{
	if (str.size() == 1 && (std::isprint(str[0]) || !std::isdigit(str[0])))
		return true;
	return false;
}

void ScalarConverter::convert(std::string const convertStr)
{
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;
	
	if (isChar(convertStr) == true)
	{
		std::cout << "char: '" << convertStr[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(convertStr[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(convertStr[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(convertStr[0]) << ".0" << std::endl;
	}
	
	toInt = std::atoi(convertStr.c_str());
}
