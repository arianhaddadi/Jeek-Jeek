#ifndef COMMENT_H
#define COMMENT_H

#include "common.h"
#include <iostream>
#include <string>
#include <vector>

class Comment {
public:
  void set_features(std::string, std::string, User *);
  std::string get_id();
  void add_reply(Reply *);
  void show_full_info();
  User *get_author();

private:
  User *author;
  std::string Id;
  std::string text;
  std::vector<Reply *> replies;
};

#endif // COMMENT_H