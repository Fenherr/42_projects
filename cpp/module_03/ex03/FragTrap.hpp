/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:33:20 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 13:01:24 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();

		void	attack(const std::string& target);
		void	highFivesGuys();
};

#endif