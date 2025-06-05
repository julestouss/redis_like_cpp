#include "constant.h"

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
    input_usr.handle_query(data_1);
    std::cout << std::endl;
  }
  return 0;
}
