#ifndef USER_H
#define USER_H

#include "common.h"
#include <string>
#include <vector>

class User {
public:
  User(const std::string &userName, const std::string &displayName,
       const std::string &passWord)
      : username(userName), display_name(displayName), password(passWord) {}
  std::string get_username() const;
  std::string get_password() const;
  std::string get_display_name() const;
  void add_jeek(Network *network);
  void add_comment(Network *network);
  void add_reply(Network *network);
  void show_notifications();
  void show_jeeks() const;
  void add_rejeeks(Jeek *);
  std::vector<Jeek *> get_jeeks() const;
  void unfollow(User *user);
  int find_following_index(User *user) const;
  void follow(User *user);
  bool following_does_not_exist(User *user) const;
  std::vector<Reply *> get_replies();
  bool like_does_not_exist(Jeek *jeek) const;
  void like(Jeek *jeek);
  int find_likes_index(Jeek *jeek) const;
  void dislike(Jeek *jeek);
  void add_notifications(const std::string &notification);
  std::vector<User *> get_followings() const;
  void add_follower(User *user);
  int find_follower_index(User *user) const;
  void delete_follower(User *user);
  void add_notifications_for_followers_after_jeek() const;
  void set_session_Id(const std::string &id);
  std::string get_session_id();

private:
  std::vector<Jeek *> jeeks;
  std::vector<User *> followings;
  std::vector<User *> followers;
  std::vector<Comment *> comments;
  std::vector<Reply *> replies;
  std::vector<Jeek *> likes;
  std::vector<std::string> notifications;
  std::string username;
  std::string display_name;
  std::string password;
  std::string session_id;
};

#endif // USER_H
