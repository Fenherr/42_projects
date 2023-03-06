/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:21:48 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/06 15:01:23 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Account.hpp"

//Constructeur
Account::Account(int initial_deposit)
{
	this->_accountIndex = 0;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	this->_accountIndex++;
}

//Destructeur
Account::~Account(void)
{
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

//Méthode pour faire un dépôt
void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	Account::_totalNbDeposits++;
}

//Méthode pour faire un retrait
bool Account::makeWithdrawal(int withdrawal)
{
	if ((this->_amount - withdrawal) >= 0)
	{
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals++;
		return true;
	}
	return false;
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
	
}

int Account::getNbAccounts(void)
{
	
}

//Initialisation des attributs de classes
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;