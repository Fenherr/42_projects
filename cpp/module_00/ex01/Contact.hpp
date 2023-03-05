/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:00:14 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/04 16:00:14 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _number;
        std::string _darkestSecret;
        int _index;

        std::string _printLen(std::string str) const;
        std::string _getInput(std::string str) const;
    
    public:
        Contact();
        ~Contact();
        void init(void);
        void view(int index) const;
        void display(int index) const;
        void setIndex(int i);
};

#endif