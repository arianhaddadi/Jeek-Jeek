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
    switch (command) {
    case "signup":
      network.signup();
      break;
    case "login":
      network.login();
      break;
    case "logout":
      std::cout << "You got logged out." << std::endl;
      break;
    case "quit":
      std::cout << "Goodbye!" << std::endl;
      break;
    default:
      std::cout << "Wrong command. Please try again:" << std::endl;
    }
  }
  return 0;
}