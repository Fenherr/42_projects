/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:04:46 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 11:16:11 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(Animal const &copy);
		virtual ~Animal();

		Animal & operator=(Animal const & rhs);

		virtual void	makeSound() const;
		std::string	getType() const;
};

#endif