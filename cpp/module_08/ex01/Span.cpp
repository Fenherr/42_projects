/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:41:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/07 16:11:33 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>

#include "Span.hpp"

/*===============================Constructors=================================*/

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &copy) : _N(copy._N)
{
}

/*================================Destructor==================================*/

Span::~Span()
{
}

/*==================================Getter====================================*/

const std::list<int>* Span::getList() const
{
	return &_list;
}

/*================================Operators===================================*/

Span & Span::operator=(const Span & rhs)
{
	if (this != &rhs)
	{
		_N = rhs._N;
		_list = rhs._list;
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, const Span & stack)
{
	for (std::list<int>::const_iterator it = stack.getList()->begin(); it != stack.getList()->end(); ++it)
		o << *it << std::endl;
	return o;
}

/*=============================Member functions===============================*/

void Span::addNumber(int nb)
{
	if (_list.size() >= _N)
		throw Span::AddNewElementException();
	_list.push_back(nb);
}

void Span::iteratorRange(std::list<int>::iterator iBegin, std::list<int>::iterator iEnd)
{
	if (_list.size() >= _N)
		throw Span::AddNewElementException();
	_list.insert(_list.end(), iBegin, iEnd);
}

unsigned int Span::shortestSpan()
{
	unsigned int check = std::numeric_limits<unsigned int>::max();
	
	if (_list.size() < 2)
		throw Span::InssufficientSize();
	_list.sort();
	
	for (std::list<int>::iterator i = _list.begin(); i != _list.end(); ++i)
	{
		std::list<int>::iterator next = i;
		++next;
		
		for (; next != _list.end(); ++next)
		{
			unsigned int diff = *next - *i;
			if (diff < check)
				check = diff;
		}
	}
	return check;
}

unsigned int Span::longestSpan()
{
	if (_list.size() < 2)
		throw Span::InssufficientSize();
	_list.sort();
	return (_list.back() - _list.front());
}

/*============================================================================*/