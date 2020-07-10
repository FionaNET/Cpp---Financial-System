#include "CreditAccount.hpp"
//TODO Implement CreditAccount class

CreditAccount::CreditAccount(const int customerID) : Account(customerID) {
	// TODO implement
}

bool CreditAccount::withdrawMoney(Money amount) {

	//Checks if withdrawal is possible before actually moving money
	if (checkWithdrawMoney(amount)) {
		this->Balance->subtract(amount);
		return true;
	}
	else {
		return false;
	}
	
}

bool CreditAccount::checkWithdrawMoney(Money amount) {

	//returns true if the withdrawal is possible
	if (amount.asCents() > -1) {
		return true;
	}
	else {
		return false;
	}
}

bool CreditAccount::depositMoney(Money amount) {

	//Positive balance cannnot be greater than 5000 dollars
	if (checkDepositMoney(amount)) {
		this->Balance->add(amount);
		return true;
	}
	else {
		return false;
	}

}

bool CreditAccount::checkDepositMoney(Money amount) {
	//Checks if the amount deposited is valid for the credit account
	if ((((amount.asCents()) + (Balance->asCents())) < 500001) && (amount.asCents() > -1)) {
		return true;
	}
	else {
		return false;
	}
}
CreditAccount::~CreditAccount() {
	// TODO implement
}
