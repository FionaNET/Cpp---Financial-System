#include "ChequeAccount.hpp"
//TODO Implement ChequeAccount class

ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {

	
	
}

bool ChequeAccount::withdrawMoney(Money amount) {

	if (checkWithdrawMoney(amount)) {
		//Decrease balance
		this->Balance->subtract(amount);
		this->Balance->subtract(*TransFee);

		//Increase transaction fee
		TransFee->addDollars(1);

		return true;

	}else {
		return false;
	}
	
}

bool ChequeAccount::checkWithdrawMoney(Money amount) {

	//returns true if the withdraw is possible accounting for the transaction fee and actual amount
	int TotalAmount = (TransFee->asCents()) + (amount.asCents());

	if ((TotalAmount <= Balance->asCents()) && (amount.asCents() > -1)) {
		return true;
	}else {
		return false;
	}

}

bool ChequeAccount::depositMoney(Money amount) {

	//money deposited into account must be less than or equal to 3000 dollars (or 300000 cents)
	if (checkDepositMoney(amount)) {
		this->Balance->add(amount);
		return true;
	}
	else {
		return false;
	}
}

bool ChequeAccount::checkDepositMoney(Money amount) {

	//Checks amount deposited is valid for the cheque account
	if ((amount.asCents() > -1) && (amount.asCents() < 300001)) {
		return true;
	}
	else {
		return false;
	}
}
Money* ChequeAccount::getTransactionFee() const {
	return TransFee;
}

ChequeAccount::~ChequeAccount() {
	delete TransFee;
}

