#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

std::vector<std::string> parsing_str(std::string& message){
  std::vector<std::string> parsed_rqt;

    std::istringstream iss(message);
    std::string rqt_word;

    while(iss >> rqt_word){
      parsed_rqt.push_back(rqt_word);
    }
    return parsed_rqt;
}

int main() {
    while (true) {
      std::cout << ">> ";

      std::unique_ptr<std::string> message = std::make_unique<std::string>();
      std::getline(std::cin, *message);
        
      if (*message == "exit") {
          break;
      }
      std::vector<std::string> parsed_request = parsing_str(*message);

      for(const auto& word : parsed_request){
        std::cout << word << ", ";
      }
      std::cout << std::endl;
    }
    return 0;
}
