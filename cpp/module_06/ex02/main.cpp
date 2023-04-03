/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:14:29 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/03 10:29:01 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate()
{
	srand(time(0));
	if (rand() % 3 == 0)
		return (new A);
	else if (rand() % 3 == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "\e[0;31mIt's A*\e[m" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "\e[0;32mIt's B*\e[m" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "\e[0;34mIt's C*\e[m" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &base = dynamic_cast<A&>(p);
		(void)base;
		std::cout << "\e[0;31mIt's A&\e[m" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	
	try
	{
		B &base = dynamic_cast<B&>(p);
		(void)base;
		std::cout << "\e[0;32mIt's B&\e[m" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	
	try
	{
		C &base = dynamic_cast<C&>(p);
		(void)base;
		std::cout << "\e[0;34mIt's C&\e[m" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	Base *test;
	
	test = generate();
	
	std::cout << "Test with ptr" << std::endl;
	identify(test);
	
	std::cout << "Test with ref" << std::endl;
	identify(*test);
}