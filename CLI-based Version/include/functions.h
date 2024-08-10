#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "common.h"
#include <string>
#include <vector>

Reply *find_reply(std::string id, Network &network);
int find_user(std::string userName, std::string passWord,
              std::vector<User *> users);
Jeek *find_jeek(std::string jeek_id, Network &network);
Comment *find_comment(std::string comment_id, Network &network);
std::string get_all_tags(Jeek *jeek_to_be_show);
std::string get_all_mentions(Jeek *jeek_to_be_shown);
std::string show_searched_hashtags(Network *network, std::string hashtag);
std::string show_searched_username(Network *network, std::string username);
std::string insert_jeeks_to_home(User *user);
std::string jeek_in_html_generator(Jeek *jeek);
User *find_user_by_sessionId(std::string Id, Network *network);
std::string show_jeek_details_html(Jeek *jeek_to_be_shown);
int generate_session_Id();
void add_jeeks_users(Network *);
std::string readFile(const char *filename);
std::string readFile(std::string filename);

#endif // FUNCTIONS_H