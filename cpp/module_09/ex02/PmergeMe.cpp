/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:37:06 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/04/25 10:28:36 by ngrenoux         ###   ########.fr       */
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

static void insertDeque(std::deque<unsigned int>& array)
{
	size_t size = array.size();

	for (size_t i = 1; i < size; i++)
	{
		unsigned int tmp = array[i];
		int j = i - 1;

		while (j >= 0 && tmp < array[j])
		{
			array[j + 1] = array[j];
			--j;
		}
			array[j + 1] = tmp;
	}
}

static void mergeDeque(std::deque<unsigned int>& array, std::deque<unsigned int>& left, std::deque<unsigned int>& right)
{
	int i = 0;
	int j = 0;
	int lSize = left.size();
	int rSize = right.size();

	array.clear();

	if (array.size() <= 15)
		insertDeque(array);

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
	mergeDeque(array, left, right);
}

/*----------------------------------------------------------------------------*/

static void insertVector(std::vector<unsigned int>& array)
{
	size_t size = array.size();

	for (size_t i = 1; i < size; i++)
	{
		unsigned int tmp = array[i];
		int j = i - 1;

		while (j >= 0 && tmp < array[j])
		{
			array[j + 1] = array[j];
			--j;
		}
			array[j + 1] = tmp;
	}
}

static void mergeVector(std::vector<unsigned int>& array, std::vector<unsigned int>& left, std::vector<unsigned int>& right)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int lSize = left.size();
	int rSize = right.size();

	if (array.size() <= 15)
		insertVector(array);

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
	mergeVector(array, left, right);
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
	double queueTime = double(queueTimeEnd - queueTimeStart) * 1000000 / CLOCKS_PER_SEC;

	std::cout << "After:\t" << std::flush;
	printArray(_queueArray);

	//Execution + time of execution for vector
	clock_t vectorTimeStart = clock();
	sortVector(_vectorArray);
	clock_t vectorTimeEnd = clock();
	double vectorTime = double(vectorTimeEnd - vectorTimeStart) * 1000000 / CLOCKS_PER_SEC;

	//Time display
	std::cout << "Time to process a range of " << _queueArray.size() << " elements with std::deque : " << std::fixed << std::setprecision(1) << queueTime << " µs" << std::endl;
	std::cout << "Time to process a range of " << _vectorArray.size() << " elements with std::vector : " << vectorTime << " µs" << std::endl;
}

/*=============================Constructor====================================*/

PmergeMe::PmergeMe()
{
}

/*==============================Destructor====================================*/

PmergeMe::~PmergeMe()
{
}
