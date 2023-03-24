/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:12:43 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 16:36:33 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//==============================Constructors & Destructor======================

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("no_name")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

//=================================Overload operators==========================

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

//======================================Methods================================

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();

	std::ofstream out((this->_target + "_shrubbery").c_str());
	out << "       _-_" << std::endl;
	out << "    /~~   ~~\\" << std::endl;
	out << " /~~         ~~\\" << std::endl;
	out << "{               }" << std::endl;
	out << " \\  _-     -_  /" << std::endl;
	out << "   ~  \\\\ //  ~" << std::endl;
	out << "_- -   | | _- _" << std::endl;
	out << "  _ -  | |   -_" << std::endl;
	out << "      // \\\\" << std::endl;
}

//=============================================================================