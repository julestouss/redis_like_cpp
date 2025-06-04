#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

class query {
private:
  std::string content;
  std::vector<std::string> parsed_rqt;

public:
  query();
  ~query();

  void read();

  const std::string& getContent() const;
  const std::vector<std::string>& getParsed() const;
  std::vector<std::string> parsing_str();
};
