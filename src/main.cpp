#include <iostream>
#include <string>
#include "query.h"
#include "data.h"

int main() {
  query input_usr{};
  data data_1{};
  while (true) {
    std::cout << ">> ";
    input_usr.read();
      
    if (input_usr.getContent() == "exit") {
        break;
    }
    input_usr.parsing_str();
    const auto& parsed_query = input_usr.getParsed();


    if(!parsed_query.empty() && parsed_query[0].compare("SET") == 0){
      data_1.setFunc(parsed_query);
    }
    std::cout << std::endl;
  }
  return 0;
}
