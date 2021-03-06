#include "processor.h"

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() { 
    std::vector<std::string> system_state_1 = LinuxParser::CpuUtilization();
    float activeTime_1 = LinuxParser::ActiveJiffies(system_state_1);
    float idleTime_1 = LinuxParser::IdleJiffies(system_state_1);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));   

    std::vector<std::string> system_state_2 = LinuxParser::CpuUtilization();
    float activeTime_2 = LinuxParser::ActiveJiffies(system_state_2);
    float idleTime_2 = LinuxParser::IdleJiffies(system_state_2);

    float  activeTime  = activeTime_2 - activeTime_1;
    float  idleTime  = idleTime_2 - idleTime_1;
    float  totalTime = activeTime + idleTime;

    float  result = (activeTime / totalTime);
    return result;
}