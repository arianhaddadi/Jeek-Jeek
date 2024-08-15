#include "reply.h"
#include "user.h"
#include <iostream>
#include <string>

void Reply::set_features(User *replier, const std::string &reply_text) {
  text = reply_text;
  author = replier;
  Id = "repl" + replier->get_username() +
       std::to_string(replier->get_replies().size());
}

void Reply::show_full_info() {
  std::cout << author->get_display_name() << std::endl;
  std::cout << text << std::endl;
  std::cout << "replies:" << std::endl;
  for (auto reply : replies) {
    std::cout << reply->get_id() << std::endl;
  }
}

std::string Reply::get_id() { return Id; }

void Reply::add_reply(Reply *reply) { replies.push_back(reply); }
