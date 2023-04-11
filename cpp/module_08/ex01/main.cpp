/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:15:07 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/11 14:45:57 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "Span.hpp"

int main()
{
	{
		std::cout << "=== Classic test ===" << std::endl;
		
		std::cout << std::endl;
		
		Span test = Span(5);
		
		try
		{
			test.addNumber(89);
			test.addNumber(17);
			test.addNumber(42);
			test.addNumber(5);
			test.addNumber(5);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << "List:" << std::endl;
		std::cout << test << std::endl;
		
		try
		{
			std::cout << "The longest Span: " << test.longestSpan() << std::endl;
			std::cout << "The shortest Span: " << test.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "=== Max int & min int test ===" << std::endl;
		
		std::cout << std::endl;
		
		Span test = Span(5);
		
		try
		{
			test.addNumber(2147483647);
			test.addNumber(-2147483648);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << "List:" << std::endl;
		std::cout << test << std::endl;
		
		try
		{
			std::cout << "The longest Span: " << test.longestSpan() << std::endl;
			std::cout << "The shortest Span: " << test.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "=== List is full test ===" << std::endl;
		
		std::cout << std::endl;
		
		Span test = Span(5);
		
		try
		{
			std::cout << "Add 89" << std::endl;
			test.addNumber(89);
			std::cout << "Add 17" << std::endl;
			test.addNumber(17);
			std::cout << "Add 42" << std::endl;
			test.addNumber(42);
			std::cout << "Add 63" << std::endl;
			test.addNumber(63);
			std::cout << "Add 5" << std::endl;
			test.addNumber(5);
			std::cout << "Add 74" << std::endl;
			test.addNumber(74);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << std::endl;
	}
	{
		std::cout << "=== Size 1 test ===" << std::endl;
		
		std::cout << std::endl;
		
		Span test = Span(5);
		
		try
		{
			test.addNumber(89);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << "List:" << std::endl;
		std::cout << test << std::endl;
		
		try
		{
			std::cout << "The longest Span: " << test.longestSpan() << std::endl;
			std::cout << "The shortest Span: " << test.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "=== Empty list test ===" << std::endl;
		
		std::cout << std::endl;
		
		Span test = Span(5);
		
		std::cout << "List:" << std::endl;
		std::cout << test << std::endl;
		
		try
		{
			std::cout << "The longest Span: " << test.longestSpan() << std::endl;
			std::cout << "The shortest Span: " << test.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "=== Range of iterators test ===" << std::endl;
		
		std::cout << std::endl;
		
		try
		{
			std::list<int> lst(10000);
			std::srand(time(0));
			std::generate(lst.begin(), lst.end(), std::rand);
			
			Span test(lst.size());
			
			test.iteratorRange(lst.begin(), lst.end());
		
			std::cout << "The longest Span: " << test.longestSpan() << std::endl;
			std::cout << "The shortest Span: " << test.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}