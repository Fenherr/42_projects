/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:10:54 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 11:14:49 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDmg = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no more energy points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDmg << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	std::cout << this->_name << " has " << this->_energyPoints << " energy points." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " enter in Gate keeper mode !" << std::endl;
}