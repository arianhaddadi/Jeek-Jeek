#ifndef __UTILILITES__
#define __UTILILITES__
#include <map>
#include <string>
#include <vector>

#define BUFFER_SIZE 4145152

struct comp {
  bool operator()(const std::string &lhs, const std::string &rhs) const;
};

typedef std::map<std::string, std::string, comp>
    cimap; // Case-Insensitive <string, string> map

std::string readFile(const char *filename);
int generate_session_Id();
std::string getExtension(std::string filePath);
std::string show_searched_hashtags(Network *network, std::string hashtag);
std::string show_searched_username(Network *network, std::string username);
std::string insert_jeeks_to_home(User *user);
std::string show_jeek_details_html(Jeek *jeek_to_be_shown);
std::string jeek_in_html_generator(Jeek *jeek);
void printVector(std::vector<std::string> v);
std::vector<std::string> split(std::string s, std::string d);

std::string urlEncode(std::string const &str);
std::string urlDecode(std::string const &str);

#endif
