/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:04:29 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 14:33:40 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap(std::string name);
		~DiamondTrap();

		void	whoAmI();
		using	ScavTrap::attack;
};

#endif