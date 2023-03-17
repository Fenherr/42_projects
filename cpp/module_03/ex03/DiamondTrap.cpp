/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:51:53 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 14:47:21 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;

	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";

	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDmg = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor DiamonTrap called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: " << this->_name << ", and the ClapTrap name is: " << ClapTrap::_name << std::endl;
}