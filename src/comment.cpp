#include "comment.h"
#include "reply.h"
#include "user.h"
#include <iostream>
#include <string>

void Comment::add_reply(Reply *reply) { replies.push_back(reply); }

std::string Comment::get_id() const { return Id; }

void Comment::show_full_info() const {
  std::cout << author->get_display_name() << std::endl;
  std::cout << text << std::endl;
  std::cout << "replies:" << std::endl;
  for (const auto reply : replies) {
    std::cout << reply->get_id() << std::endl;
  }
}

User *Comment::get_author() const { return author; }
