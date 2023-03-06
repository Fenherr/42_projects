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
#include <iomanip>
#include <ctime>

#include "Account.hpp"

//Initialisation des attributs de classes
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//Affichage du temps local
void Account::_displayTimestamp(void)
{
	std::time_t currentTime = std::time(NULL);
	
	std::cout << "[" << 1900 + std::localtime(&currentTime)->tm_year
				<< std::setw(2) << 1 + std::localtime(&currentTime)->tm_mon
				<< std::setw(2) << std::localtime(&currentTime)->tm_mday
				<< "_"
				<< std::setw(2) << std::localtime(&currentTime)->tm_hour
				<< std::setw(2) << std::localtime(&currentTime)->tm_min
				<< std::setw(2) << std::localtime(&currentTime)->tm_sec
				<< "] " << std::flush;
}

//Constructeur
Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

//Destructeur
Account::~Account(void)
{
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
}

//Getter de la class Account
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

//Méthode qui vérifie le montant
int Account::checkAmount(void) const
{
	return _amount;
}

//Méthode pour faire un dépôt
void Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount << ";" << std::flush;
	_amount += deposit;
	std::cout << "deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposit" << _nbDeposits << std::endl;
}

//Méthode pour faire un retrait
bool Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:" << std::flush;
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";" << std::endl;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	std::cout << "amount:" << _amount
				<< ";nb_deposit:" << _nbDeposits << std::endl;
	return true;
}

//Méthode pour afficher les infos du compte
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposit:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

//Méthode pour afficher le status du compte
void Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposit:" <<_nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
