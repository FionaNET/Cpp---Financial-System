#include "Account.hpp"

#ifndef SAVINGSACCOUNT_HPP_
#define SAVINGSACCOUNT_HPP_

class SavingsAccount : public Account {

private:
	int NumofDep;
	Money* BonusAm = new Money(10, 0);
	SavingsAccount& operator=(const SavingsAccount &other);
    SavingsAccount(const SavingsAccount &other);
public:
	SavingsAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool checkWithdrawMoney(Money amount);
	bool depositMoney(Money amount);
	bool checkDepositMoney(Money amount);
	Money getBonusValue() const;
	virtual ~SavingsAccount();
};

#endif /* SAVINGSACCOUNT_HPP_ */
