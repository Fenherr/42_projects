/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:03:50 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/11 14:06:53 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		MutantStack();
		MutantStack(const MutantStack &copy);
		~MutantStack();
		
		MutantStack & operator=(const MutantStack & rhs);
		
		typedef typename std::deque<T>::iterator iterator;
		
		iterator begin();
		iterator end();
};

/*============================================================================*/

/*======================Constructors & destructor=============================*/

template<typename T>
MutantStack<T>::MutantStack()
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
	*this = copy;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

/*===============================Operator=====================================*/

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack & rhs)
{
	std::stack<T, std::deque<T> >::operator=(rhs);
	return *this;
}

/*============================Member methods==================================*/

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T, std::deque<T> >::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T, std::deque<T> >::c.end();
}

/*============================================================================*/

#endif