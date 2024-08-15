#include "user.h"
#include "comment.h"
#include "jeek.h"
#include "network.h"
#include "reply.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<Jeek *> User::get_jeeks() { return jeeks; }

std::string User::get_display_name() { return display_name; }

std::string User::get_password() { return password; }

std::string User::get_username() { return username; }

std::vector<Reply *> User::get_replies() { return replies; }

void User::add_reply(Network *network) {
  std::string comment_id, content;
  std::cin >> comment_id >> content;
  Reply *the_reply = network->find_reply(comment_id);
  if (the_reply == nullptr) {
    std::cout << "Comment/reply was not found." << std::endl;
    return;
  }
  auto *new_reply = new Reply();
  new_reply->set_features(this, content);
  replies.push_back(new_reply);
  network->add_reply(new_reply);
  the_reply->add_reply(new_reply);
  std::cout << "Reply was successfully posted." << std::endl;
}

void User::add_comment(Network *network) {
  std::string jeek_id, content;
  std::cin >> jeek_id >> content;
  Jeek *jeek = network->find_jeek(jeek_id);
  if (jeek == nullptr) {
    std::cout << "The jeek you wanted to comment on doesn't exist."
              << std::endl;
    return;
  }
  auto *new_comment = new Comment();
  new_comment->set_features(content, username + std::to_string(comments.size()),
                            this);
  network->add_comment(new_comment);
  comments.push_back(new_comment);
  jeek->add_comment(new_comment);
  jeek->get_author()->add_notifications(this->get_username() +
                                        " commented on " + jeek->get_id());
  std::cout << "Your comment was successfully posted." << std::endl;
}

void User::add_jeek(Network *network) {
  std::string command, content;
  Jeek *new_jeek = new Jeek();
  new_jeek->set_features("", username + std::to_string(jeeks.size()), this);
  while (command != "publish" && command != "abort") {
    std::cin >> command;
    if (command == "text") {
      getline(std::cin, content);
      if (content.empty())
        continue;
      content.erase(content.begin());
      new_jeek->set_text(content);
    } else if (command == "tag") {
      getline(std::cin, content);
      if (content.empty())
        continue;
      content.erase(content.begin());
      new_jeek->add_a_hashtag(content, network);
    } else if (command == "mention") {
      getline(std::cin, content);
      if (content.empty()) {
        continue;
      }
      content.erase(content.begin());
      User *user = network->find_user(content, "");
      if (user == nullptr) {
        std::cout << "The user you wanted to mention doesn't exist."
                  << std::endl;
        return;
      }
      new_jeek->mention(this, user);
    }
  }
  if (command == "abort" || new_jeek->get_text().empty()) {
    std::cout
        << "Adding Jeek failed due to not having any text or entering abort "
           "command by user "
        << std::endl;
    return;
  }
  jeeks.push_back(new_jeek);
  network->add_jeeks(new_jeek);
  add_notifications_for_followers_after_jeek();
  std::cout << "Your Jeek was successfully published." << std::endl;
}

void User::set_session_Id(const std::string &id) { session_id = id; }

void User::set_features(const std::string &userName,
                        const std::string &displayName,
                        const std::string &passWord) {
  username = userName;
  display_name = displayName;
  password = passWord;
  session_id = "";
}

void User::add_rejeeks(Jeek *new_jeek) { jeeks.push_back(new_jeek); }

void User::show_jeeks() {
  for (auto jeek : jeeks) {
    jeek->show_after_search();
  }
}

bool User::following_does_not_exist(User *user) {
  for (auto following : followings) {
    if (user->get_username() == following->get_username()) {
      return false;
    }
  }
  return true;
}

void User::follow(User *user) { followings.push_back(user); }

int User::find_following_index(User *user) {
  for (int i = 0; i < followings.size(); i++) {
    if (user->get_username() == followings[i]->get_username()) {
      return i;
    }
  }
  return -1;
}

void User::unfollow(User *user) {
  followings.erase(followings.begin() + find_following_index(user));
}

bool User::like_does_not_exist(Jeek *jeek) {
  for (auto like : likes) {
    if (like->get_id() == jeek->get_id()) {
      return false;
    }
  }
  return true;
}

void User::like(Jeek *jeek) {
  jeek->get_liked();
  likes.push_back(jeek);
}

int User::find_likes_index(Jeek *jeek) {
  for (int i = 0; i < likes.size(); i++) {
    if (likes[i]->get_id() == jeek->get_id()) {
      return i;
    }
  }
  return -1;
}

void User::dislike(Jeek *jeek) {
  jeek->get_disliked();
  likes.erase(likes.begin() + find_likes_index(jeek));
}

void User::add_notifications(const std::string &notification) {
  notifications.push_back(notification);
}

std::vector<User *> User::get_followings() { return followings; }

void User::add_follower(User *user) { followers.push_back(user); }

int User::find_follower_index(User *user) {
  for (int i = 0; i < followers.size(); i++) {
    if (followers[i]->get_username() == user->get_username()) {
      return i;
    }
  }
  return -1;
}

void User::delete_follower(User *user) {
  followers.erase(followers.begin() + find_follower_index(user));
}

void User::add_notifications_for_followers_after_jeek() {
  for (auto follower : followers) {
    follower->add_notifications(this->get_username() + " jeeked " +
                                (jeeks[jeeks.size() - 1]->get_id()));
  }
}

void User::show_notifications() {
  for (const auto &notification : notifications) {
    std::cout << notification << std::endl;
  }
  notifications.erase(notifications.begin(), notifications.end());
}

std::string User::get_session_id() { return session_id; }