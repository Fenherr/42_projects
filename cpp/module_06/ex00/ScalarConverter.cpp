/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:51:13 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/04 11:35:05 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*==================================Variables=================================*/

std::string pseudoLiterals[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
std::string toChar = "";
int toInt = 0;
float toFloat = 0;
double toDouble = 0;
int type = 0;
std::string pEnd;

/*====================================Types===================================*/

static bool isChar(std::string str)
{
	if (str.size() == 1 && !std::isdigit(str[0]))
		return true;
	return false;
}

static bool isInt(std::string str)
{
	long checkInt = std::strtol(str.c_str(), NULL, 10);
	
	int i = 0;
	
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; str[i]; i++)
	{
		if (checkInt > INT_MAX || checkInt < INT_MIN)
			return false;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

static bool isFloat(std::string str)
{
	int i = 0;
	int size = str.size();
	int countF = 0;
	int countDot = 0;
	
	if (str[i] == '-' || str[i] == '+')
		i++;
	
	for (int j = 0; str[j]; j++)
	{
		if (str[j] == 'f')
			countF++;
		if (str[j] == '.')
			countDot++;
	}
	
	if (countF > 1 || (countDot > 1 || (countDot < 1 && countF == 1)))
		return false;
	
	for (; str[i]; i++)
	{
		if (str[str.size() - 1] != 'f')
			break;
		if (str[i] != '.' && !std::isdigit(str[i]) && str[i] != 'f')
			break ;
	}
	
	if (i == size)
		return true;
	return false;
}

static bool isDouble(std::string str)
{
	int i = 0;
	int size = str.size();
	int countDot = 0;
	
	if (str[i] == '-' || str[i] == '+')
		i++;
	
	for (int j = 0; str[j]; j++)
	{
		if (str[j] == '.')
			countDot++;
	}
	
	if (countDot > 1)
		return false;
	
	for (; str[i]; i++)
	{
		if (str[i] != '.' && !std::isdigit(str[i]))
			break ;
	}
	
	if (i == size)
		return true;
	return false;
}

static int isLiteral(std::string str)
{
	for (int i = 0; i < 6; i++)
	{
		if (str == pseudoLiterals[i])
			return i;
	}
	return -1;
}

static bool isString(std::string str)
{
	long checkInt = std::strtol(str.c_str(), NULL, 10);
	
	for (int i = 0; str[i]; i++)
	{
		if (str.size() > 1 && !std::isdigit(str[i]) && str[str.size() - 1] != 'f' && str[i] != '.')
			return true;
		if (checkInt > INT_MAX)
			return true;
		if (str[i] == '.' && str[i + 1] == '.')
			return true;
	}
	return false;
}

static void searchType(std::string str)
{
	if (isChar(str))
		type = CHAR;
	else if (isInt(str))
		type = INT;
	else if (isFloat(str))
		type = FLOAT;
	else if (isDouble(str))
		type = DOUBLE;
	else if (isLiteral(str) != -1)
		type = LITERAL;
	else if (isString(str))
		type = STRING;
}

/*===================================Prints===================================*/

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

static void printInt(std::string str)
{
	toInt = std::atoi(str.c_str());
	
	if (str[0] == '-' || toInt > 127)
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
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(toInt) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(toInt) << std::endl;
}

static void printFloat(std::string str)
{
	char* tmp;
	int prec;
	long checkInt;
	
	toFloat = std::strtol(str.c_str(), &tmp, 10);
	checkInt = toFloat;
	pEnd = tmp;
	toFloat = std::strtof(str.c_str(), &tmp);
	prec = pEnd.size() - 2;
	
	if (str[0] == '-' || toFloat > 127)
		toChar = "impossible";
	else if (!std::isprint(toFloat))
		toChar = "Non displayable";
	else
	{
		toChar = "'";
		toChar += static_cast<char>(toFloat);
		toChar += "'";
	}
	
	std::cout << "char: " << toChar << std::endl;
	if (checkInt > INT_MAX || checkInt < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(toFloat) << std::endl;
	if (str[str.size() - 2] == '.' && str[str.size() - 1] == 'f')
	{
		std::cout << "float: " << std::fixed << std::setprecision(prec) << toFloat << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toFloat) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(prec) << toFloat << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(toFloat) << std::endl;
	}
}

static void printDouble(std::string str)
{
	char* tmp;
	int prec;
	long checkInt;
	
	toDouble = std::strtol(str.c_str(), &tmp, 10);
	checkInt = toDouble;
	pEnd = tmp;
	toDouble = std::strtod(str.c_str(), &tmp);
	prec = pEnd.size() - 1;
	
	if (str[0] == '-' || toDouble > 127)
		toChar = "impossible";
	else if (!std::isprint(toDouble))
		toChar = "Non displayable";
	else
	{
		toChar = "'";
		toChar += static_cast<char>(toDouble);
		toChar += "'";
	}
	
	std::cout << "char: " << toChar << std::endl;
	if (checkInt > INT_MAX || checkInt < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(toDouble) << std::endl;
	if (str[str.size() - 1] == '.')
	{
		std::cout << "float: " << std::fixed << std::setprecision(prec) << static_cast<float>(toDouble) << ".0f" << std::endl;
		std::cout << "double: " << toDouble << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(prec) << static_cast<float>(toDouble) << "f" << std::endl;
		std::cout << "double: " << toDouble << std::endl;
	}
}

static void printLiteral(std::string str)
{
	int index = isLiteral(str);
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(std::strtof(pseudoLiterals[index].c_str(), NULL)) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(std::strtod(pseudoLiterals[index].c_str(), NULL)) << std::endl;
}

/*===================================Method===================================*/

void ScalarConverter::convert(std::string const convertStr)
{
	searchType(convertStr);

	switch (type)
	{
	case CHAR:
		printChar(convertStr);
		break;
	case INT:
		printInt(convertStr);
		break;
	case FLOAT:
		printFloat(convertStr);
		break;
	case DOUBLE:
		printDouble(convertStr);
		break;
	case LITERAL:
		printLiteral(convertStr);
		break;
	default:
		std::cout << "Error: Argument not accepted." << std::endl;
		break;
	}
}

/*============================================================================*/