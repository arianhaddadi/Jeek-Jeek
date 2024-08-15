#ifndef JEEK_H
#define JEEK_H

#include "common.h"
#include <string>
#include <vector>

class Jeek {
public:
  Jeek() = default;
  Jeek(const std::string &jeek_text, const std::string &jeek_id,
       User *jeek_author)
      : author(jeek_author), text(jeek_text), Id(jeek_id) {}
  std::string get_text() const;
  void set_text(std::string content);
  void mention(User *mentioner, User *mentioned);
  void add_a_hashtag(const std::string &content, Network *network);
  void show_after_search() const;
  void add_comment(Comment *comment);
  std::string get_id();
  void set_rejeek(User *rejeeker, Jeek *rejeeked_jeek);
  std::vector<Hashtag *> get_hashtags() const;
  std::vector<User *> get_mentions() const;
  void add_rejeek_number();
  void show_full_info() const;
  void get_liked();
  void get_disliked();
  User *get_author() const;
  int get_like_number() const;
  int get_rejeek_number() const;
  std::string get_tags_formatted() const;
  std::string get_mentions_formatted() const;

private:
  User *author;
  std::string text;
  std::string Id;
  std::vector<Comment *> comments;
  std::vector<Hashtag *> hashtags;
  std::vector<User *> mentions;
  int rejeek_number = 0;
  int like_number = 0;
};

#endif // JEEK_H