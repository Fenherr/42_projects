/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:45:03 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/26 17:26:11 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <vector>

class PmergeMe
{
	private:
		std::vector<unsigned int> _vectorArray;
		std::deque<unsigned int> _queueArray;

		PmergeMe(const PmergeMe &copy);
		PmergeMe operator=(const PmergeMe & rhs);

		void printArray(std::deque<unsigned int>& array);
		void sortDeque(std::deque<unsigned int>& array);
		void sortVector(std::vector<unsigned int>& array);

	public:
		PmergeMe();
		~PmergeMe();

		void fillArray(std::string nbStr);
		void execute();

	class ArgumentsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
