/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:37:06 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/24 10:26:41 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*===========================Member Functions=================================*/

void PmergeMe::fillArray(std::string nbStr)
{
	unsigned int nb;

	for (unsigned int i = 0; i < nbStr.size(); i++)
	{
		if (!std::isdigit(nbStr[i]))
			throw PmergeMe::ArgumentsException();
	}

	nb = static_cast<unsigned int>(std::atoi(nbStr.c_str()));

	_queueArray.push_back(nb);
	_vectorArray.push_back(nb);
}

void PmergeMe::printArray(std::deque<unsigned int>& array)
{
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

/*----------------------------------------------------------------------------*/

static void mergeInsertDeque(std::deque<unsigned int>& array, std::deque<unsigned int>& left, std::deque<unsigned int>& right)
{
	int i = 0;
	int j = 0;
	int lSize = left.size();
	int rSize = right.size();

	array.clear();

	//Left and right fusion in original array
	while (i < lSize && j < rSize)
	{
		if (left[i] <= right[j])
			array.push_back(left[i++]);
		else
			array.push_back(right[j++]);
	}

	//Copy of left array elements in original array
	while (i < lSize)
		array.push_back(left[i++]);

	//Same with right
	while (j < rSize)
		array.push_back(right[j++]);

	left.clear();
	right.clear();
}

void PmergeMe::sortDeque(std::deque<unsigned int>& array)
{
	if (array.size() <= 1)
		return ;

	int mid = array.size() / 2;

	std::deque<unsigned int> left(array.begin(), array.begin() + mid);
	std::deque<unsigned int> right(array.begin() + mid, array.end());

	//Sort
	if (left.size() > 1)
		sortDeque(left);

	if (right.size() > 1)
		sortDeque(right);

	//Merge
	mergeInsertDeque(array, left, right);
}

/*----------------------------------------------------------------------------*/

static void mergeInsertVector(std::vector<unsigned int>& array, std::vector<unsigned int>& left, std::vector<unsigned int>& right)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int lSize = left.size();
	int rSize = right.size();

	//Left and right fusion in original array
	while (i < lSize && j < rSize)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	//Copy of left array elements in original array
	while (i < lSize)
		array[k++] = left[i++];

	//Same with right
	while (j < rSize)
		array[k++] = right[j++];
}

void PmergeMe::sortVector(std::vector<unsigned int>& array)
{
	if (array.size() <= 1)
		return ;

	int mid = array.size() / 2;

	std::vector<unsigned int> left(array.begin(), array.begin() + mid);
	std::vector<unsigned int> right(array.begin() + mid, array.end());

	//Sort
	if (left.size() > 1)
		sortVector(left);

	if (right.size() > 1)
		sortVector(right);

	//Merge
	mergeInsertVector(array, left, right);
}

/*----------------------------------------------------------------------------*/

void PmergeMe::execute()
{
	std::cout << "Before:\t" << std::flush;
	printArray(_queueArray);

	//Execution + time of execution for queue
	clock_t queueTimeStart = clock();
	sortDeque(_queueArray);
	clock_t queueTimeEnd = clock();
	double queueTime = double(queueTimeEnd - queueTimeStart) / CLOCKS_PER_SEC;

	std::cout << "After:\t" << std::flush;
	printArray(_queueArray);

	//Execution + time of execution for vector
	clock_t vectorTimeStart = clock();
	sortVector(_vectorArray);
	clock_t vectorTimeEnd = clock();
	double vectorTime = double(vectorTimeEnd - vectorTimeStart) / CLOCKS_PER_SEC;

	//Time display
	std::cout << "Time to process a range of " << _queueArray.size() << " elements with std::deque : " << std::fixed << queueTime << " sec" << std::endl;
	std::cout << "Time to process a range of " << _vectorArray.size() << " elements with std::vector : " << vectorTime << " sec" << std::endl;
}

/*=============================Constructor====================================*/

PmergeMe::PmergeMe()
{
}

/*==============================Destructor====================================*/

PmergeMe::~PmergeMe()
{
}
