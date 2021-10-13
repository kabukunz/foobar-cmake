// foo.cpp

#include <iostream> // std::cout
#include "bar.h"

int main() {
  
  bar *mybar = new(bar);
  int count = mybar->rmn();
  
  for(int i = 0; i < count; i++){
    std::cout << "Hello World!" << std::endl;
  }
}