/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:06:36 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/08 11:35:31 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string name;
	
	std::cout << "Create a Zombie in the stack" << std::endl;
	std::cout << "Name your zombie: " << std::flush;
	std::cin >> name;
	
	Zombie zombie1(name);
	zombie1.announce();
	
	std::cout << "Create a Zombie in the heap" << std::endl;
	std::cout << "Name your zombie: " << std::flush;
	std::cin >> name;
	
	Zombie *zombie2 = new Zombie(name);
	zombie2->announce();
	delete(zombie2);
	
	std::cout << "Calling randomChump()" << std::endl;
	randomChump("Billy");
}