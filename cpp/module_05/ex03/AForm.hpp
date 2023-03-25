/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:16:42 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/24 15:46:03 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string const _name;
		bool _sign;
		int const _signGrade;
		int const _executeGrade;
		
	protected:
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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	public:
		AForm();
		AForm(std::string const name, int const signGrade, int const executeGrade);
		AForm(const AForm &copy);
		virtual ~AForm();
		
		AForm & operator=(const AForm &rhs);
		
		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat &target);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream&   operator<<( std::ostream& o, const AForm& rhs );

#endif