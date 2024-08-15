#include "hashtag.h"
#include "jeek.h"
#include <string>
#include <vector>

void Hashtag::add_jeek(Jeek &jeek) {
  Jeek *new_jeek = &jeek;
  pointed_jeeks.push_back(new_jeek);
}

void Hashtag::show_info() const {
  for (const auto pointed_jeek : pointed_jeeks) {
    pointed_jeek->show_after_search();
  }
}

std::string Hashtag::get_text() const { return text; }

std::vector<Jeek *> Hashtag::get_jeeks() const { return pointed_jeeks; }