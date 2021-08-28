#ifndef _FUNCTIONS_
#define _FUNCTIONS_

#include <fstream>
#include "Network.hpp"

#define BUFFER_SIZE 4145152


Reply * find_reply ( string id , Network& network ) ;
int find_user( string userName , string passWord , vector<User*> users ) ;
Jeek* find_jeek ( string jeek_id , Network & network ) ;
Comment* find_comment ( string comment_id , Network & network ) ;
Hashtag* find_hashtag ( string content , Network & network ) ;
string get_all_tags (Jeek * jeek_to_be_show) ;
string get_all_mentions (Jeek* jeek_to_be_shown ) ;
string show_searched_hashtags ( Network* network , string hashtag ) ;
string show_searched_username ( Network* network , string username ) ;
string insert_jeeks_to_home (User* user) ;
string jeek_in_html_generator ( Jeek* jeek ) ;
User* find_user_by_sessionId (string Id , Network* network);
string show_jeek_details_html (Jeek* jeek_to_be_shown);
int generate_session_Id ();
void add_jeeks_users(Network*);
string readFile(const char *filename);
string readFile(string filename);

#endif