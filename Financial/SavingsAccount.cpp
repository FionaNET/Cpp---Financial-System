#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(const int customerID) : Account(customerID) {
	NumofDep = 0;
	
}

bool SavingsAccount::withdrawMoney(Money amount) {	

	//Checks withdrawal is possible first
	if (checkWithdrawMoney(amount)) {
		
		this->Balance->subtract(amount);

		//The bonus value will be decreased by two dollars for each successful withdrawal
		if ((this->BonusAm)->asCents() > 199) {
			(this->BonusAm)->subtractDollars(2);
		}

		//Withdrawal successful
		return true;
	}else {
		//Withdrawal false
		return false;
	}
		
}

bool SavingsAccount::checkWithdrawMoney(Money amount) {

	//returns true if the withdraw is possible accounting for the actual amount
	int SavAfter = this->Balance->asCents() - amount.asCents();

	if ((SavAfter > -1) && (amount.asCents() > -1)) {
		return true;
	}
	else {
		return false;
	}

}

bool SavingsAccount::depositMoney(Money amount) {

	//Amount may include 0 dollars
	if (checkDepositMoney(amount)) {
		
		//Counts the times deposited 
		NumofDep++;

		//Add the money into the account
		this->Balance->add(amount);

		//Every second deposit, add the bonus amount
		if ((NumofDep != 0) && (NumofDep%2 == 0)) {
			this->Balance->addDollars(BonusAm->getDollars());
		}
		//Deposit successful
		
		return true;		

	}else {
		//Deposit failed
		return false;
	}
	
}

bool SavingsAccount::checkDepositMoney(Money amount) {
	//Checks the deposited amount is 0 dollars or greater
	if (amount.asCents() > -1) {
		return true;
	}
	else {
		return false;
	}
}

Money SavingsAccount::getBonusValue() const {
	return *this->BonusAm;
}

SavingsAccount::~SavingsAccount() {
	delete BonusAm;
}


