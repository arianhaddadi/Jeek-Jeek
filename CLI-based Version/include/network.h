#ifndef NETWORK_H
#define NETWORK_H

#include "common.h"
#include <string>
#include <vector>

class Network {
public:
  void signup();
  void login();
  bool username_is_not_used(const std::string &username);
  void choose_action(const std::string &command);
  void user_logined();
  void choose_action_after_login(const std::string &command);
  void search();
  void show(const std::string &command);
  void follow_unfollow(const std::string &command);
  void add_rejeek(const std::string &jeek_id);
  void like_dislike(const std::string &command);
  void add_hashtag(Hashtag *hashtag);
  void search_users(std::string content);
  void search_hashtags(std::string content);
  void add_jeeks(Jeek *jeek);
  void add_comment(Comment *comment);
  void add_reply(Reply *reply);
  std::vector<Reply *> get_replies();
  User *user_exists(const std::string &username, const std::string &password);
  void set_user(User *user);
  void add_user(const std::string &username, const std::string &password,
                const std::string &display_name);
  std::vector<User *> get_users();
  Hashtag *find_hashtag(const std::string &content);
  Jeek *find_jeek(const std::string &jeek_id);
  Comment *find_comment(const std::string &comment_id);
  Reply *find_reply(const std::string &id);
  User *find_user(const std::string &username, const std::string &password);
  User *find_user_by_session_id(const std::string &id);

private:
  User *current_user;
  std::vector<User *> users;
  std::vector<Comment *> comments;
  std::vector<Jeek *> all_jeeks;
  std::vector<Reply *> replies;
  std::vector<Hashtag *> hashtags;
};
#endif // NETWORK_H