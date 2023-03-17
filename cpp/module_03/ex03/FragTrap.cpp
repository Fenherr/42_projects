/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:33:28 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 12:41:58 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDmg = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " has no more energy points" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDmg << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	std::cout << this->_name << " has " << this->_energyPoints << " energy points." << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " says: High fives Guys ?!" << std::endl;
}