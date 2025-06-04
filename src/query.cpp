#include "query.h"

query::query() = default;
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
