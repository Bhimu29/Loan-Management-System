#include "LoanApplication.h"

LoanApplication::LoanApplication(
    int applicationId,
    Customer customer,
    std::string loanType,
    double amount,
    int years,
    double emi
)
    : applicationId(applicationId),
      customer(customer),
      loanType(loanType),
      amount(amount),
      years(years),
      emi(emi),
      status("Pending")
{
}

int LoanApplication::getApplicationId() const
{
    return applicationId;
}

Customer LoanApplication::getCustomer() const
{
    return customer;
}

std::string LoanApplication::getLoanType() const
{
    return loanType;
}

double LoanApplication::getAmount() const
{
    return amount;
}

int LoanApplication::getYears() const
{
    return years;
}

double LoanApplication::getEMI() const
{
    return emi;
}

std::string LoanApplication::getStatus() const
{
    return status;
}

void LoanApplication::setStatus(std::string status)
{
    this->status = status;
}