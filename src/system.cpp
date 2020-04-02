#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"

#include <bits/stdc++.h>
#include <algorithm>
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// DONE: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// ADD: Sorting processes according to CPU usage
vector<int> System::Sort_pid(vector<int> pids) {
  std::map<int, int, std::greater<int> > pidmap;
  std::vector<int> sorted_pid;
  
  int pids_size = pids.size();
  for (auto i = 0; i < pids_size; i++) {
    pidmap.insert(std::make_pair(LinuxParser::ActiveJiffies(pids[i]), pids[i]));
  }

  std::map<int, int>::iterator it;
  for (it = pidmap.begin(); it != pidmap.end(); it++) {
    sorted_pid.push_back((*it).second);
  }

  return sorted_pid;
}

// DONE: Return a container composed of the system's processes
vector<Process>& System::Processes() {
  vector<int> pids = LinuxParser::Pids();
  int pids_size = pids.size();
  vector<int> aux_sort;

  for (auto i = 0; i < pids_size; i++) {
    aux_sort.push_back(pids[i]);
  }

  vector<int> aux_sorted = System::Sort_pid(aux_sort);
  int aux_size = aux_sorted.size();
  for (auto j = 0; j < aux_size; j++) {
    processes_.push_back(aux_sorted[j]);
  }

  return processes_;
}

// DONE: Return the system's kernel identifier (string)
std::string System::Kernel() {
  std::string os_kernel;
  os_kernel = LinuxParser::Kernel();

  return os_kernel;
}

// DONE: Return the system's memory utilization
float System::MemoryUtilization() {
  float mem_utilization;
  mem_utilization = LinuxParser::MemoryUtilization();

  return mem_utilization;
}

// DONE: Return the operating system name
std::string System::OperatingSystem() {
  std::string os_name;
  os_name = LinuxParser::OperatingSystem();

  return os_name;
}

// DONE: Return the number of processes actively running on the system
int System::RunningProcesses() {
  int number_of_running_proc;
  number_of_running_proc = LinuxParser::RunningProcesses();

  return number_of_running_proc;
}

// DONE: Return the total number of processes on the system
int System::TotalProcesses() {
  int total_number_of_proc;
  total_number_of_proc = LinuxParser::TotalProcesses();

  return total_number_of_proc;
}

// DONE: Return the number of seconds since the system started running
int long System::UpTime() { return LinuxParser::UpTime(); }