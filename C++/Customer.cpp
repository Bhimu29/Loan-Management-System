#include "Customer.h"

Customer::Customer(
    const std::string& name,
    const std::string& mobile,
    const std::string& email,
    const std::string& address
)
{
    this->name = name;
    this->mobile = mobile;
    this->email = email;
    this->address = address;
}

std::string Customer::getName() const
{
    return name;
}

std::string Customer::getMobile() const
{
    return mobile;
}

std::string Customer::getEmail() const
{
    return email;
}

std::string Customer::getAddress() const
{
    return address;
}