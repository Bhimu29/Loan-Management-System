#include "Loan.h"

Loan::Loan(double amount, double interestRate, int years)
{
    this->amount = amount;
    this->interestRate = interestRate;
    this->years = years;
}

Loan::~Loan()
{
}