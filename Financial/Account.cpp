#include "Account.hpp"
#include "Money.hpp"
int Account::nextAccID = 0;

Account::Account(const int customerID) {
	//Associated with a specific customer ID
	this->CustID = customerID;
	//Unique account ID
	this->accID = nextAccID;
	//Increments ID
	nextAccID++;
	
}

int Account::getAccountID() const {
	return accID;
}

int Account::getCustomerID() const {
	return CustID;
}

Money Account::getBalance() const {
	return *Balance;
	
}

Account::~Account() {
	// TODO implement
}



