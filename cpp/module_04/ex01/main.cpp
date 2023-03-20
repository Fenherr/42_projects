/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:31:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/20 16:06:47 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int				k;
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	
	j->makeSound();
	i->makeSound();
	
	delete j;
	delete i;
	
	const Animal* animals[100];
	for (k = 0; k < 50; k++)
		animals[k] = new Dog();
	while (k < 100)
	{
		animals[k] = new Cat();
		k++;
	}
	for (int i = 0; i < 100; i++)
		animals[i]->makeSound();
	for (int j = 0; j < 100; j++)
		delete animals[j];
}