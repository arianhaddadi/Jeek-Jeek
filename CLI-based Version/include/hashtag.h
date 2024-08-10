#ifndef HASHTAG_H
#define HASHTAG_H

#include "common.h"
#include <iostream>
#include <string>
#include <vector>

class Hashtag {
public:
  void set_text(std::string content);
  void add_jeek(Jeek &new_jeek);
  std::string get_text();
  void show_info();
  std::vector<Jeek *> get_jeeks();

private:
  std::vector<Jeek *> pointed_jeeks;
  std::string text;
};

#endif // HASHTAG_H
