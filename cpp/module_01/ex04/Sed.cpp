/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:55:43 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/09 15:53:40 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void replace(std::string filename, std::string s1, std::string s2)
{
	std::string line;
	
	std::ifstream infile(filename.c_str());

	(void)s2;
	if (infile)
	{
		while (getline(infile, line))
		{
			std::cout << line.find(s1) << std::endl;
		}
	}
	else
		std::cout << "The file doesn't exist." << std::endl;
	infile.close();
}