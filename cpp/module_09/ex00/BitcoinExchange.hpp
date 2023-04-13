/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:48:29 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/13 13:36:41 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchangeRates;
		
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		
		BitcoinExchange & operator=(const BitcoinExchange & rhs);
	
		void execute(std::string filename);
		void mapParsing(std::string dataName);
		
	public:
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
};

#endif