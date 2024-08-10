#ifndef NETWORK_H
#define NETWORK_H

#include "common.h"
#include <string>
#include <vector>

class Network {
public:
  void signup();
  void login();
  bool username_not_used(std::string);
  void choose_action(std::string);
  void user_logined();
  void choose_action_after_login(std::string);
  void search();
  void show(std::string);
  void follow_unfollow(std::string);
  void add_rejeek(std::string);
  void like_dislike(std::string);
  void add_hashtag(Hashtag *);
  void search_users(std::string);
  void search_hashtags(std::string);
  void add_jeeks(Jeek *);
  std::vector<Jeek *> get_jeeks();
  std::vector<Comment *> get_comments();
  void add_comment(Comment *);
  void add_reply(Reply *);
  Reply *find_reply(std::string id);
  std::vector<Reply *> get_replies();
  User *user_exists(std::string, std::string);
  void set_user(User *);
  void add_user(std::string, std::string, std::string);
  User *get_current_user();
  std::vector<User *> get_users();
  Hashtag* find_hashtag(std::string content);

private:
  User *current_user;
  std::vector<User *> users;
  std::vector<Comment *> comments;
  std::vector<Jeek *> all_jeeks;
  std::vector<Reply *> replies;
  std::vector<Hashtag *> hashtags;
};
#endif // NETWORK_H