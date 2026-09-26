#include <iostream>
#include <string>
#include <cstdlib>
#include<iomanip>

#include "Customer.h"
#include "LoanApplication.h"

#include "Loan.h"
#include "PersonalLoan.h"
#include "EducationLoan.h"
#include "HomeLoan.h"
#include "VehicleLoan.h"

using namespace std;

int main(int argc, char* argv[])
{
    // ==========================================
    // LOAN APPLICATION MODE
    // ==========================================

    if (argc == 11 && string(argv[1]) == "apply")
    {
        int applicationId = atoi(argv[2]);

        string name = argv[3];
        string mobile = argv[4];
        string email = argv[5];
        string address = argv[6];

        string loanType = argv[7];

        double amount = atof(argv[8]);
        double interestRate = atof(argv[9]);
        int years = atoi(argv[10]);


        // Create Customer object

        Customer customer(
            name,
            mobile,
            email,
            address
        );


        // Create Loan object

        Loan* loan = nullptr;


        if (loanType == "personal")
        {
            loan = new PersonalLoan(
                amount,
                interestRate,
                years
            );
        }
        else if (loanType == "education")
        {
            loan = new EducationLoan(
                amount,
                interestRate,
                years
            );
        }
        else if (loanType == "home")
        {
            loan = new HomeLoan(
                amount,
                interestRate,
                years
            );
        }
        else if (loanType == "vehicle")
        {
            loan = new VehicleLoan(
                amount,
                interestRate,
                years
            );
        }
        else
        {
            cout << "Invalid loan type";
            return 1;
        }


        // Calculate EMI

        double emi = loan->calculateEMI();


        // Create LoanApplication object

        LoanApplication application(
            applicationId,
            customer,
            loanType,
            amount,
            years,
            emi
        );


        // Display application

        cout << "APPLICATION" << endl;

        cout << "ID:"
             << application.getApplicationId()
             << endl;

        cout << "NAME:"
             << application.getCustomer().getName()
             << endl;

        cout << "MOBILE:"
             << application.getCustomer().getMobile()
             << endl;

        cout << "EMAIL:"
             << application.getCustomer().getEmail()
             << endl;

        cout << "ADDRESS:"
             << application.getCustomer().getAddress()
             << endl;

        cout << "LOAN:"
             << application.getLoanType()
             << endl;

       cout << "AMOUNT:₹"
     << fixed
     << setprecision(0)
     << application.getAmount()
     << endl;
     
        cout << "YEARS:"
             << application.getYears()
             << endl;

        cout << "EMI:"
             << application.getEMI()
             << endl;

        cout << "STATUS:"
             << application.getStatus()
             << endl;


        delete loan;

        return 0;
    }


    // ==========================================
    // NORMAL EMI CALCULATION MODE
    // ==========================================

    if (argc >= 5)
    {
        string loanType = argv[1];

        double amount = atof(argv[2]);

        double interestRate = atof(argv[3]);

        int years = atoi(argv[4]);


        Loan* loan = nullptr;


        if (loanType == "personal")
        {
            loan = new PersonalLoan(
                amount,
                interestRate,
                years
            );
        }
        else if (loanType == "education")
        {
            loan = new EducationLoan(
                amount,
                interestRate,
                years
            );
        }
        else if (loanType == "home")
        {
            loan = new HomeLoan(
                amount,
                interestRate,
                years
            );
        }
        else if (loanType == "vehicle")
        {
            loan = new VehicleLoan(
                amount,
                interestRate,
                years
            );
        }
        else
        {
            cout << "Invalid loan type";
            return 1;
        }


        // Calculate EMI

        double emi = loan->calculateEMI();

        cout << emi;


        delete loan;

        return 0;
    }


    // ==========================================
    // INVALID INPUT
    // ==========================================

    cout << "Invalid input";

    return 1;
}