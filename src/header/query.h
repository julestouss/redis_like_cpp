#pragma once
#include "constant.h"


//declaration anticipé de data
class data;

class query {
private:
  std::string content;
  std::vector<std::string> parsed_rqt;
  std::unordered_map<std::string, std::function<void(data& d, const std::vector<std::string>& arg)>> cmd_map;

public:
  query();
  ~query();

  void read();

  const std::string& getContent() const;
  const std::vector<std::string>& getParsed() const;
  std::vector<std::string> parsing_str();
  
  void handle_query(data& d);
};
