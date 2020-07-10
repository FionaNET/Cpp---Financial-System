#include "Transaction.hpp"
#include <string>

int Transaction::TransactionID = 1;

Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount){
	//Set Transaction ID
	TransID = TransactionID;
	//Increment after transaction ID
	TransactionID++;

	//AccountFrom/To are pointing to accounts 
	this->accountFrom = fromAccount;
	this->accountTo = toAccount;

	if (amount.asCents() < 0) {
		Transamount = Money(0,0);
	}
	else {
		Transamount = amount;
	}
	
	//Constructed in pending state 
	TransState = PENDING;
	
}

bool Transaction::performTransaction(){
	
	//Check if either transaction fails using bool and withdraw/etc
	bool from = accountFrom->checkWithdrawMoney(Transamount);
	bool to = accountTo->checkDepositMoney(Transamount);
	
	
	if (from && to) {
		//If check suceeds and both accounts are successful then perform transaction
		accountFrom->withdrawMoney(Transamount);
		accountTo->depositMoney(Transamount);
		//If both are valid, mark the transaction as complete
		TransState = COMPLETED;
		return true;
	}else {
		//Failure
		TransState = FAILED;
		return false;
	}

}

TransactionState Transaction::getState() const {
	return TransState;
}

Money Transaction::getAmount() const {
	return Transamount;
}

Account* Transaction::getToAccount() const {
	return accountTo;
}

Account* Transaction::getFromAccount() const {
	return accountFrom;
}


int Transaction::getID() const {
	return TransID;
}

Transaction::~Transaction() {
	// TODO implement
}

