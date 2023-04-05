/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:34:16 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/05 14:11:14 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	
	public:
		//Constructors & destructor
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		~Array();
		
		//Operators overload
		Array & operator=(const Array & rhs);
		T& operator[] (unsigned int i);
		
		//Method
		unsigned int size() const;
		
		//Exception
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index out of bounds.";
				}
		};
};

//Default constructor
template<typename T>
Array<T>::Array()
{
	_array = NULL;
	_size = 0;
}

//Overload constructor
template<typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n]();
	_size = n;
}

//Copy constructor
template<typename T>
Array<T>::Array(const Array &copy)
{
	_size = copy._size;
	_array = new T[copy._size];
	
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
}

//Destructor
template<typename T>
Array<T>::~Array()
{
	delete [] _array;
}

//Operator = overload
template<typename T>
Array<T> & Array<T>::operator=(const Array & rhs)
{
	if (this != &rhs)
	{
		if (_array)
			delete [] _array;
		_array = new T[rhs.size()];
		_size = rhs._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
	}
	return *this;
}

//Operator [] overload
template<typename T>
T& Array<T>::operator[] (unsigned int i)
{
	if (i > _size - 1)
		throw OutOfBoundsException();
	return _array[i];
}

//Operator << overload
template<typename T>
std::ostream & operator<<(std::ostream & o, const Array<T> & array)
{
	for (unsigned int i = 0; i < array.size(); i++)
		o << array[i] << " ";
	return o;
}

//Method
template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif