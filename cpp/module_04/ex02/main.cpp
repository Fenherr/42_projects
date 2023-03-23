/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:31:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/23 11:14:43 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "----Subject test----" << std::endl;
	std::cout << std::endl;
	
	const AAnimal*	j = new Dog();
	const AAnimal*	i = new Cat();
	
	j->makeSound();
	i->makeSound();
	
	delete j;
	delete i;
	
	std::cout << std::endl;
	std::cout << "----Zoo test----" << std::endl;
	std::cout << std::endl;
	
	int				k;
	const AAnimal* animals[100];
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
		
	std::cout << std::endl;
	std::cout << "----Copy test----" << std::endl;
	std::cout << std::endl;
	
	Dog basic;
	Dog tmp = basic;
	
	std::cout << std::endl;
	
	Cat basic2;
	Cat tmp2 = basic2;
	
	std::cout << std::endl;
	std::cout << "----Brain idea test----" << std::endl;
	std::cout << std::endl;
	
	Dog dog;
	
	dog.getBrain()->setIdea(0, "I love my master");
	std::cout << "Dog's idea: " << dog.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
}