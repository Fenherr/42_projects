/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:28:18 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 12:45:57 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDmg(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor ClapTrap called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no more energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << std::endl;
	_energyPoints -= 1;
	std::cout << _name << " has " << _energyPoints << " energy points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " took " << amount << " damage points" << std::endl;
	_hitPoints -= amount;
	std::cout << _name << " has " << _hitPoints << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no more energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " repairs himself by " << amount << " points." << std::endl;
	_energyPoints -= 1;
	_hitPoints += amount;
	std::cout << _name << " has " << _energyPoints << " energy points and " << _hitPoints << " hit points." << std::endl;
}