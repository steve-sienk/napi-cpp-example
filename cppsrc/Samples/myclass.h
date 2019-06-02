#include <string>

class MyClass {
  public:
    MyClass(std::string value); // constructor
    std::string getValue();
    std::string append(std::string toAppend);
  private:
    std::string panda;
};
