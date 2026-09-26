#ifndef PERSONALLOAN_H
#define PERSONALLOAN_H

#include "Loan.h"

class PersonalLoan : public Loan
{
public:

    PersonalLoan(
        double amount,
        double interestRate,
        int years
    );

    double calculateEMI() override;

    string getLoanType() override;
};

#endif