#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include <string>
#include "Account.hpp"
#include "Money.hpp"

enum TransactionState {
	COMPLETED,
	PENDING,
	FAILED
};

class Transaction {
	
private:
	Transaction& operator=(const Transaction &other);
    Transaction(const Transaction &other);
	Account* accountFrom;
	Account* accountTo;
	Money Transamount;
	TransactionState TransState; 
	int TransID;

public:
	
	static int TransactionID;
	Transaction(Account* fromAccount, Account* toAccount, Money amount);
	bool performTransaction();
	TransactionState getState() const;
	Money getAmount() const;
	Account* getFromAccount() const;
	Account* getToAccount() const;
	int getID() const;
	virtual ~Transaction();
};

#endif /* TRANSACTION_HPP_ */
