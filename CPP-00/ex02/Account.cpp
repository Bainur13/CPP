/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bainur <bainur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:25:47 by bainur            #+#    #+#             */
/*   Updated: 2024/08/05 20:08:38 by bainur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts= 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void print_zero(int time)
{
    if (time < 10)
        std::cout << "0" << time;
    else
        std::cout << time;
}
static void _displayTimesstamp(void)
{
    time_t time_now = time(NULL);
    struct tm *aTime = localtime(&time_now);
    int year = aTime->tm_year + 1900;
    int month = aTime->tm_mon + 1;
    int day = aTime->tm_mday;
    int hour = aTime->tm_hour;
    int min = aTime->tm_min;
    int sec = aTime->tm_sec;

    std::cout << "[" << year;
    print_zero(month);
    print_zero(day);
    std::cout << "_";
    print_zero(hour);
    print_zero(min);
    print_zero(sec);
    std::cout << "]";
}

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimesstamp();
    std::cout << " accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    this->_nbDeposits++;
    _totalNbDeposits++;

    _displayTimesstamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << deposit;
    this->_amount = this->_amount + deposit;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits;
    std::cout << std::endl;
    _totalAmount = _totalAmount + deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimesstamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";withdrawal:";
    if (this->_amount - withdrawal < 0)
    {
        std::cout << "refused" << std::endl;
        return (0);
    }
    
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << withdrawal;
    this->_amount = this->_amount - withdrawal;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
    _totalAmount = _totalAmount - withdrawal;
    return (1);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    _displayTimesstamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
    _displayTimesstamp();
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    std::cout << " index:" << _nbAccounts << ";";
    std::cout << "amount:" << initial_deposit << ";";
    std::cout << "created" << std::endl;
    _totalAmount = _totalAmount + initial_deposit;
    _nbAccounts++;
}

Account::~Account(void)
{
    _displayTimesstamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}
