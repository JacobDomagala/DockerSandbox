#include "config.hpp"
#include <cstdlib>

Config::Config() : m_appName("DockerSandbox"), m_version("1.0.0"), m_environment("development"), m_port(8080) {}

std::string Config::getEnvVar(const std::string& name, const std::string& defaultValue) const {
    const char* value = std::getenv(name.c_str());
    return value ? std::string(value) : defaultValue;
}

void Config::loadFromEnvironment() {
    m_appName = getEnvVar("APP_NAME", "DockerSandbox");
    m_version = getEnvVar("APP_VERSION", "1.0.0");
    m_environment = getEnvVar("APP_ENV", "development");

    std::string portStr = getEnvVar("APP_PORT", "8080");
    try {
        m_port = std::stoi(portStr);
    } catch (const std::exception&) {
        m_port = 8080;
    }
}
