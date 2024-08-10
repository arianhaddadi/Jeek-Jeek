#ifndef JEEK_H
#define JEEK_H

#include "common.h"
#include <string>
#include <vector>

class Jeek {
public:
  std::string get_text();
  void set_text(std::string content);
  void mention(std::string, std::vector<User *> &users, User *);
  void add_a_hashtag(std::string, Network &);
  void show_after_search();
  void add_comment(Comment *);
  std::string get_id();
  void set_rejeek(User *, Jeek *);
  std::vector<Hashtag *> get_hashtags();
  std::vector<User *> get_mentions();
  void add_rejeek_number();
  void show_full_info();
  void get_liked();
  void get_disliked();
  User *get_author();
  void set_features(std::string, std::string, User *);
  int get_like_number();
  int get_rejeek_number();

private:
  User *author;
  std::string text;
  std::string Id;
  std::vector<Comment *> comments;
  std::vector<Hashtag *> hashtags;
  std::vector<User *> mentions;
  int rejeek_number;
  int like_number;
};

#endif // JEEK_H