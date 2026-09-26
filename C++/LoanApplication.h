#ifndef LOAN_APPLICATION_H
#define LOAN_APPLICATION_H

#include <string>
#include "Customer.h"

class LoanApplication
{
private:
    int applicationId;
    Customer customer;

    std::string loanType;
    double amount;
    int years;
    double emi;
    std::string status;

public:
    LoanApplication(
        int applicationId,
        Customer customer,
        std::string loanType,
        double amount,
        int years,
        double emi
    );

    int getApplicationId() const;
    Customer getCustomer() const;

    std::string getLoanType() const;
    double getAmount() const;
    int getYears() const;
    double getEMI() const;
    std::string getStatus() const;

    void setStatus(std::string status);
};

#endif