#ifndef USER_H
#define USER_H

#include "common.h"
#include <string>
#include <vector>

class User {
public:
  void set_features(std::string, std::string, std::string);
  std::string get_username();
  std::string get_password();
  std::string get_display_name();
  void add_jeek(std::vector<User *> &users, Network &);
  void add_comment(Network &);
  void add_reply(Network &);
  void show_notifications();
  void show_jeeks();
  void add_rejeeks(Jeek *);
  std::vector<Jeek *> get_jeeks();
  void unfollow(User *);
  int find_following_index(User *);
  void follow(User *);
  bool following_does_not_exist(User *);
  std::vector<Reply *> get_replies();
  bool like_does_not_exist(Jeek *);
  void like(Jeek *);
  int find_likes_index(Jeek *);
  void dislike(Jeek *);
  void add_notifications(std::string);
  std::vector<User *> get_followings();
  void add_follower(User *);
  int find_follower_index(User *);
  void delete_follower(User *);
  void add_notifications_for_followers_after_jeek();
  void set_session_Id(std::string);
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
  std::string session_Id;
};

#endif // USER_H
