#include "VehicleLoan.h"
#include <cmath>

VehicleLoan::VehicleLoan(
    double amount,
    double interestRate,
    int years
) : Loan(amount, interestRate, years)
{
}

double VehicleLoan::calculateEMI()
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

string VehicleLoan::getLoanType()
{
    return "Vehicle Loan";
}