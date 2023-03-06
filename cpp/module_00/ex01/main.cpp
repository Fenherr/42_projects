/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:54:06 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/06 09:56:34 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   phoneBook;
    std::string input = "";

    phoneBook.menu();
    while (input.compare("EXIT"))
    {
        if (input.compare("ADD") == 0)
            phoneBook.addContact();
        else if (input.compare("SEARCH") == 0)
        {
            phoneBook.printContact();
            phoneBook.search();
        }
        std::cout << ">> " << std::flush;
        std::getline(std::cin, input);
    }
    return (0);
}