#include "cpu_monitor.h"
#include <fstream>
#include <sstream>
#include <string>

long CPUStats::total() const {
    return user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;
}

long CPUStats::idleTime() const {
    return idle + iowait;
}

CPUStats getCPUStats() {
    std::ifstream file("/proc/stat");
    std::string line;
    CPUStats stats = {};

    if (file.is_open() && std::getline(file, line)) {
        std::istringstream ss(line);
        std::string cpu;
        ss >> cpu; // Skip "cpu"
        ss >> stats.user >> stats.nice >> stats.system >> stats.idle >> stats.iowait 
           >> stats.irq >> stats.softirq >> stats.steal >> stats.guest >> stats.guest_nice;
    }
    return stats;
}

double calculateCPUUsage(const CPUStats& prev, const CPUStats& curr) {
    long totalDiff = curr.total() - prev.total();
    long idleDiff = curr.idleTime() - prev.idleTime();
    return 100.0 * (totalDiff - idleDiff) / totalDiff;
}
