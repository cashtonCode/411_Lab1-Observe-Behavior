/*Cashton Christensen
* 1/7/2019
* Lab 01
* You are asked to write a C++ program to read and report some of the data you explored.
*/
#include <iostream>
#include <fstream>
int main()
{
//Open the file for CPU hostname
std::ifstream thisProcFile;
std::cout << "\n1) CPU hostname:\n";
thisProcFile.open ("/proc/sys/kernel/hostname", std::ios::in);
// Read the file. Note this file only has the host name in it
std::string line;
getline(thisProcFile, line);
std::cout << line << std::endl << std::endl;
thisProcFile.close();



//Open the file for the number of processing units on the machine
std::cout << "2) Number of Processing Units:\n";
system("grep -c ^processor /proc/cpuinfo");
std::cout << std::endl;



//Open the file for the CPU Vendor and Model for each processor
std::cout << "3) CPU Vendor and Model for each processor:\n";
system("awk '/model name/ {print}' /proc/cpuinfo");
std::cout << std::endl;



//Open the file for the Kernel version
std::cout << "4) The Version of Linux:\n";
thisProcFile.open ("/proc/version", std::ios::in);
getline(thisProcFile, line);
std::cout << line << std::endl << std::endl;
thisProcFile.close();



//Open the file for the amount of time since the system was last booted. How long in hh/mm/ss has it been since the system was last booted?
std::cout << "5) The amount of time since the system was last booted in seconds:\n";
thisProcFile.open ("/proc/uptime", std::ios::in);
getline(thisProcFile, line);
std::cout << line << std::endl << std::endl;
thisProcFile.close();

std::cout << "   The amount of time since the system was last booted in hh/mm/ss:\n";
system("awk '{print int($1/3600)\":\"int(($1%3600)/60)\":\"int($1%60)}' /proc/uptime");
std::cout << std::endl;



//Open the file for the amount of memory configured into this computer and the memory currently available
std::cout << "6) The amount of memory configured into this computer and the memory currently available:\n";
thisProcFile.open ("/proc/meminfo", std::ios::in);
getline(thisProcFile, line);
std::cout << line << std::endl;
getline(thisProcFile, line);
std::cout << line << std::endl;
getline(thisProcFile, line);
std::cout << line << std::endl << std:: endl;
thisProcFile.close();
}
