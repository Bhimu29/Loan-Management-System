#include <iostream>
#include "Customer.h"

using namespace std;

int main()
{
    Customer customer(
        "Rahul Sharma",
        "9876543210",
        "rahul@gmail.com",
        "Andheri, Mumbai"
    );

    cout << "Customer Details" << endl;
    cout << "------------------------" << endl;

    cout << "Name: "
         << customer.getName()
         << endl;

    cout << "Mobile: "
         << customer.getMobile()
         << endl;

    cout << "Email: "
         << customer.getEmail()
         << endl;

    cout << "Address: "
         << customer.getAddress()
         << endl;

    return 0;
}