/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:35:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/15 13:01:38 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();								//Constructeur
		Point(float const n1, float const n2);	//Constructeur surchargé
		
		Point(Point const &copy);				//Constructeur copie
		
		~Point();								//Destructeur

		Point & operator=(Point const & rhs);	//Surcharge de l'opérateur '='

		Fixed	getX() const;					//Getter de x
		Fixed	getY() const;					//Getter de y
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif