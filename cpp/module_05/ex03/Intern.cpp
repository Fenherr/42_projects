/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:45:04 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/27 09:29:42 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//==============================Constructors & Destructor======================

Intern::Intern()
{
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern()
{
}

//=================================Overload operators==========================

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

//======================================Methods================================

AForm * Intern::makeForm(std::string formName, std::string target) const
{
	AForm *form;
	int i;
	std::string formTab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	for (i = 0; i < 3; i++)
	{
		if (formName == formTab[i])
			break ;
	}
	
	switch (i)
	{
	case 0:
		form = new ShrubberyCreationForm(target);
		std::cout << "Intern creates " << formName << std::endl;
		return form;
		break;
	case 1:
		form = new RobotomyRequestForm(target);
		std::cout << "Intern creates " << formName << std::endl;
		return form;
		break;
	case 2:
		form = new PresidentialPardonForm(target);
		std::cout << "Intern creates " << formName << std::endl;
		return form;
		break;
	default:
		std::cout << "Form doesn't exist." << std::endl;
		std::cout << "Choose one form:" << std::endl;
		std::cout << "\t- shrubbery form" << std::endl;
		std::cout << "\t- roboromy request" << std::endl;
		std::cout << "\t- presidential pardon" << std::endl;
		break;
	}
	return NULL;
}

//=============================================================================