#include "PersonalLoan.h"
#include <cmath>

PersonalLoan::PersonalLoan(
    double amount,
    double interestRate,
    int years
) : Loan(amount, interestRate, years)
{
}

double PersonalLoan::calculateEMI()
{
    double monthlyRate = interestRate / 12 / 100;

    int months = years * 12;

    if (monthlyRate == 0)
    {
        return amount / months;
    }

    double emi =
        amount *
        monthlyRate *
        pow(1 + monthlyRate, months)
        /
        (pow(1 + monthlyRate, months) - 1);

    return emi;
}

string PersonalLoan::getLoanType()
{
    return "Personal Loan";
}