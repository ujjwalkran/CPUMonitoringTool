#ifndef MEMORY_MONITOR_H
#define MEMORY_MONITOR_H

struct MemoryStats {
    long totalMemory;
    long freeMemory;
};

MemoryStats getMemoryStats();
double calculateMemoryUsage(const MemoryStats& stats);

#endif // MEMORY_MONITOR_H
