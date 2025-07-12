#include "logger.hpp"

Logger::Logger(const std::string& name) : m_name(name) {}

std::string Logger::getCurrentTimestamp() const {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void Logger::info(const std::string& message) const {
    std::cout << "[" << getCurrentTimestamp() << "] [INFO] [" << m_name << "] " << message << std::endl;
}

void Logger::warning(const std::string& message) const {
    std::cout << "[" << getCurrentTimestamp() << "] [WARN] [" << m_name << "] " << message << std::endl;
}

void Logger::error(const std::string& message) const {
    std::cerr << "[" << getCurrentTimestamp() << "] [ERRORR] [" << m_name << "] " << message << std::endl;
}

void Logger::debug(const std::string& message) const {
    std::cout << "[" << getCurrentTimestamp() << "] [DEBUG] [" << m_name << "] " << message << std::endl;
}
