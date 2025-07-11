#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

class Logger {
private:
    std::string m_name;
    std::string getCurrentTimestamp() const;

public:
    explicit Logger(const std::string& name);
    void info(const std::string& message) const;
    void warning(const std::string& message) const;
    void error(const std::string& message) const;
    void debug(const std::string& message) const;
};
