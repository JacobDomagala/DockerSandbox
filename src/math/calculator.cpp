#include "calculator.hpp"
#include <cmath>

double Calculator::add(double a, double b) const {
    return a + b;
}

double Calculator::subtract(double a, double b) const {
    return a - b;
}

double Calculator::multiply(double a, double b) const {
    return a * b;
}

double Calculator::divide(double a, double b) const {
    if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

double Calculator::power(double base, double exponent) const {
    return std::pow(base, exponent);
}

double Calculator::sqrt(double value) const {
    if (value < 0) {
        throw std::runtime_error("Cannot calculate square root of negative number");
    }
    return std::sqrt(value);
}

double Calculator::factorial(int n) const {
    if (n < 0) {
        throw std::runtime_error("Factorial of negative number is undefined");
    }
    if (n == 0 || n == 1) {
        return 1;
    }

    double result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
