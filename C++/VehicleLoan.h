#ifndef VEHICLELOAN_H
#define VEHICLELOAN_H

#include "Loan.h"

class VehicleLoan : public Loan
{
public:

    VehicleLoan(
        double amount,
        double interestRate,
        int years
    );

    double calculateEMI() override;

    string getLoanType() override;
};

#endif