#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
private:
    std::string name;
    std::string mobile;
    std::string email;
    std::string address;

public:
    Customer(
        const std::string& name,
        const std::string& mobile,
        const std::string& email,
        const std::string& address
    );

    std::string getName() const;
    std::string getMobile() const;
    std::string getEmail() const;
    std::string getAddress() const;
};

#endif