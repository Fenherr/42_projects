/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:01:10 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/23 13:32:07 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat employee("Employee", 150);
		Bureaucrat boss("Boss", 1);
		
		std::cout << employee << std::endl;
		std::cout << boss << std::endl;
		
		std::cout << std::endl;
		
		employee.promote();
		std::cout << employee << std::endl;
		
		std::cout << std::endl;
		
		boss.demote();
		std::cout << boss << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}