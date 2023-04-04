/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:05:08 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/04 15:05:15 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int array1[] = {1, 2, 3, 4, 5};
	
	std::cout << "Test int array: " << std::endl;
	iter(array1, 5, &print);
	
	std::cout << std::endl;
	
	double array2[] = {1.5, 2.5, 3.5, 4.5, 5.5};
	
	std::cout << "Test double array: " << std::endl;
	iter(array2, 5, &print);
	
	std::cout << std::endl;
	
	float array3[] = {1.5f, 2.5f, 3.5f, 4.5f, 5.5f};
	
	std::cout << "Test float array: " << std::endl;
	iter(array3, 5, &print);
	
	std::cout << std::endl;
	
	char array4[] = {'a', 'b', 'c', 'd', 'e'};
	
	std::cout << "Test char array: " << std::endl;
	iter(array4, 5, &print);
	
	std::cout << std::endl;
}