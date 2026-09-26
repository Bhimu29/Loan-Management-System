#include <iostream>
#include "Customer.h"
#include "LoanApplication.h"

using namespace std;

int main()
{
    Customer customer(
        "Rahul Sharma",
        "9876543210",
        "rahul@gmail.com",
        "Andheri, Mumbai"
    );

    LoanApplication application(
        1001,
        customer,
        "Home Loan",
        3000000,
        20,
        25093.20
    );

    cout << "LOAN APPLICATION" << endl;
    cout << "------------------------" << endl;

    cout << "Application ID: "
         << application.getApplicationId()
         << endl;

    cout << "Customer Name: "
         << application.getCustomer().getName()
         << endl;

    cout << "Mobile: "
         << application.getCustomer().getMobile()
         << endl;

    cout << "Loan Type: "
         << application.getLoanType()
         << endl;

    cout << "Loan Amount: ₹"
         << application.getAmount()
         << endl;

    cout << "Tenure: "
         << application.getYears()
         << " years"
         << endl;

    cout << "EMI: ₹"
         << application.getEMI()
         << endl;

    cout << "Status: "
         << application.getStatus()
         << endl;

    return 0;
}