#include <unordered_map>
#include <string>
#include <variant>
#include <vector>
#include <iostream>
#include <algorithm>

class data{
private:
  std::unordered_map<std::string, std::variant<int, std::string>> data_map;
public:
  data();
  ~data();

  void getFunc(const std::vector<std::string>& query);
  void setFunc(const std::vector<std::string>& query);
  void delFunc(const std::vector<std::string>& query);
  void snapshot();
};
