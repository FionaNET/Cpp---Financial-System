#include <string>
#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_
using namespace std;

class Customer {
private:
	string name;
	int id;
	Customer& operator=(const Customer &other);
    Customer(const Customer &other);
	static int nextCustID;

public:
	Customer(const std::string &name);
	std::string getName() const;
	int getID() const;
	virtual ~Customer();
};

#endif /* CUSTOMER_HPP_ */
