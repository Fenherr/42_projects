/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:28:27 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 16:41:58 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//==============================Constructors & Destructor======================

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("no_name")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy request", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

//=================================Overload operators==========================

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

//======================================Methods================================

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	
	std::cout << "BZZZZZZZZZZZ.....BRRRRRRRR...." << std::endl;
	static int i;
	if (i % 2 == 0)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << "The operation failed" << std::endl;
	i++;
}

//=============================================================================