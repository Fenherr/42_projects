/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:04:46 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 16:21:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(AAnimal const &copy);
		virtual ~AAnimal();

		AAnimal & operator=(AAnimal const & rhs);

		virtual void	makeSound() const = 0;
		std::string	getType() const;
};

#endif