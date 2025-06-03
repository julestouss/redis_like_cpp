#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

class message {
  private:
    std::string content;
    std::vector<std::string> parsed_rqt;
  public:
    message() = default;
    ~message() = default;

    void read(){
      std::getline(std::cin, content);
    }

    const std::string& getContent() const {
      return content;
    }

    const std::vector<std::string>& getParsed() const {
      return parsed_rqt;
    }

    std::vector<std::string> parsing_str(){

      std::istringstream iss(content);
      std::string rqt_word;

      while(iss >> rqt_word){
        parsed_rqt.push_back(rqt_word);
      }
      return parsed_rqt;
    }
};


int main() {
    message input_usr{};
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
