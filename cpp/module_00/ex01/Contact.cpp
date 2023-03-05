/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:00:23 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/04 16:00:23 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str) const
{
    std::string input = "";
    bool        valid = false;

    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else
        {
            std::cin.clear();
            std::cout << "Invalid input." << std::endl;
        }
    } while (!valid);
    return (input);
}

void Contact::init(void)
{
    std::cin.ignore();
    this->_firstName = this->_getInput("First name: ");
    this->_lastName = this->_getInput("Last name: ");
    this->_nickname = this->_getInput("nickname: ");
    this->_number = this->_getInput("Phone number: ");
    this->_darkestSecret = this->_getInput("Darkest secret: ");
    std::cout << std::endl;
}

std::string Contact::_printLen(std::string str) const
{
    if (str.size() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void Contact::setIndex(int i)
{
    this->_index = i;
}

void Contact::view(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void Contact::display(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << "==== CONTACT No" << index << " ====" << std::endl;
    std::cout << "First name:\t" << this->_firstName << std::endl;
    std::cout << "Last name:\t" << this->_lastName << std::endl;
    std::cout << "Nickname:\t" << this->_nickname << std::endl;
    std::cout << "Phone number:\t" << this->_number << std::endl;
    std::cout << "Darkest secret:\t" << this->_darkestSecret << std::endl;
    std::cout << std::endl;
}