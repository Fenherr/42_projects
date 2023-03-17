/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:18:05 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/17 11:19:01 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	billy("Billy");
	
	billy.attack("Bob");
	billy.takeDamage(20);
	billy.beRepaired(5);
}