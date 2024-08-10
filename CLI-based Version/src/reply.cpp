#include "reply.h"
#include "user.h"
#include <iostream>
#include <string>

void Reply::set_features(User *replier, std::string reply_text) {
  text = reply_text;
  author = replier;
  Id = "repl" + replier->get_username() +
       std::to_string(replier->get_replies().size());
}

void Reply::show_full_info() {
  std::cout << author->get_display_name() << std::endl;
  std::cout << text << std::endl;
  std::cout << "replies:" << std::endl;
  for (int i = 0; i < replies.size(); i++)
    std::cout << replies[i]->get_id() << std::endl;
}

std::string Reply::get_id() { return Id; }

void Reply::add_reply(Reply *new_reply) { replies.push_back(new_reply); }
