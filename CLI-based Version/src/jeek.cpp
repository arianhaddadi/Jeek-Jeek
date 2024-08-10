#include "jeek.h"
#include "comment.h"
#include "functions.h"
#include "hashtag.h"
#include "network.h"
#include "user.h"
#include <iostream>
#include <string>
#include <vector>

void Jeek::show_full_info() {
  std::cout << author->get_display_name() << std::endl;
  std::cout << text << std::endl;
  for (int i = 0; i < hashtags.size(); i++)
    std::cout << "#" << hashtags[i]->get_text() << std::endl;
  for (int i = 0; i < mentions.size(); i++)
    std::cout << "@" << mentions[i]->get_username() << std::endl;
  std::cout << "Likes " << like_number << std::endl
            << "Rejeeks " << rejeek_number << std::endl
            << "Comments:" << std::endl;
  for (int i = 0; i < comments.size(); i++)
    std::cout << comments[i]->get_id() << std::endl;
}

void Jeek::set_features(std::string jeek_text, std::string id,
                        User *jeek_author) {
  this->set_text(jeek_text);
  Id = id;
  author = jeek_author;
  like_number = 0;
  rejeek_number = 0;
}

void Jeek::add_comment(Comment *new_comment) {
  comments.push_back(new_comment);
}

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
    std::cout << "the jeek you want to rejeek doesn't exist" << std::endl;
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

void Jeek::mention(std::string content, std::vector<User *> &all_users,
                   User *mentioner) {
  if (find_user(content, "", all_users) < 0) {
    std::cout << "user you wanted to mention doesn't exist" << std::endl;
    return;
  }
  User *mentioned_user = all_users[find_user(content, "", all_users)];
  mentions.push_back(mentioned_user);
  mentioned_user->add_notifications(mentioner->get_username() +
                                    " mentioned you in " + this->get_id());
}

void Jeek::add_a_hashtag(std::string content, Network &network) {
  if (network.find_hashtag(content) == nullptr) {
    Hashtag *new_hashtag = new Hashtag();
    new_hashtag->set_text(content);
    new_hashtag->add_jeek(*this);
    hashtags.push_back(new_hashtag);
    network.add_hashtag(new_hashtag);
  } else {
    Hashtag *hashtag = network.find_hashtag(content);
    hashtag->add_jeek(*this);
    hashtags.push_back(hashtag);
  }
}

int Jeek::get_like_number() { return like_number; }

int Jeek::get_rejeek_number() { return rejeek_number; }