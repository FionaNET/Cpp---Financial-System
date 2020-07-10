#include "FinancialServicesSystem.hpp"
#include <iostream>
#include <vector>

FinancialServicesSystem::FinancialServicesSystem() {
	
}

std::string FinancialServicesSystem::author(){
	return "flin697";
}

bool FinancialServicesSystem::addCustomer(Customer* customer) {

	//Verify customer returns true if the customer is found
	if (verifyCustomer(customer->getID())) {
		//If Customer ID is found in data base, cannot add customer and hence return false
		return false;
	}
	else {

		//Customer is not found and added to database
		this->ListofCustomers.push_back(customer);
		return true;
	}
}

bool FinancialServicesSystem::addAccount(Account* account) {

	//Only create an account is there is a customer with that ID in the database AND there is no account with that ID
	if (verifyCustomer(account->getCustomerID()) && !verifyAccount(account->getAccountID())) {

		//Account is not found and added to database
		this->ListofAccounts.push_back(account);
		return true;

	}else {

		//If Account ID is found in data base, cannot add account and hence return false
		return false;
	}

}

bool FinancialServicesSystem::addTransaction(Transaction* transaction) {

	//Only if the transaction is pending and both accounts in the system and transaction ID is not already there and customer exists
	if ((transaction->getState() == PENDING) && (verifyAccount(transaction->getFromAccount()->getAccountID())) && 
		(verifyAccount(transaction->getToAccount()->getAccountID())) && (!verifyTransaction(transaction->getID())) &&
		(verifyCustomer(transaction->getFromAccount()->getCustomerID())) && (verifyCustomer(transaction->getToAccount()->getCustomerID()))) {
		this->ListofTransactions.push_back(transaction);
		return true;

	}else {
		return false;
	}
	
}

std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {

	//Transactions Vector Storing in method
	std::vector<Transaction*> SuccessfulTransactions;

	//Set initial failure to store successful transactions later
	bool Success = false;

	//Storing results of pending transactions
	std::vector<Transaction*> PendingTransactions = getTransactions(PENDING);
	//Temporary storing transaction for ordering
	Transaction* TempTrans = 0;

	//Transactions should be ordered in terms of unique ID ascending

	for (unsigned j = 0; j < (PendingTransactions.size()) ; j++) {
		for (unsigned i = 0; i < (PendingTransactions.size() - 1 ); i++) {
			//If the ID of the transaction after the current is smaller, swap the transactions
			if ((PendingTransactions[i]->getID()) > (PendingTransactions[i + 1]->getID())) {
				//Temporarily store the transaction [i + 1]
				TempTrans = PendingTransactions[i + 1];
				//Replace Transaction [i] with [i+1] which is smaller in ID
				PendingTransactions[i + 1] = PendingTransactions[i];
				//Replace Transaction [i+1] with [i] which is larger in ID
				PendingTransactions[i] = TempTrans;
			}
		}
	}

	//Performing pending transactions
	for (unsigned i = 0; i < PendingTransactions.size(); i++) {
		Success = PendingTransactions[i]->performTransaction();
		if (Success) {
			//Puts successful transactions into the transaction vector list
			SuccessfulTransactions.push_back(PendingTransactions[i]);
		}
	}

	return SuccessfulTransactions;
}

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {

	//Customers Total Balance default set to 0
	Money CustomerBal = Money(0, 0);

	//Search through List of Accounts for customer ID
	for (unsigned i = 0; i < ListofAccounts.size(); i++) {

		//If the customerID linked to an account matches the customerID we are searching with
		if (ListofAccounts[i]->getCustomerID() == customerID) {

			//Depending on if the balance is negative or positive
			if (ListofAccounts[i]->getBalance().asCents() > 0) {

				//Customer balance is positive to we add to the net
				CustomerBal.add(ListofAccounts[i]->getBalance());

			}else if (ListofAccounts[i]->getBalance().asCents() < 0) {

				//Turning the dollars and cents into positive values
				int newDol = (ListofAccounts[i]->getBalance().getDollars()) * -1;
				int newCents = (ListofAccounts[i]->getBalance().getCents()) * -1;
				Money SubAm = Money(newDol, newCents);

				//Customer balance is negative therefore we subtract from net balance
				CustomerBal.subtract(SubAm);
			}
			
		}
	}

	return CustomerBal;
}

bool FinancialServicesSystem::verifyCustomer(int customerID) const {
	
	//Variable to change if the customer is found (Originally not existing in system) -False if customer is not in system
	bool isCustIn = false;
	int ID = 0;

	//Check if customer is already in the system
	//If it is the first customer in the system, it will not enter the for loop as List of Customers size will start at 0
	if (ListofCustomers.size() != 0) {
		for (unsigned i = 0; (i < ListofCustomers.size()); i++) {

			ID = ListofCustomers[i]->getID();

			if (customerID == ID) {
				//Customer is found as the 'i'th value in List of Customers
				isCustIn = true;

				//Break if the customer is found at all 
				break;
			}
		}
	}
	return isCustIn;
}

bool FinancialServicesSystem::verifyAccount(int accountID) const {

	//Variable to change if the account is found (Originally not existing in system) - False if account is not in system
	bool isAccIn = false;

	//AccountID in the ListofAccounts
	int ID = 0;

	//Check if the account is already in the system
	//If it is the first account in the system, it will not enter the for loop as List of Accounts size will start at 0
	if (ListofAccounts.size() != 0) {
		for (unsigned i = 0; (i < ListofAccounts.size()); i++) {

			ID = ListofAccounts[i]->getAccountID();

			if (accountID == ID) {
				//Account is found as the 'i'th value in List of Account
				isAccIn = true;

				//Break if the account is found at all 
				break;
			}
		}
	}
	return isAccIn;
}

bool FinancialServicesSystem::verifyTransaction(int transactionID) const {

	//By default the transaction should not be in the system- hence set as false
	bool isTransIn = false;
	int ID = 0;

	//If it is the first account in the system, it will not enter the for loop as List of Transactions size will start at 0
	if (ListofTransactions.size() != 0) {
		for (unsigned i = 0; (i < ListofTransactions.size()); i++) {

			ID = ListofTransactions[i]->getID();

			if (transactionID == ID) {
				//Transaction is found as the 'i'th value in List of Transaction
				isTransIn = true;

				//Break if the transaction is found at all 
				break;
			}
		}
	}
	return isTransIn;
}

std::vector<Account*> FinancialServicesSystem::getAccounts() const {
	return ListofAccounts;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	return ListofCustomers;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	return ListofTransactions;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {

	//New vector storing the transactions of a specified state
	std::vector<Transaction*> ListofTransactionsSTATE;

	//Similar to a search function, it goes through all the ListofTransactions and finds those whose states match the parameter
	for (unsigned i = 0; i < ListofTransactions.size(); i++) {
		if ((ListofTransactions[i]->getState()) == state) {

			//Add the transaction of that state to the new vector list
			ListofTransactionsSTATE.push_back(ListofTransactions[i]);

		}
	}
	
	return ListofTransactionsSTATE;
}

FinancialServicesSystem::~FinancialServicesSystem() {
	// TODO implement
}

