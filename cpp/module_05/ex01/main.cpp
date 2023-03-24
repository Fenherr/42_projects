/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:01:10 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 10:45:45 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat employee("Employee", 110);
		
		Form form("Test form", 100, 100);
		
		std::cout << std::endl;
		
		std::cout << employee << std::endl;
		
		std::cout << std::endl;
		
		std::cout << form << std::endl;
		
		std::cout << std::endl;
		
		employee.signForm(form);
		
		std::cout << std::endl;
		
		std::cout << form << std::endl;
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