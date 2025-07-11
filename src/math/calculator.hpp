#pragma once
#include <stdexcept>

class Calculator {
public:
    double add(double a, double b) const;
    double subtract(double a, double b) const;
    double multiply(double a, double b) const;
    double divide(double a, double b) const;
    double power(double base, double exponent) const;
    double sqrt(double value) const;
    double factorial(int n) const;
};
