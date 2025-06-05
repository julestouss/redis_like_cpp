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

  if (std::all_of(value.begin(), value.end(), ::isdigit)) {
    data_map[key] = std::stoi(value); // Stocker un int
  }else {
    data_map[key] = value; // Stocker une string
  }
}
