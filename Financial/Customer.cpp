#include "Customer.hpp"
#include <string>
using namespace std;

int Customer::nextCustID = 0;

Customer::Customer(const std::string &name) {
	this->name = name;
	this->id = nextCustID;
	nextCustID++;
}

std::string Customer::getName() const {
	return this->name;
}

int Customer::getID() const {
	return this->id;
}

Customer::~Customer() {
	// TODO implement
}

