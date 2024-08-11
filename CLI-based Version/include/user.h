#ifndef USER_H
#define USER_H

#include "common.h"
#include <string>
#include <vector>

class User {
public:
  void set_features(const std::string &userName, const std::string &displayName,
                    const std::string &passWord);
  std::string get_username();
  std::string get_password();
  std::string get_display_name();
  void add_jeek(Network *network);
  void add_comment(Network *network);
  void add_reply(Network *network);
  void show_notifications();
  void show_jeeks();
  void add_rejeeks(Jeek *);
  std::vector<Jeek *> get_jeeks();
  void unfollow(User *user);
  int find_following_index(User *user);
  void follow(User *user);
  bool following_does_not_exist(User *user);
  std::vector<Reply *> get_replies();
  bool like_does_not_exist(Jeek *jeek);
  void like(Jeek *jeek);
  int find_likes_index(Jeek *jeek);
  void dislike(Jeek *jeek);
  void add_notifications(const std::string &notification);
  std::vector<User *> get_followings();
  void add_follower(User *user);
  int find_follower_index(User *user);
  void delete_follower(User *user);
  void add_notifications_for_followers_after_jeek();
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
