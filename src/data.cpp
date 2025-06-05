#include "data.h"

data::data() = default;
data::~data() = default;

void data::setFunc(const std::vector<std::string>& query){
  if(query.size() < 3){
    std::cout << "Pas assez d'arguments" << std::endl;
    return;
  }
  const std::string& key = query[1];
  const std::string& value = query[2];
  const std::string& arg = query[3];
  
  if(!data_map.contains(key) || arg.compare("-u")==0 || arg.compare("--update")==0){
    if (std::all_of(value.begin(), value.end(), ::isdigit)) {
      data_map[key] = std::stoi(value);
    }else {
      data_map[key] = value;
    }
  } else{
    std::cout << "Key already existing, if you want to SET anyway use -u or --update";
  }
}

void data::getFunc(const std::vector<std::string>& query){
  if(query.size()<2){
    std::cout << "Pas assez d'arguments" << std::endl;
    return;
  }

  const std::string& key = query[1];

  if(data_map.contains(key)){
    std::visit([](auto&& arg) {
        std::cout << arg;
    }, data_map[key]);
  }
}

void data::delFunc(const std::vector<std::string>& query){
  if(query.size()<2){
    std::cout << "Pas assez d'arguments" << std::endl;
    return;
  }
  const std::string& key = query[1];

  if(data_map.contains(key)){
    data_map.erase(key);
  }
}

