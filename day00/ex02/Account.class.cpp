/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:50:43 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/14 11:50:44 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

/* Constructors and destructors */

Account::Account() :
_accountIndex(Account::_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account(int initial_deposit) :
_accountIndex(Account::_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	Account::_nbAccounts += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	Account::_nbAccounts -= 1;
}

/* display-methods */

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:"
		<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
			<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int Account::checkAmount() const {
	return this->_amount;
}

/* deposit and withdrawal methods */

bool Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";

	if (this->_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	return (true);
}

void Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;


	this->_nbDeposits += 1;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
}

/* get-methods */

int Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int Account::getTotalAmount() {
	return Account::_totalAmount;
}

int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

/* timestamp method */

void Account::_displayTimestamp() {

	std::time_t time = std::time(&time);
	struct tm * timeinfo;
	char buff[20];

	timeinfo = localtime(&time);
	strftime(buff, 20,"%Y%m%d_%H%M%S", timeinfo);
	std::cout << '[' << buff << "] ";
}

/* static initialization */

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;