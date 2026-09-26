#include <iostream>
#include <iomanip>

#include "Customer.h"
#include "PersonalLoan.h"
#include "EducationLoan.h"
#include "HomeLoan.h"
#include "VehicleLoan.h"

using namespace std;

int main()
{
    int choice;

    double amount;
    double interestRate;
    int years;

    string name;
    string mobile;
    string email;
    string address;

    Loan* loan = nullptr;


    // ========================================
    // CUSTOMER DETAILS
    // ========================================

    cout << "========================================" << endl;
    cout << "       LOAN MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;

    cout << endl;

    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter Mobile Number: ";
    getline(cin, mobile);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter Address: ";
    getline(cin, address);


    // Create Customer object

    Customer customer(
        1,
        name,
        mobile,
        email,
        address
    );


    // ========================================
    // LOAN TYPE
    // ========================================

    cout << endl;

    cout << "========================================" << endl;
    cout << "           SELECT LOAN TYPE" << endl;
    cout << "========================================" << endl;

    cout << "1. Personal Loan" << endl;
    cout << "2. Education Loan" << endl;
    cout << "3. Home Loan" << endl;
    cout << "4. Vehicle Loan" << endl;

    cout << endl;

    cout << "Enter your choice: ";
    cin >> choice;


    // ========================================
    // LOAN DETAILS
    // ========================================

    cout << endl;

    cout << "Enter Loan Amount: Rs. ";
    cin >> amount;

    cout << "Enter Interest Rate (%): ";
    cin >> interestRate;

    cout << "Enter Loan Tenure (Years): ";
    cin >> years;


    // ========================================
    // CREATE LOAN OBJECT
    // ========================================

    switch (choice)
    {
        case 1:

            loan = new PersonalLoan(
                amount,
                interestRate,
                years
            );

            break;


        case 2:

            loan = new EducationLoan(
                amount,
                interestRate,
                years
            );

            break;


        case 3:

            loan = new HomeLoan(
                amount,
                interestRate,
                years
            );

            break;


        case 4:

            loan = new VehicleLoan(
                amount,
                interestRate,
                years
            );

            break;


        default:

            cout << "Invalid loan choice!" << endl;

            return 0;
    }


    // ========================================
    // DISPLAY APPLICATION
    // ========================================

    cout << endl;

    cout << "========================================" << endl;
    cout << "          LOAN APPLICATION" << endl;
    cout << "========================================" << endl;


    cout << "Customer Name : "
         << customer.getName()
         << endl;


    cout << "Mobile Number : "
         << customer.getMobile()
         << endl;


    cout << "Email         : "
         << customer.getEmail()
         << endl;


    cout << "Address       : "
         << customer.getAddress()
         << endl;


    cout << endl;


    cout << "Loan Type     : "
         << loan->getLoanType()
         << endl;


    cout << "Loan Amount   : Rs. "
         << amount
         << endl;


    cout << "Interest Rate : "
         << interestRate
         << "%"
         << endl;


    cout << "Tenure        : "
         << years
         << " years"
         << endl;


    cout << fixed << setprecision(2);


    cout << "Monthly EMI   : Rs. "
         << loan->calculateEMI()
         << endl;


    cout << "Status        : Pending"
         << endl;


    cout << "========================================" << endl;


    delete loan;

    return 0;
}