#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int		Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:"
		<< _totalAmount << ";deposits:" << _totalNbDeposits
		<< ";withdrawals:"<< _totalNbWithdrawals<< std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
	return ;
}


Account::Account(void) : _accountIndex(_nbAccounts),
						  _amount(0),
						  _nbDeposits(0),
						  _nbWithdrawals(0){
	_nbAccounts += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
	return ;
}

Account::~Account(void) {
	_nbAccounts -= 1;
	_totalAmount -= this->_amount;
    if (this->_amount > 0) {
        Account::_totalNbWithdrawals++;
    } else if (this->_amount < 0) {
        Account::_totalNbDeposits++;
    }
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";closed" << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit) {
	int	previous;

	previous = _amount;
	_amount += deposit;
	_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << previous
		<< ";deposit:" << deposit << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	previous;

	previous = _amount;
	if (previous - withdrawal < 0) {
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << previous
			<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << previous
		<< ";withdrawal:" << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const {
	return _amount;
}

void Account::_displayTimestamp(void) {
	char		ptr[25];
	time_t		now;
	struct tm	*info;

	time(&now);
	info = localtime(&now);
	strftime(ptr, 25, "[%Y%m%d-%H%M%S] ", info);
	std::cout << ptr;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}