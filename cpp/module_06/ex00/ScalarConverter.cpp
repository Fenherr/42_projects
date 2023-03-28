/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:51:13 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/28 13:55:41 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(std::string const str)
{
	if (str.size() == 1 && (std::isprint(str[0]) || !std::isdigit(str[0])))
		return true;
	return false;
}

static bool isFloat(std::string const str)
{
	if (str[str.size() - 1] == 'f')
		return true;
	return false;
}

void ScalarConverter::convert(std::string const convertStr)
{
	std::string pseudoLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	
	std::string toChar = "";
	float toFloat = 0;
	double toDouble = 0;
	int toInt = std::atoi(convertStr.c_str());
	
	if (isChar(convertStr) == true)
	{
		toChar = convertStr[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(convertStr[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(convertStr[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(convertStr[0]) << ".0" << std::endl;
		return ;
	}
	
	if (isFloat(convertStr) == true)
	{
		toFloat = std::strtof(convertStr.c_str(), NULL);
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::strtod(convertStr.c_str(), NULL);
		toFloat = static_cast<float>(toDouble);
	}
	
	for (int i = 0; i < 6; i++)
	{
		if (convertStr == pseudoLiterals[i])
		{
			toChar = "impossible";
			break ;
		}
	}
	
	if (toChar == "" && std::isprint(toInt))
		toChar = static_cast<char>(toInt);
	else if (toChar == "")
		toChar = "Non displayable";
	
	std::cout << "char: '" << toChar << "'" << std::endl;
	if (toChar == "impossible")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << toInt << std::endl;
	
	if (toChar == "impossible" && toFloat == 0)
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		if (toChar != "impossible" && toFloat - static_cast<int>(toFloat) == 0)
		{
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}
