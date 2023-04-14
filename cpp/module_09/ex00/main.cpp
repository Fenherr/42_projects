/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:16:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/14 09:43:19 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
		std::cout << "Error: could not open file." << std::endl;
	else if (ac > 2)
		std::cout << "Error: too much arguments." << std::endl;
	else
		BitcoinExchange test(av[1]);
}