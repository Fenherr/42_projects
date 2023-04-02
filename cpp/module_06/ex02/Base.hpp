/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:14:43 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/02 12:14:43 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <stdlib.h>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base
{
	public:
		virtual ~Base(){};
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif