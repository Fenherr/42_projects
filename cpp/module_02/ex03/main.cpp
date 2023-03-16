/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:37:55 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/15 15:21:55 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point	t1(3.0f, 2.0f);
	Point	t2(7, 7);
	Point	t3(11, 4);
	Point	p1(7, 4);
	Point	p2(0, 0);
	Point	p3(9, 5);

	if (bsp(t1, t2, t3, p1) == true)
		std::cout << "The first point is in the triangle" << std::endl;
	else
		std::cout << "The first point isn't in the triangle" << std::endl;

	if (bsp(t1, t2, t3, p2) == true)
		std::cout << "The second point is in the triangle" << std::endl;
	else
		std::cout << "The second point isn't in the triangle" << std::endl;

	if (bsp(t1, t2, t3, p3) == true)
		std::cout << "The third point is in the triangle" << std::endl;
	else
		std::cout << "The third point isn't in the triangle" << std::endl;
}