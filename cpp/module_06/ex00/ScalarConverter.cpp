/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:51:13 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/29 16:56:47 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(std::string const str)
{
	if (str.size() == 1 && !std::isdigit(str[0]))
		return true;
	return false;
}

static bool isInt(std::string const str)
{
	int i = 0;
	
	if (str[0] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (str[str.size() - 1] == 'f' || str[i] == '.')
			return false;
		else if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void ScalarConverter::convert(std::string const convertStr)
{
	std::string toChar = convertStr;
	int toInt = 0;
	
	//Convert to char
	if (isChar(toChar))
	{
		if (std::isprint(toChar[0]))
			std::cout << "char: '" << toChar[0] << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return ;
	}
	
	//Overflow management
	long intCheck = std::strtol(convertStr.c_str(), NULL, 10);
	
	if (intCheck > INT_MAX || intCheck < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible"<< std::endl;
		std::cout << "float: " << static_cast<float>(intCheck) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(intCheck) << ".0" << std::endl;
		return ;
	}
	
	//Convert to int
	toInt = std::atoi(convertStr.c_str());
	
	if (isInt(convertStr))
	{
		if (convertStr[0] == '-' || toInt > 127)
			toChar = "impossible";
		else if (!std::isprint(toInt))
			toChar = "Non displayable";
		else
		{
			toChar = "'";
			toChar += static_cast<char>(toInt);
			toChar += "'";
		}
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << toInt << std::endl;
		std::cout << "float: " << static_cast<float>(toInt) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toInt) << ".0" << std::endl;
		return ;
	}
}
