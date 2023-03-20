/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:18:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 11:20:24 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &copy);
		virtual ~WrongAnimal();

		WrongAnimal & operator=(WrongAnimal const & rhs);

		void	makeSound() const;
		std::string	getType() const;
};

#endif