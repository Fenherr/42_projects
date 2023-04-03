/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:51:13 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/03 10:02:28 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string tmp;
static std::string pseudoLiterals[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};

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

static bool isFloat(std::string const str)
{
	if (str.size() > 1 && str[str.size() - 1] == 'f')
		return true;
	return false;
}

static bool isDouble(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[str.size() - 1] != 'f' && str[i] == '.')
			return true;
	}
	return false;
}

static void printChar(std::string str)
{
	if (std::isprint(str[0]))
		std::cout << "char: '" << str[0] << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

static void printInt(int nb, std::string str)
{
	std::string toChar = "";
	
	if (str[0] == '-' || nb > 127)
		toChar = "impossible";
	else if (!std::isprint(nb))
		toChar = "Non displayable";
	else
	{
		toChar = "'";
		toChar += static_cast<char>(nb);
		toChar += "'";
	}
	
	std::cout << "char: " << toChar << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
}

static void printFloat(float nb, std::string tmp, std::string str)
{
	std::string toChar = "";
	int prec = tmp.size() - 2;
	
	if (str[0] == '-' || nb > 127)
		toChar = "impossible";
	else if (!std::isprint(nb))
		toChar = "Non displayable";
	else
	{
		toChar = "'";
		toChar += static_cast<char>(nb);
		toChar += "'";
	}
	std::cout << "char: " << toChar << std::endl;
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(prec) << nb << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << std::endl;
}

static void printDouble(double nb, std::string tmp, std::string str)
{
	std::string toChar = "";
	int prec = tmp.size() - 1;
	
	if (str[0] == '-' || nb > 127)
		toChar = "impossible";
	else if (!std::isprint(nb))
		toChar = "Non displayable";
	else
	{
		toChar = "'";
		toChar += static_cast<char>(nb);
		toChar += "'";
	}
	std::cout << "char: " << toChar << std::endl;
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(prec - 1) << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(prec) << nb << std::endl;
}

void ScalarConverter::convert(std::string const convertStr)
{
	std::string toChar = convertStr;
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;
	
	//Pseudo literals management
	for (int i = 0; i < 6; i++)
	{
		if (convertStr == pseudoLiterals[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << static_cast<float>(std::strtof(pseudoLiterals[i].c_str(), NULL)) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(std::strtod(pseudoLiterals[i].c_str(), NULL)) << std::endl;
			return ;
		}
	}
	
	//Overflow management
	long intCheck = std::strtol(convertStr.c_str(), NULL, 10);
	if (intCheck > INT_MAX || intCheck < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	
	//Convert to char
	if (isChar(toChar))
	{
		printChar(toChar);
		return ;
	}
	
	//Convert to int
	toInt = std::atoi(convertStr.c_str());
	
	if (isInt(convertStr))
	{
		printInt(toInt, convertStr);
		return ;
	}
	
	//Convert to float
	if (isFloat(convertStr))
	{
		char* pEnd;
		toFloat = std::strtol(toChar.c_str(), &pEnd, 10);
		tmp = pEnd;
		toFloat = std::strtof(toChar.c_str(), &pEnd);
		printFloat(toFloat, tmp, convertStr);
		return ;
	}
	
	//Convert to double
	if (isDouble(convertStr))
	{
		char* pEnd;
		toDouble = std::strtol(toChar.c_str(), &pEnd, 10);
		tmp = pEnd;
		toDouble = std::strtod(toChar.c_str(), &pEnd);
		printDouble(toDouble, tmp, convertStr);
		return ;
	}
}
