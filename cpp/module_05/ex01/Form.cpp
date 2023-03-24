/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:42:46 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 10:40:11 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//==============================Constructors & Destructor======================

Form::Form() : _name("no_name"), _sign(false), _signGrade(150), _executeGrade(150)
{
}

Form::Form(std::string const name, int const signGrade, int const executeGrade) :
	_name(name), _sign(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _sign(copy._sign), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
}

Form::~Form()
{
}

//=================================Overload operators==========================

Form & Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_sign = rhs._sign;
	return *this;
}

std::ostream&   operator<<( std::ostream& o, const Form& rhs )
{
	o << "Form name: " << rhs.getName() << std::endl
	  << "Is signed: " << rhs.getSign() << std::endl
	  << "Grade required to sign the form: " << rhs.getSignGrade() << std::endl
	  << "Grade required to execute the form: " << rhs.getExecuteGrade();
	return o;
}

//======================================Getters================================

std::string Form::getName() const
{
	return _name;
}

bool Form::getSign() const
{
	return _sign;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

//======================================Methods================================

void Form::beSigned(Bureaucrat &target)
{
	if (target.getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_sign = true;
}

//=====================================Exceptions==============================

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

//=============================================================================