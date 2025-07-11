// File: src/main.cpp
#include <iostream>
#include <string>
#include <vector>
#include "utils/logger.h"
#include "utils/config.h"
#include "math/calculator.h"

int main(int argc, char* argv[]) {
    Logger logger("SandboxApp");
    logger.info("Starting Docker Sandbox Application");

    Config config;
    config.loadFromEnvironment();

    logger.info("Application Name: " + config.getAppName());
    logger.info("Version: " + config.getVersion());
    logger.info("Environment: " + config.getEnvironment());

    Calculator calc;

    // Perform some sample calculations
    std::vector<std::pair<double, double>> testCases = {
        {10.0, 5.0},
        {25.0, 4.0},
        {100.0, 10.0},
        {3.14159, 2.0}
    };

    logger.info("Performing mathematical operations:");

    for (const auto& testCase : testCases) {
        double a = testCase.first;
        double b = testCase.second;

        logger.info("Testing with a=" + std::to_string(a) + ", b=" + std::to_string(b));
        logger.info("  Add: " + std::to_string(calc.add(a, b)));
        logger.info("  Subtract: " + std::to_string(calc.subtract(a, b)));
        logger.info("  Multiply: " + std::to_string(calc.multiply(a, b)));

        if (b != 0) {
            logger.info("  Divide: " + std::to_string(calc.divide(a, b)));
        } else {
            logger.warning("  Division by zero skipped");
        }

        logger.info("  Power: " + std::to_string(calc.power(a, b)));
        logger.info("---");
    }

    logger.info("Application completed successfully");
    return 0;
}
