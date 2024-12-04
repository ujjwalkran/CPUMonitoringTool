#!/bin/bash
mkdir -p logs
../build/resource_monitor &
echo "Resource monitor started. Logs saved to logs/resource_log.txt"
