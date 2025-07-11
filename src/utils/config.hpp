#pragma once
#include <string>
#include <map>

class Config {
private:
    std::string m_appName;
    std::string m_version;
    std::string m_environment;
    int m_port;
    std::string getEnvVar(const std::string& name, const std::string& defaultValue = "") const;

public:
    Config();
    void loadFromEnvironment();

    const std::string& getAppName() const { return m_appName; }
    const std::string& getVersion() const { return m_version; }
    const std::string& getEnvironment() const { return m_environment; }
    int getPort() const { return m_port; }
};
