/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:18:05 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 12:44:41 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap	billy("Billy");
	ScavTrap	bob("Bob");
	FragTrap	richard("Richard");

	std::cout << std::endl;

	billy.attack("Bob");
	bob.attack("Billy");
	billy.takeDamage(20);
	billy.beRepaired(50);
	bob.guardGate();
	richard.attack("Bob");
	std::cout << "Thanks to Bob's skill, the damage he takes is reduced by 5" << std::endl;
	bob.takeDamage(25);
	bob.beRepaired(5);
	richard.highFivesGuys();
	bob.attack("Richard");
	richard.takeDamage(20);
	richard.beRepaired(10);

	std::cout << std::endl;
}