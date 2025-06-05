#include "constant.h"

void init(){
  log::open();
}


int main() {
  init();

  query input_usr{};
  data data_1{};
  while (true) {
    std::cout << ">> ";
    input_usr.read();

    if (input_usr.getContent() == "exit") {
      log::close();
      break;
    }
    input_usr.parsing_str();
    if (input_usr.handle_query(data_1)){
      log::write(input_usr.getContent());
    }

    std::cout << std::endl;
  }
  return 0;
}
