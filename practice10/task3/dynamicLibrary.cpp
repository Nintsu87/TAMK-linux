#include <iostream>

extern "C" {
  void dHelloWorld() {
    std::cout << "Hello, World!" << std::endl;
  }
}
