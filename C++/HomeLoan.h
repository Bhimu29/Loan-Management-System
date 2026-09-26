#ifndef HOMELOAN_H
#define HOMELOAN_H

#include "Loan.h"

class HomeLoan : public Loan
{
public:

    HomeLoan(
        double amount,
        double interestRate,
        int years
    );

    double calculateEMI() override;

    string getLoanType() override;
};

#endif