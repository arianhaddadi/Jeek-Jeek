#include "hashtag.h"
#include "jeek.h"
#include <string>
#include <vector>

void Hashtag::add_jeek(Jeek &jeek) {
  Jeek *new_jeek = &jeek;
  pointed_jeeks.push_back(new_jeek);
}

void Hashtag::show_info() {
  for (auto pointed_jeek : pointed_jeeks) {
    pointed_jeek->show_after_search();
  }
}

std::string Hashtag::get_text() { return text; }

void Hashtag::set_text(const std::string &content) { text = content; }

std::vector<Jeek *> Hashtag::get_jeeks() { return pointed_jeeks; }