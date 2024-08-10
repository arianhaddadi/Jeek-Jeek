#ifndef REPLY_H
#define REPLY_H

#include "common.h"
#include <string>
#include <vector>

class Reply {
public:
  std::string get_id();
  void set_features(User *, std::string);
  void show_full_info();
  void add_reply(Reply *);

private:
  User *author;
  std::string Id;
  std::string text;
  std::vector<Reply *> replies;
};

#endif // REPLY_H