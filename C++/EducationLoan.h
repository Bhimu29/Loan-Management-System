#ifndef EDUCATIONLOAN_H
#define EDUCATIONLOAN_H

#include "Loan.h"

class EducationLoan : public Loan
{
public:

    EducationLoan(
        double amount,
        double interestRate,
        int years
    );

    double calculateEMI() override;

    string getLoanType() override;
};

#endif