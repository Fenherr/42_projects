/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:48:29 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/26 17:30:36 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <map>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchangeRates;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);

		BitcoinExchange & operator=(const BitcoinExchange & rhs);

		void mapParsing();
		void execute(std::string filename);

	public:
		BitcoinExchange(std::string filename);
		~BitcoinExchange();

	class FileException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class EmptyDatabaseException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class ErrorDatabaseException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
