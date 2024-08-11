#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "common.h"
#include <string>
#include <vector>

std::string show_searched_hashtags(Network *network, std::string hashtag);
std::string show_searched_username(Network *network, std::string username);
std::string insert_jeeks_to_home(User *user);
std::string jeek_in_html_generator(Jeek *jeek);
std::string show_jeek_details_html(Jeek *jeek_to_be_shown);
int generate_session_Id();
void add_jeeks_users(Network *);
std::string readFile(const char *filename);

#endif // FUNCTIONS_H