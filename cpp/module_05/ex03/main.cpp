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
#include "Intern.hpp"

int main()
{
	{
		Intern someRandomIntern;
		AForm* scf;
		
		scf = someRandomIntern.makeForm("shrubbery creation", "garden");
		
		delete scf;
		std::cout << std::endl;
	}
	{
		Intern somaRandomIntern;
		AForm* rrf;
		
		rrf = somaRandomIntern.makeForm("robotomy request", "Bender");
		
		delete rrf;
		std::cout << std::endl;
	}
	{
		Intern someRandomIntern;
		AForm* ppf;
		
		ppf = someRandomIntern.makeForm("presidential pardon", "Austin Power");
		
		delete ppf;
		std::cout << std::endl;
	}
}