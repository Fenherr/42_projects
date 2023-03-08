/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:59:02 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/08 13:09:35 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;
	
	std::cout << "String adress: " << &str << std::endl;
	std::cout << "Pointer adress: " << stringPTR << std::endl;
	std::cout << "Reference adress: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "String value: " << str << std::endl;
	std::cout << "Pointer value: " << *stringPTR << std::endl;
	std::cout << "Reference value: " << stringREF << std::endl;
}