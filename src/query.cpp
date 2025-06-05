#include "query.h"

query::query(){

  cmd_map["SET"] = [](data& d, const std::vector<std::string>& args) {
    d.setFunc(args);
  };
  cmd_map["GET"] = [](data& d, const std::vector<std::string>& args) {
      d.getFunc(args);
  };
  cmd_map["DEL"] = [](data& d, const std::vector<std::string>& args) {
    d.delFunc(args);
  };

};
query::~query() = default;

void query::read(){
  std::getline(std::cin, content);
}

const std::string& query::getContent() const {
  return content;
}

const std::vector<std::string>& query::getParsed() const {
  return parsed_rqt;
}

std::vector<std::string> query::parsing_str(){
  parsed_rqt.clear();
  std::istringstream iss(content);
  std::string rqt_word;

  while(iss >> rqt_word){
    parsed_rqt.push_back(rqt_word);
  }
  return parsed_rqt;
}

int query::handle_query(data& d){
  if(cmd_map.contains(parsed_rqt[0])){
    cmd_map[parsed_rqt[0]](d, parsed_rqt);
    return 1;
  }
  else{
    std::cout << "Unknown command : " << parsed_rqt[0];
    return 2;
  }
}
