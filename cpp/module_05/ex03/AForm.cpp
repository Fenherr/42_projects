/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:42:46 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 10:40:11 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//==============================Constructors & Destructor======================

AForm::AForm() : _name("no_name"), _sign(false), _signGrade(150), _executeGrade(150)
{
}

AForm::AForm(std::string const name, int const signGrade, int const executeGrade) :
	_name(name), _sign(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _sign(copy._sign), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
}

AForm::~AForm()
{
}

//=================================Overload operators==========================

AForm & AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_sign = rhs._sign;
	return *this;
}

std::ostream&   operator<<( std::ostream& o, const AForm& rhs )
{
	o << "Form name: " << rhs.getName() << std::endl
	  << "Is signed: " << rhs.getSign() << std::endl
	  << "Grade required to sign the form: " << rhs.getSignGrade() << std::endl
	  << "Grade required to execute the form: " << rhs.getExecuteGrade();
	return o;
}

//======================================Getters================================

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSign() const
{
	return _sign;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

//======================================Methods================================

void AForm::beSigned(Bureaucrat &target)
{
	if (target.getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_sign = true;
}

//=====================================Exceptions==============================

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form not signed";
}

//=============================================================================