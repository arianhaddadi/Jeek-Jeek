#ifndef COMMENT_H
#define COMMENT_H

#include "common.h"
#include <string>
#include <vector>

class Comment {
public:
  Comment(const std::string &content, const std::string &id,
          User *comment_author)
      : author(comment_author), Id("commy" + id), text(content) {}
  std::string get_id() const;
  void add_reply(Reply *reply);
  void show_full_info() const;
  User *get_author() const;

private:
  User *author;
  std::string Id;
  std::string text;
  std::vector<Reply *> replies;
};

#endif // COMMENT_H