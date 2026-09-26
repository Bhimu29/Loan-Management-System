#ifndef LOAN_H
#define LOAN_H

#include <string>
using namespace std;

class Loan
{
protected:
    double amount;
    double interestRate;
    int years;

public:

    Loan(double amount, double interestRate, int years);

    virtual double calculateEMI() = 0;

    virtual string getLoanType() = 0;

    virtual ~Loan();
};

#endif