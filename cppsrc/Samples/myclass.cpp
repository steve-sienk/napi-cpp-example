/* cppsrc/Samples/myclass.cpp */

#include "myclass.h"

MyClass::MyClass(std::string value){
  this->panda = value;
}

std::string MyClass::getValue() {
  return this->panda;
}

std::string MyClass::append(std::string toAppend) {
  this->panda += ", ";
  this->panda += toAppend;
  return this->panda;
}
