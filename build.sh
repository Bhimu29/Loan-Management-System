#!/bin/bash

echo "========================================"
echo "Building C++ Loan Management API"
echo "========================================"

g++ "C++/api.cpp" \
"C++/Loan.cpp" \
"C++/PersonalLoan.cpp" \
"C++/EducationLoan.cpp" \
"C++/HomeLoan.cpp" \
"C++/VehicleLoan.cpp" \
"C++/Customer.cpp" \
"C++/LoanApplication.cpp" \
-o "C++/api"

echo "========================================"
echo "C++ API compiled successfully"
echo "========================================"

npm install

echo "========================================"
echo "Build completed"
echo "========================================"