/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:41:27 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/06 14:47:04 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>

#include "easyfind.hpp"

int main()
{
	std::list<int> test1;
	std::vector<int> test2;
	
	test1.push_back(0);
	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);
	test1.push_back(4);
	
	test2.push_back(42);
	test2.push_back(6);
	test2.push_back(27);
	test2.push_back(154);
	test2.push_back(69);
	
	std::cout << "Test with list container:" << std::endl;
	easyfind(test1, 3);
	easyfind(test1, 5);
	
	std::cout << std::endl;
	
	std::cout << "Test with vector container:" << std::endl;
	easyfind(test2, 3);
	easyfind(test2, 42);
}