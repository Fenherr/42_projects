/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:34 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/02/10 14:20:36 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contact[8];
        int     _readInput(void) const;
    
    public:
        PhoneBook();
        ~PhoneBook();
        void addContact(void);
        void printContact(void) const;
        void search(void) const;
        void menu(void) const;
};

#endif
