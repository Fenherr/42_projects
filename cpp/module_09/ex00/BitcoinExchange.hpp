/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:48:29 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/14 13:19:55 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>
#include <map>

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
			virtual const char* what() const throw()
			{
				return "Error: could not open file.";
			}
	};
};

#endif