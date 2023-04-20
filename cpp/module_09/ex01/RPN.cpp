/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:02:03 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/20 11:46:53 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*=============================Constructor====================================*/

RPN::RPN()
{
}

/*==============================Destructor====================================*/

RPN::~RPN()
{
}

/*===============================Function=====================================*/

int operations(char op, int nb1, int nb2)
{
	int res;
	
	switch(op)
	{
		case '+':
			res = nb1 + nb2;
			break ;
		case '-':
			res = nb1 - nb2;
			break ;
		case '*':
			res = nb1 * nb2;
			break ;
		case '/':
			res = nb1 / nb2;
			break ;
		default:
			std::cout << "Error: bad operator." << std::endl;
			break ;
	}
	return res;
}

/*===========================Member functions=================================*/

void RPN::push(int nb)
{
	_stack.push(nb);
}

int RPN::pop()
{
	int nb = _stack.top();
	_stack.pop();
	return nb;
}

bool RPN::empty()
{
	return _stack.empty();
}

void RPN::execute(std::string str)
{
	RPN stack;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		if (ch == ' ' || ch == '\n')
			continue ;
		
		if (std::isdigit(ch))
		{
			int nb = ch - '0';
			stack.push(nb);
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			if (stack.empty())
				throw ErrorException();
			
			int nb2 = stack.pop();
			if (stack.empty())
				throw ErrorException();
			
			int nb1 = stack.pop();
			
			int res = operations(ch, nb1, nb2);
			stack.push(res);
		}
		else
			throw ErrorException();
	}
	if (stack.empty())
		throw ErrorException();
	
	int res = stack.pop();
	if (!stack.empty())
		throw ErrorException();
	std::cout << res << std::endl;
}