#include "logger.h"
#include <fstream>
#include <iostream>

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Error: Unable to open log file: " << filename << "\n";
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// void Logger::log(const std::string& message) {
//     if (logFile.is_open()) {
//         logFile << message << "\n";
//     }
// }

void Logger::log(const std::string& message) {
    if (logFile.is_open()) {
        std::cout << "Logging message: " << message << std::endl; // Debug log
        logFile << message << "\n";
        logFile.flush();
    } else {
        std::cerr << "Error: Log file not open. Cannot write log." << std::endl;
    }
}
