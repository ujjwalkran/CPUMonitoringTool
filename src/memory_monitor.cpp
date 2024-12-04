#include "memory_monitor.h"
#include <fstream>
#include <string>

MemoryStats getMemoryStats() {
    std::ifstream file("/proc/meminfo");
    std::string line;
    MemoryStats stats = {};

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.find("MemTotal") == 0) {
                stats.totalMemory = std::stol(line.substr(line.find_first_of("0123456789")));
            } else if (line.find("MemFree") == 0) {
                stats.freeMemory = std::stol(line.substr(line.find_first_of("0123456789")));
            }
        }
    }
    return stats;
}

double calculateMemoryUsage(const MemoryStats& stats) {
    return 100.0 * (stats.totalMemory - stats.freeMemory) / stats.totalMemory;
}
