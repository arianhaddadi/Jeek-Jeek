#include "jeek.h"
#include "comment.h"
#include "hashtag.h"
#include "network.h"
#include "user.h"
#include <iostream>
#include <string>
#include <vector>

void Jeek::show_full_info() {
  std::cout << author->get_display_name() << std::endl;
  std::cout << text << std::endl;
  for (auto hashtag : hashtags) {
    std::cout << "#" << hashtag->get_text() << std::endl;
  }
  for (auto mention : mentions) {
    std::cout << "@" << mention->get_username() << std::endl;
  }
  std::cout << "Likes " << like_number << std::endl
            << "Rejeeks " << rejeek_number << std::endl
            << "Comments:" << std::endl;
  for (auto comment : comments) {
    std::cout << comment->get_id() << std::endl;
  }
}

void Jeek::set_features(const std::string &jeek_text, const std::string &id,
                        User *jeek_author) {
  this->set_text(jeek_text);
  Id = id;
  author = jeek_author;
  like_number = 0;
  rejeek_number = 0;
}

void Jeek::add_comment(Comment *comment) { comments.push_back(comment); }

std::string Jeek::get_text() { return text; }

User *Jeek::get_author() { return author; }

void Jeek::set_text(std::string content) {
  if (content.size() > 140)
    content.erase(content.begin() + 140, content.end());
  text = content;
}

void Jeek::get_disliked() { like_number--; }

void Jeek::get_liked() { like_number++; }

std::vector<Hashtag *> Jeek::get_hashtags() { return hashtags; }

std::vector<User *> Jeek::get_mentions() { return mentions; }

void Jeek::add_rejeek_number() { rejeek_number++; }

std::string Jeek::get_id() { return Id; }

void Jeek::set_rejeek(User *rejeeker, Jeek *rejeeked_jeek) {
  if (rejeeked_jeek == nullptr) {
    std::cout << "the Jeek you want to rejeek doesn't exist" << std::endl;
    return;
  }
  text = "Rejeeked:" + rejeeked_jeek->get_text();
  Id = rejeeker->get_username() + std::to_string(rejeeker->get_jeeks().size());
  author = rejeeker;
  hashtags = rejeeked_jeek->get_hashtags();
  mentions = rejeeked_jeek->get_mentions();
  rejeeked_jeek->add_rejeek_number();
  rejeeked_jeek->author->add_notifications(
      rejeeker->get_username() + " rejeeked " + rejeeked_jeek->get_id());
}

void Jeek::show_after_search() {
  std::cout << Id << " " << author->get_display_name() << std::endl
            << text << std::endl
            << std::endl;
}

void Jeek::mention(User *mentioner, User *mentioned) {
  mentions.push_back(mentioned);
  mentioned->add_notifications(mentioner->get_username() +
                               " mentioned you in " + this->get_id());
}

void Jeek::add_a_hashtag(const std::string &content, Network *network) {
  if (network->find_hashtag(content) == nullptr) {
    auto *new_hashtag = new Hashtag();
    new_hashtag->set_text(content);
    new_hashtag->add_jeek(*this);
    hashtags.push_back(new_hashtag);
    network->add_hashtag(new_hashtag);
  } else {
    Hashtag *hashtag = network->find_hashtag(content);
    hashtag->add_jeek(*this);
    hashtags.push_back(hashtag);
  }
}

int Jeek::get_like_number() const { return like_number; }

int Jeek::get_rejeek_number() const { return rejeek_number; }

std::string Jeek::get_tags_formatted() {
  std::string formatted_tags;
  for (auto hashtag : hashtags) {
    formatted_tags += "#" + hashtag->get_text() + " ";
  }
  return formatted_tags;
}

std::string Jeek::get_mentions_formatted() {
  std::string formatted_mentions;
  for (auto mention : mentions) {
    formatted_mentions += "@" + mention->get_username() + " ";
  }
  return formatted_mentions;
}
