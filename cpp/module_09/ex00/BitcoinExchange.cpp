/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:08:18 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/17 14:30:28 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*===============================function=====================================*/

static bool checkDate(const char* date, const char* format)
{
	struct tm timeStruct;
	
	std::memset(&timeStruct, 0, sizeof(timeStruct));
	
	if (strptime(date, format, &timeStruct) == NULL)
		return false;
	
	const int minYear = 2009;
	int year = timeStruct.tm_year + 1900;
	return (year >= minYear);
}

/*===========================Member functions=================================*/

void BitcoinExchange::mapParsing()
{
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
		size_t pos = line.find(",");
		if (pos != std::string::npos)
		{
			mapKey = line.substr(0, pos);
			mapValueStr = line.substr(pos + 1);
			mapValue = static_cast<float>(std::strtof(mapValueStr.c_str(), NULL));
			_exchangeRates.insert(std::make_pair(mapKey, mapValue));
		}
	}
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
	
	getline(file, line);
	while (getline(file, line))
	{
		size_t pos = line.find("|");

		if (pos > 12)
		{
			date = line.substr(0, std::string::npos);
			std::cout << "Error: bad input => " << date << std::endl;
		}
		
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			valueStr = line.substr(pos + 1);
			value = static_cast<float>(std::strtof(valueStr.c_str(), NULL));
	
			if (!checkDate(date.c_str(), "%Y-%m-%d"))
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
					if (lower == _exchangeRates.begin())
					{
						std::cout << date << " => " << value << " = " << value * lower->second << std::endl;
						continue;
					}
					else
						it = --lower;
				}
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			}
		}
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