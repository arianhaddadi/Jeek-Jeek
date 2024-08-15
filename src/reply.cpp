#include "reply.h"
#include "user.h"
#include <iostream>
#include <string>

void Reply::show_full_info() const {
  std::cout << author->get_display_name() << std::endl;
  std::cout << text << std::endl;
  std::cout << "replies:" << std::endl;
  for (const auto reply : replies) {
    std::cout << reply->get_id() << std::endl;
  }
}

std::string Reply::get_id() const { return Id; }

void Reply::add_reply(Reply *reply) { replies.push_back(reply); }
