#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_
#include "Money.hpp"
class Account{
//TODO Implement members as needed
private:
	Account& operator=(const Account &other);
	Account(const Account &other);
protected:
	
	Money* Balance = new Money(0, 0);
	int CustID;
	int accID;
	static int nextAccID;

	
public:
	
	Account(const int customerID);
	virtual bool withdrawMoney(Money amount) = 0;
	virtual bool checkWithdrawMoney(Money amount) = 0 ;
	virtual bool depositMoney(Money amount) = 0;
	virtual bool checkDepositMoney(Money amount) = 0;
	int getCustomerID() const;
	int getAccountID() const;
	Money getBalance() const;
	virtual ~Account();

};

#endif /* ACCOUNT_HPP_ */
