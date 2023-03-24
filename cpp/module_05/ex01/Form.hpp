/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:16:42 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 10:32:20 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const _name;
		bool _sign;
		int const _signGrade;
		int const _executeGrade;

	public:
		Form();
		Form(std::string const name, int const signGrade, int const executeGrade);
		Form(const Form &copy);
		~Form();
		
		Form & operator=(const Form &rhs);
		
		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		
		void beSigned(Bureaucrat &target);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif