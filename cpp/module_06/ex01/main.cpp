/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:37:12 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/30 12:27:57 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data* ptr;
	uintptr_t raw;
	
	ptr->data = 0;
	
	std::cout << "Value data member: " << ptr->data << std::endl;
	std::cout << std::endl;
	
	std::cout << "ptr address: " << ptr << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << "ptr address deserialize: " << ptr << std::endl;
}