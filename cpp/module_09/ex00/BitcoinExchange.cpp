/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:08:18 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/26 17:30:43 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char* BitcoinExchange::FileException::what() const throw()
{
	return "Error: could not open file.";
}

const char* BitcoinExchange::EmptyDatabaseException::what() const throw()
{
	return "Error: empty data.";
}

const char* BitcoinExchange::ErrorDatabaseException::what() const throw()
{
	return "Error: problem in the data.";
}

/*===============================function=====================================*/
static bool isLeap(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}

static bool has31Days(int month)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return false;
	return true;
}

static bool checkDate(const char* date, const char* format)
{
	struct tm timeStruct;
	int year;
	int month;
	int day;

	std::memset(&timeStruct, 0, sizeof(timeStruct));

	if (strptime(date, format, &timeStruct) == NULL)
		return false;

	std::istringstream iss(date);
	char dash1;
	char dash2;

	if (iss >> year >> dash1 >> month >> dash2 >> day && dash1 == '-' && dash2 == '-')
	{
		if (month < 1 || month > 12)
			return false;
		else if (day < 1 || day > 31)
			return false;
		else if (!has31Days(month) && day == 31)
			return false;
		else if (month == 2 && isLeap(year) && day > 29)
			return false;
		else if (month == 2 && day > 28 && !isLeap(year))
			return false;
		else
			return true;
	}
	else
		return true;
}

/*===========================Member functions=================================*/

void BitcoinExchange::mapParsing()
{
	std::string date;
	std::string line;
	std::string mapKey;
	std::string mapValueStr;
	float mapValue;
	std::fstream data("data.csv");

	if (!data)
		throw FileException();

	if (getline(data, line) && line == "date,exchange_rate")
	{
		if (!getline(data, line))
			throw EmptyDatabaseException();
	}

	if (!getline(data, line))
			throw EmptyDatabaseException();

	while (getline(data, line))
	{
		size_t pos = line.find_last_of(",");
		date = line.substr(0, pos);

		if (pos > 10)
			throw ErrorDatabaseException();
		else if (!checkDate(date.c_str(), "%Y-%m-%d"))
			throw ErrorDatabaseException();
		else if (pos != std::string::npos)
		{
			mapKey = line.substr(0, pos);
			mapValueStr = line.substr(pos + 1);
			mapValue = static_cast<float>(std::strtof(mapValueStr.c_str(), NULL));
			_exchangeRates.insert(std::make_pair(mapKey, mapValue));
		}
	}
}

static bool checkStr(std::string str)
{
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ' && str[i] != '-' && str[i] != '|' && !std::isdigit(str[i]) && str[i] != '.')
			return false;
	}
	return true;
}

void BitcoinExchange::execute(std::string filename)
{
	std::string line;
	std::string date;
	std::string valueStr;
	float value;
	std::fstream file(filename.c_str());

	if (!file)
		throw FileException();

	while (getline(file, line))
	{
		if (line == "date | value")
			getline(file, line);

		size_t pos = line.find_last_of("|");

		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			valueStr = line.substr(pos + 1);
			value = static_cast<float>(std::strtof(valueStr.c_str(), NULL));

			if (pos > 11 || !checkStr(line))
				std::cout << "Error: bad input => " << line << std::endl;
			else if (!checkDate(date.c_str(), "%Y-%m-%d"))
				std::cout << "Error: bad input => " << date << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else if (static_cast<int>(value) < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else
			{
				std::map<std::string, float>::iterator it = _exchangeRates.find(date);
				if (it == _exchangeRates.end())
				{
					std::map<std::string, float>::iterator lower = _exchangeRates.lower_bound(date);
					if (lower == _exchangeRates.begin() && date < _exchangeRates.begin()->first)
					{
						std::cout << "Error: bad input => " << line << std::endl;
						continue;
					}
					else
						it = --lower;
				}
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			}
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
}

/*=============================Constructor====================================*/

BitcoinExchange::BitcoinExchange(std::string filename)
{
	try
	{
		mapParsing();
		execute(filename);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

/*==============================Destructor====================================*/

BitcoinExchange::~BitcoinExchange()
{
}

/*============================================================================*/
