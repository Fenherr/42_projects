/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:48:54 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 17:04:06 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		Bureaucrat larva("Employee", 100);
		Bureaucrat supervisor("Supervisor", 50);
		ShrubberyCreationForm form("garden");

		try
		{
			supervisor.signForm(form);
			larva.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		Bureaucrat trevor("Trevor", 45);
		Bureaucrat minion("Minion", 72);
		RobotomyRequestForm form("normie");
		
		try
		{
			minion.signForm(form);
			trevor.executeForm(form);
			
			std::cout << std::endl;
			
			trevor.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << std::endl;
	}
	{
		Bureaucrat gorilla("Gorilla", 4);
		Bureaucrat executor("Executor", 20);
		PresidentialPardonForm form("Jarvis");
		
		try
		{
			executor.signForm(form);
			gorilla.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << std::endl;
	}
}