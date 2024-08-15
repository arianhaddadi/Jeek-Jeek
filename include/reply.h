#ifndef REPLY_H
#define REPLY_H

#include "user.h"
#include <string>
#include <vector>

class Reply {
public:
  Reply(User *replier, const std::string &reply_text)
      : author(replier), Id("repl" + replier->get_username() +
                            std::to_string(replier->get_replies().size())),
        text(reply_text) {}
  std::string get_id() const;
  void show_full_info() const;
  void add_reply(Reply *reply);

private:
  User *author;
  std::string Id;
  std::string text;
  std::vector<Reply *> replies;
};

#endif // REPLY_H