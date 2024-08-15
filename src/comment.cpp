#include "comment.h"
#include "reply.h"
#include "user.h"
#include <iostream>
#include <string>

void Comment::add_reply(Reply *reply) { replies.push_back(reply); }

void Comment::set_features(const std::string &content, const std::string &id,
                           User *comment_author) {
  text = content;
  author = comment_author;
  Id = "commy" + id;
}

std::string Comment::get_id() { return Id; }

void Comment::show_full_info() {
  std::cout << author->get_display_name() << std::endl;
  std::cout << text << std::endl;
  std::cout << "replies:" << std::endl;
  for (auto reply : replies) {
    std::cout << reply->get_id() << std::endl;
  }
}

User *Comment::get_author() { return author; }
