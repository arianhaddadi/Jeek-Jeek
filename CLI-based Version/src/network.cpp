#include "network.h"
#include "comment.h"
#include "hashtag.h"
#include "jeek.h"
#include "reply.h"
#include "user.h"
#include <iostream>
#include <string>
#include <vector>

Reply *Network::find_reply(const std::string &id) {
  for (auto reply : replies)
    if (reply->get_id() == id) {
      return reply;
    }
  return nullptr;
}

std::vector<User *> Network::get_users() { return users; }

void Network::add_reply(Reply *reply) { replies.push_back(reply); }

void Network::add_comment(Comment *comment) { comments.push_back(comment); }

void Network::add_jeeks(Jeek *jeek) { all_jeeks.push_back(jeek); }

void Network::add_hashtag(Hashtag *hashtag) { hashtags.push_back(hashtag); }

bool Network::username_is_not_used(const std::string &username) {
  for (auto user : users) {
    if (user->get_username() == username) {
      return false;
    }
  }
  return true;
}

void Network::signup() {
  std::string username, display_name, password;
  std::cin >> username >> display_name >> password;
  User *new_user = new User();
  new_user->set_features(username, display_name, password);
  if (!username_is_not_used(username)) {
    std::cout << "this username is used before. Signing up failed" << std::endl;
    return;
  }
  std::cout << "user successfully signed up" << std::endl;
  users.push_back(new_user);
}

void Network::search_users(std::string content) {
  content.erase(content.begin(), content.begin() + 2);
  for (auto user : users) {
    if (user->get_username() == content) {
      user->show_jeeks();
      return;
    }
  }
  std::cout << "user doesn't exist" << std::endl;
}

void Network::search_hashtags(std::string content) {
  content.erase(content.begin(), content.begin() + 2);
  for (auto hashtag : hashtags) {
    if (hashtag->get_text() == content) {
      hashtag->show_info();
      return;
    }
  }
  std::cout << "Hashtag doesn't exist" << std::endl;
}

void Network::search() {
  std::string content;
  getline(std::cin, content);
  if (content[1] == '@')
    search_users(content);
  else if (content[1] == '#')
    search_hashtags(content);
}

void Network::add_rejeek(const std::string &jeek_id) {
  Jeek *new_jeek = new Jeek();
  new_jeek->set_rejeek(current_user, find_jeek(jeek_id));
  all_jeeks.push_back(new_jeek);
  current_user->add_rejeeks(new_jeek);
  std::cout << "The Jeek was successfully rejeeked." << std::endl;
}

void Network::choose_action_after_login(const std::string &command) {
  if (command == "jeek") {
    current_user->add_jeek(this);
  } else if (command == "search") {
    search();
  } else if (command == "comment") {
    current_user->add_comment(this);
  } else if (command == "reply") {
    current_user->add_reply(this);
  } else if (command == "showReply" || command == "showComment" ||
             command == "showJeek") {
    show(command);
  } else if (command == "follow" || command == "unfollow") {
    follow_unfollow(command);
  } else if (command == "like" || command == "dislike") {
    like_dislike(command);
  } else if (command == "notifications") {
    current_user->show_notifications();
  } else if (command == "logout") {
    throw command;
  } else if (command == "rejeek") {
    std::string jeek_id;
    std::cin >> jeek_id;
    add_rejeek(jeek_id);
  } else {
    std::cout << "wrong command.PLease try again" << std::endl;
  }
}

void Network::user_logined() {
  std::cout << current_user->get_username() << " successfully logged in."
            << std::endl;
  std::string command;
  while (true) {
    std::cout << "Enter your command: " << std::endl;
    std::cin >> command;
    choose_action_after_login(command);
  }
}

void Network::login() {
  std::string userName, password;
  std::cin >> userName >> password;
  User *user = find_user(userName, password);
  if (user == nullptr) {
    std::cout << "Invalid information." << std::endl;
    return;
  }
  current_user = user;
  user_logined();
}

void Network::choose_action(const std::string &command) {
  if (command == "signup") {
    signup();
  } else if (command == "login") {
    login();
  } else {
    throw command;
  }
}

std::vector<Reply *> Network::get_replies() { return replies; }

