#include <iostream>
#include "query.h"

int main() {
    query input_usr{};
    while (true) {
      std::cout << ">> ";
      input_usr.read();
        
      if (input_usr.getContent() == "exit") {
          break;
      }
      input_usr.parsing_str();


      for(const auto& word : input_usr.getParsed()){
        std::cout << word << ", ";
      }
      std::cout << std::endl;
    }
    return 0;
}
