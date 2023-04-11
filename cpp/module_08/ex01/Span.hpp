/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:57:02 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/11 14:40:29 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <limits>
#include <algorithm>

class Span
{
	private:
		unsigned int _N;
		std::list<int> _list;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		~Span();
		
		Span & operator=(const Span & rhs);
		
		void addNumber(int nb);
		void iteratorRange(std::list<int>::iterator iBegin, std::list<int>::iterator iEnd);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
		const std::list<int>* getList() const;
		
		class AddNewElementException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Cannot be added. Maximum capacity reached.";
				}
		};
		
		class InssufficientSize : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Inssufficient size.";
				}
		};
};

std::ostream & operator<<(std::ostream & o, const Span & stack);

#endif