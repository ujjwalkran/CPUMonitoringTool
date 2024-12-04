#ifndef CPU_MONITOR_H
#define CPU_MONITOR_H

struct CPUStats {
    long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

    long total() const;
    long idleTime() const;
};

CPUStats getCPUStats();
double calculateCPUUsage(const CPUStats& prev, const CPUStats& curr);

#endif // CPU_MONITOR_H
