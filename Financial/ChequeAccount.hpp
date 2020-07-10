#include "Account.hpp"

#ifndef CHEQUEACCOUNT_HPP_
#define CHEQUEACCOUNT_HPP_

class ChequeAccount : public Account {

private:
	ChequeAccount& operator=(const ChequeAccount &other);
    ChequeAccount(const ChequeAccount &other);
	Money* TransFee = new Money(1, 0);

public:
	
	ChequeAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool checkWithdrawMoney(Money amount);
	bool depositMoney(Money amount);
	bool checkDepositMoney(Money amount);
	Money* getTransactionFee() const;
	virtual ~ChequeAccount();
};

#endif /* CHEQUEACCOUNT_HPP_ */
