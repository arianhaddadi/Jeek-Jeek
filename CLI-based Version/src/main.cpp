#include "network.h"
#include <iostream>
#include <string>

int main() {
  Network network;
  std::string command;
  while (command != "quit") {
    std::cout << "you need to signup/login to us the system" << std::endl
         << "your command:";
    std::cin >> command;
    try {
      network.choose_action(command);
    } catch (std::string exception) {
      if (exception == "logout") {
        std::cout << "you got logged out" << std::endl;
        continue;
      }
      std::cout << "wrong command.PLease try again:" << std::endl;
      continue;
    }
  }
  return 0;
}