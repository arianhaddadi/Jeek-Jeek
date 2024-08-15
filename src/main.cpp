#include "network.h"
#include <iostream>
#include <string>

int main() {
  Network network;
  std::string command;
  while (command != "quit") {
    std::cout << "You need to signup/login to the system. " << std::endl
              << "Your command:";
    std::cin >> command;
    try {
      network.choose_action(command);
    } catch (const std::string &exception) {
      if (exception == "logout") {
        std::cout << "You got logged out." << std::endl;
        continue;
      }
      std::cout << "Wrong command. Please try again:" << std::endl;
      continue;
    }
  }
  return 0;
}