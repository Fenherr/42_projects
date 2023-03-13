/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:55:43 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/13 08:58:09 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void replace(std::string filename, std::string s1, std::string s2)
{
	std::string line;
	size_t		start = 0;
	
	if (filename.empty() || s1.empty())
		std::cout << "One of the data is empty." << std::endl;
	else
	{
		std::ifstream infile(filename.c_str());

		if (infile)
		{
			std::ofstream outfile((filename + ".replace").c_str());
			while (getline(infile, line))
			{
				while ((start = line.find(s1)) != std::string::npos)
				{
					line.erase(start, s1.size());
					line.insert(start, s2);
					start += s2.size();
				}
				outfile << line << std::endl;
			}
		}
		else
			std::cout << "The file doesn't exist." << std::endl;
		infile.close();
	}
}