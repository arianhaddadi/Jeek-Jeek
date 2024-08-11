#ifndef JEEK_H
#define JEEK_H

#include "common.h"
#include <string>
#include <vector>

class Jeek {
public:
  std::string get_text();
  void set_text(std::string content);
  void mention(User *mentioner, User *mentioned);
  void add_a_hashtag(const std::string &content, Network *network);
  void show_after_search();
  void add_comment(Comment *comment);
  std::string get_id();
  void set_rejeek(User *rejeeker, Jeek *rejeeked_jeek);
  std::vector<Hashtag *> get_hashtags();
  std::vector<User *> get_mentions();
  void add_rejeek_number();
  void show_full_info();
  void get_liked();
  void get_disliked();
  User *get_author();
  void set_features(const std::string &jeek_text, const std::string &id,
                    User *jeek_author);
  int get_like_number() const;
  int get_rejeek_number() const;
  std::string get_tags_formatted();
  std::string get_mentions_formatted();

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