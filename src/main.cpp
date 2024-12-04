#include "cpu_monitor.h"
#include "memory_monitor.h"
#include "logger.h"
#include <iostream>
#include <thread>
#include <chrono>

void monitorResources(const std::string& logFile) {
    std::cout << "Log file path: " << logFile << std::endl;  // Print the file path
    Logger logger(logFile);

    CPUStats prevCPUStats = getCPUStats();
    int count = 0; //puttint count for debugging purpose

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // CPU Usage
        CPUStats currCPUStats = getCPUStats();
        double cpuUsage = calculateCPUUsage(prevCPUStats, currCPUStats);
        prevCPUStats = currCPUStats;

        // Memory Usage
        MemoryStats memStats = getMemoryStats();
        double memoryUsage = calculateMemoryUsage(memStats);

        // Log and Display
        std::string logMessage = "CPU Usage: " + std::to_string(cpuUsage) + "%, "
                                + "Memory Usage: " + std::to_string(memoryUsage) + "%";
        logger.log(logMessage);
        std::cout << logMessage << "\n";

        std::cout << "Logged message successfully\n";  // Debug line to check if the loop is working
        count++; 
    }
}

int main() {
    std::cout << "Starting Resource Monitor...\n";
    monitorResources("../backend/logs/resource_log.txt");
    return 0;
}
