/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:12:11 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/11 14:35:02 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "==== My test ====" << std::endl;
	std::cout << std::endl;
	{
		MutantStack<int> test;
		
		std::cout << "Fill stack" << std::endl;
		test.push(42);
		test.push(7);
		
		std::cout << std::endl;
		
		MutantStack<int>::iterator it = test.begin();
		MutantStack<int>::iterator ite = test.end();
		
		std::cout << "Display the stack" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		--it;
		--it;
		
		std::cout << std::endl;
		
		std::cout << "Delete first element" << std::endl;
		test.pop();
		
		std::cout << std::endl;
		
		std::cout << "Stack's size" << std::endl;
		std::cout << test.size() << std::endl;
		
	}
	std::cout << std::endl;
	std::cout << "==== Subject test ====" << std::endl;
	std::cout << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		return 0;
	}
}