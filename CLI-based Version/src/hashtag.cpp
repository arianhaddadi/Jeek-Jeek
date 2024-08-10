#include "hashtag.h"
#include "jeek.h"
#include <vector>
#include <string>

void Hashtag::add_jeek(Jeek &jeek) {
  Jeek *new_jeek = &jeek;
  pointed_jeeks.push_back(new_jeek);
}

void Hashtag::show_info() {
  for (int i = 0; i < pointed_jeeks.size(); i++)
    pointed_jeeks[i]->show_after_search();
}

std::string Hashtag::get_text() { return text; }

void Hashtag::set_text(std::string content) { text = content; }

std::vector<Jeek *> Hashtag::get_jeeks() { return pointed_jeeks; }