/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:02:22 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/22 11:35:33 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "My tests" << std::endl;
		std::cout << std::endl;
		Dog*	dog = new Dog();
		Cat*	cat = new Cat();
		Animal*	animal = new Animal();
		WrongAnimal*	wrongCat = new WrongCat();
		
		dog->makeSound();
		cat->makeSound();
		animal->makeSound();
		wrongCat->makeSound();
		
		std::cout << std::endl;
		std::cout << "========================================" << std::endl;
		std::cout << std::endl;
		
		delete dog;
		delete cat;
		delete wrongCat;
		delete animal;
	}
	{
		std::cout << "Subject tests" << std::endl;
		std::cout << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		
		std::cout << std::endl;
		std::cout << "========================================" << std::endl;
		
		delete j;
		delete i;
		delete meta;
	}
}