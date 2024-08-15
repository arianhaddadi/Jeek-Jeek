#ifndef HASHTAG_H
#define HASHTAG_H

#include "common.h"
#include <string>
#include <vector>

class Hashtag {
public:
  explicit Hashtag(const std::string &content) : text(content) {}
  void add_jeek(Jeek &new_jeek);
  std::string get_text() const;
  void show_info() const;
  std::vector<Jeek *> get_jeeks() const;

private:
  std::vector<Jeek *> pointed_jeeks;
  std::string text;
};

#endif // HASHTAG_H
