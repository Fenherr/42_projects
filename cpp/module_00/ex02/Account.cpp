/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <ngrenoux@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:21:48 by ngrenoux          #+#    #+#             */
/*   Updated: 2023/03/07 10:15:32 by ngrenoux         ###   ########.fr       */
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

//Affichage de la date et heure
void Account::_displayTimestamp(void)
{
	//Récupération de la date et de l'heure actuelles
	std::time_t currentTime = std::time(NULL);
	
	//Affichage de la date puis de l'heure
	std::cout << "[" << 1900 + std::localtime(&currentTime)->tm_year //Récupération de l'année
				<< 1 + std::localtime(&currentTime)->tm_mon			 //Récupération du mois
				<< std::localtime(&currentTime)->tm_mday			 //Récupération du jour
				<< "_"
				<< std::localtime(&currentTime)->tm_hour			 //Récupération de l'heure
				<< std::localtime(&currentTime)->tm_min				 //Récupération des minutes
				<< std::localtime(&currentTime)->tm_sec				 //Récupération des secondes
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

//Récupération des données (Getter) de la class Account
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

//Méthode qui retourne le montant
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
				<< ";nb_deposit:" << _nbDeposits << std::endl;
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
	std::cout << withdrawal << ";" << std::flush;
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