void Network::follow_unfollow(const std::string &command) {
  std::string following_username;
  std::cin >> following_username;
  User *user = find_user(following_username, "");
  if (user == nullptr) {
    std::cout << "User you wanted to follow/unfollow doesn't exist."
              << std::endl;
    return;
  }
  if (command == "follow") {
    if (current_user->following_does_not_exist(user)) {
      current_user->follow(user);
      user->add_follower(current_user);
      std::cout << "User was successfully followed." << std::endl;
    } else if (command == "unfollow") {
      if (!current_user->following_does_not_exist(user)) {
        current_user->unfollow(user);
        user->delete_follower(current_user);
        std::cout << "User was successfully unfollowed." << std::endl;
      }
    }
  }
}

void Network::like_dislike(const std::string &command) {
  std::string liked_jeek_id;
  std::cin >> liked_jeek_id;
  Jeek *jeek_to_get_liked_disliked = find_jeek(liked_jeek_id);
  if (jeek_to_get_liked_disliked == nullptr) {
    std::cout << "The jeek you wanted to like/dislike doesn't exist."
              << std::endl;
    return;
  }
  if (command == "like")
    if (current_user->like_does_not_exist(jeek_to_get_liked_disliked)) {
      current_user->like(jeek_to_get_liked_disliked);
      std::cout << "The Jeek was successfully liked." << std::endl;
      jeek_to_get_liked_disliked->get_author()->add_notifications(
          current_user->get_username() + " liked " +
          jeek_to_get_liked_disliked->get_id());
    } else
      std::cout
          << "This jeek was liked by you before so you can't like it again."
          << std::endl;
  else if (command == "dislike")
    if (!current_user->like_does_not_exist(jeek_to_get_liked_disliked)) {
      current_user->dislike(jeek_to_get_liked_disliked);
      std::cout << "The Jeek was successfully disliked." << std::endl;
      jeek_to_get_liked_disliked->get_author()->add_notifications(
          current_user->get_username() + " disliked " +
          jeek_to_get_liked_disliked->get_id());
    } else {
      std::cout << "This jeek is not liked by you so you can't dislike it."
                << std::endl;
    }
}

Jeek *Network::find_jeek(const std::string &jeek_id) {
  for (auto jeek : all_jeeks) {
    if (jeek->get_id() == jeek_id) {
      return jeek;
    }
  }
  return nullptr;
}

Hashtag *Network::find_hashtag(const std::string &content) {
  for (auto hashtag : hashtags)
    if (hashtag->get_text() == content) {
      return hashtag;
    }
  return nullptr;
}

void Network::show(const std::string &command) {
  std::string id;
  std::cin >> id;
  if (command == "showReply") {
    Reply *reply_to_get_shown = find_reply(id);
    if (reply_to_get_shown == nullptr) {
      std::cout << "The reply you wanted to be shown doesn't exist."
                << std::endl;
      return;
    }
    reply_to_get_shown->show_full_info();
  } else if (command == "showComment") {
    Comment *comment_to_get_shown = find_comment(id);
    if (comment_to_get_shown == nullptr) {
      std::cout << "The comment you wanted to be shown doesn't exist."
                << std::endl;
      return;
    }
    comment_to_get_shown->show_full_info();
  } else {
    Jeek *jeek_to_get_shown = find_jeek(id);
    if (jeek_to_get_shown == nullptr) {
      std::cout << "The jeek you wanted to be shown doesn't exist."
                << std::endl;
      return;
    }
    jeek_to_get_shown->show_full_info();
  }
}

User *Network::user_exists(const std::string &username,
                           const std::string &password) {
  for (auto user : users) {
    if (user->get_username() == username && user->get_password() == password) {
      return user;
    }
  }
  return nullptr;
}

void Network::set_user(User *user) { current_user = user; }

void Network::add_user(const std::string &username, const std::string &password,
                       const std::string &display_name) {
  User *new_user = new User();
  new_user->set_features(username, display_name, password);
  users.push_back(new_user);
}

Comment *Network::find_comment(const std::string &comment_id) {
  for (auto comment : comments)
    if (comment->get_id() == comment_id)
      return comment;
  return nullptr;
}

User *Network::find_user(const std::string &username,
                         const std::string &password) {
  for (auto user : users) {
    if (user->get_username() == username &&
        (user->get_password() == password || password.empty())) {
      return user;
    }
  }
  return nullptr;
}

User *Network::find_user_by_session_id(const std::string &id) {
  for (auto user : users) {
    if (user->get_session_id() == id) {
      return user;
    }
  }
  return nullptr;
}
