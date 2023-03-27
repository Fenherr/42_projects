/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:48:54 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/27 09:42:23 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		std::cout << "-----Shrubbery test-----" << std::endl;
		std::cout << std::endl;
		Bureaucrat larva("Employee", 100);
		Bureaucrat supervisor("Supervisor", 50);
		Intern someRandomIntern;
		AForm* scf;
		
		scf = someRandomIntern.makeForm("shrubbery creation", "garden");
		
		try
		{
			supervisor.signForm(*scf);
			larva.executeForm(*scf);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		delete scf;
		std::cout << std::endl;
	}
	{
		std::cout << "-----Robotomy test-----" << std::endl;
		std::cout << std::endl;
		Bureaucrat trevor("Trevor", 45);
		Bureaucrat minion("Minion", 72);
		Intern somaRandomIntern;
		AForm* rrf;
		
		rrf = somaRandomIntern.makeForm("robotomy request", "Bender");
		
		try
		{
			minion.signForm(*rrf);
			trevor.executeForm(*rrf);
			
			std::cout << std::endl;
			
			trevor.executeForm(*rrf);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		
		delete rrf;
		std::cout << std::endl;
	}
	{
		std::cout << "-----Presidential test-----" << std::endl;
		std::cout << std::endl;
		Bureaucrat gorilla("Gorilla", 4);
		Bureaucrat executor("Executor", 20);
		Intern someRandomIntern;
		AForm* ppf;
		
		ppf = someRandomIntern.makeForm("presidential pardon", "Austin Power");
		
		try
		{
			executor.signForm(*ppf);
			gorilla.executeForm(*ppf);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		
		delete ppf;
		std::cout << std::endl;
	}
	{
		std::cout << "-----Form doesn't exist test-----" << std::endl;
		std::cout << std::endl;
		Intern someRandomIntern;
		AForm* randomForm;
		
		randomForm = someRandomIntern.makeForm("random form", "random");
		
		delete randomForm;
		std::cout << std::endl;
	}
	{
		std::cout << "-----Fail execution test-----" << std::endl;
		std::cout << std::endl;
		Bureaucrat larva("Employee", 150);
		Bureaucrat supervisor("Supervisor", 50);
		Intern someRandomIntern;
		AForm* scf;
		
		scf = someRandomIntern.makeForm("shrubbery creation", "garden");
		
		try
		{
			supervisor.signForm(*scf);
			larva.executeForm(*scf);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		delete scf;
		std::cout << std::endl;
	}
	{
		std::cout << "-----Fail sign test-----" << std::endl;
		std::cout << std::endl;
		Bureaucrat larva("Employee", 100);
		Bureaucrat supervisor("Supervisor", 150);
		Intern someRandomIntern;
		AForm* scf;
		
		scf = someRandomIntern.makeForm("shrubbery creation", "garden");
		
		try
		{
			supervisor.signForm(*scf);
			larva.executeForm(*scf);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		delete scf;
		std::cout << std::endl;
	}
}