/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:54:17 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 17:03:15 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//==============================Constructors & Destructor======================

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("no_name")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("Presidential Pardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _target(copy._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

//=================================Overload operators==========================

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

//======================================Methods================================

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	
	std::cout << this->_target << " was forgiven by Zaphod Beeblebrox !" << std::endl;
}

//=============================================================================