#pragma once
#include "constant.h"

class log {
private:
  log()=delete;
  static time_t timestamp;
  static std::ofstream logfile;

public:
  static void open();
  static void close();
  static void write(std::string query);
  
};
