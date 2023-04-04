/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:37:12 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/04 11:38:16 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data* ptr = new Data;
	Data* ptr2;
	uintptr_t raw = Serializer::serialize(ptr);
	
	ptr->data = 42;
	
	std::cout << "Value data member: " << ptr->data << std::endl;
	std::cout << std::endl;
	
	std::cout << "ptr address: " << ptr << std::endl;
	std::cout << std::endl;
	
	ptr2 = Serializer::deserialize(raw);
	std::cout << "Value data member: " << ptr2->data << std::endl;
	std::cout << std::endl;
	
	std::cout << "ptr2 address deserialize: " << ptr2 << std::endl;
	
	delete ptr;
}