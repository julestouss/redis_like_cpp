#include "log.h"

std::ofstream log::logfile;
time_t log::timestamp;

void log::open(){
  logfile.open("./log/rlc.log", std::ios::app);
}

void log::close(){
  logfile.close();
}

void log::write(std::string query){
  if(logfile.is_open()){
    time(&timestamp);
    std::string timestr = ctime(&timestamp);
    timestr.erase(timestr.find_last_not_of("\n\r") + 1);
    logfile << timestr << " :: " << query << "\n";
    logfile.flush();
  }
  else {
    std::cout << "Log file not open" << std::endl;
  }
}
