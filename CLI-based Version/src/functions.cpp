#include "functions.h"
#include "comment.h"
#include "hashtag.h"
#include "jeek.h"
#include "network.h"
#include "reply.h"
#include "user.h"
#include <fstream>
#include <string>

#define BUFFER_SIZE 4145152

std::string readFile(const char *filename) {
  std::string s = "";
  char buffer[BUFFER_SIZE];
  std::ifstream infile(filename);
  infile.seekg(0, infile.end);
  size_t length = infile.tellg();
  infile.seekg(0, infile.beg);
  if (length > sizeof(buffer))
    length = sizeof(buffer);

  infile.read(buffer, length);
  for (size_t i = 0; i < length; i++) {
    s += buffer[i];
  }
  return s;
}

std::string readFile(std::string filename) {
  return readFile(filename.c_str());
}

void add_jeeks_users(Network *network) {
  network->add_user("a", "b", "c");
  Jeek *new_jeek = new Jeek();
  new_jeek->set_features("hello", "id", network->get_users()[0]);
  new_jeek->add_a_hashtag("heell", *network);
  network->get_users()[0]->add_rejeeks(new_jeek);
  network->add_jeeks(new_jeek);
}

int generate_session_Id() {
  srand(time(nullptr));
  return rand() % 1000;
}

User *find_user_by_sessionId(std::string Id, Network *network) {
  for (int i = 0; i < network->get_users().size(); i++)
    if (network->get_users()[i]->get_session_id() == Id)
      return network->get_users()[i];
  return nullptr;
}

int find_user(std::string userName, std::string passWord,
              std::vector<User *> users) {
  if (passWord == "") {
    for (int i = 0; i < users.size(); i++)
      if (users[i]->get_username() == userName)
        return i;
    return -1;
  }
  for (int i = 0; i < users.size(); i++)
    if (users[i]->get_username() == userName &&
        users[i]->get_password() == passWord)
      return i;
  return -1;
}

Jeek *find_jeek(std::string jeek_id, Network &network) {
  for (int i = 0; i < network.get_jeeks().size(); i++)
    if ((network.get_jeeks()[i])->get_id() == jeek_id)
      return network.get_jeeks()[i];
  return nullptr;
}

Comment *find_comment(std::string comment_id, Network &network) {
  for (int i = 0; i < network.get_comments().size(); i++)
    if ((network.get_comments()[i])->get_id() == comment_id)
      return network.get_comments()[i];
  return nullptr;
}

Reply *find_reply(std::string id, Network &network) {
  for (int i = 0; i < network.get_replies().size(); i++)
    if (network.get_replies()[i]->get_id() == id)
      return network.get_replies()[i];
  return nullptr;
}

std::string get_all_tags(Jeek *jeek_to_be_shown) {
  std::string all_tags = "";
  for (int i = 0; i < jeek_to_be_shown->get_hashtags().size(); i++)
    all_tags += "#" + jeek_to_be_shown->get_hashtags()[i]->get_text() + " ";
  return all_tags;
}

std::string get_all_mentions(Jeek *jeek_to_be_shown) {
  std::string all_mentions = "";
  for (int i = 0; i < jeek_to_be_shown->get_mentions().size(); i++)
    all_mentions +=
        "@" + jeek_to_be_shown->get_mentions()[i]->get_username() + " ";
  return all_mentions;
}

std::string show_searched_hashtags(Network *network, std::string hashtag) {
  std::string file_content = readFile("htmlFiles/home.html");
  int index_of_file_content = file_content.find("</body>");
  Hashtag *searched_hashtag = network->find_hashtag(hashtag.substr(1));
  file_content.erase(file_content.begin() + index_of_file_content,
                     file_content.end());
  if (searched_hashtag == nullptr)
    return file_content +
           "<p style = \"text-align:center\"> No results were found </p>" +
           " </body> </html>";
  for (int i = 0; i < searched_hashtag->get_jeeks().size(); i++)
    file_content += jeek_in_html_generator(searched_hashtag->get_jeeks()[i]);
  file_content += " </body> + </html> ";
  return file_content;
}

std::string jeek_in_html_generator(Jeek *jeek) {
  std::string content = "<strong>@" + jeek->get_author()->get_username() +
                        ": </strong>" + jeek->get_text() + " ";
  for (int i = 0; i < jeek->get_hashtags().size(); i++)
    content += "#" + jeek->get_hashtags()[i]->get_text() + " ";
  std::string html_code =
      "<div style = \"width: fit-screen; padding: 5px; border: 3px solid cyan; "
      "margin: 0; color:green;\" ><pre style = \"font-size:20px\"> " +
      content +
      " <form action = \"/jeek_details\" method = \"post\" ><input value "
      "=\"details\" " +
      "style=\"float:right;color:red;width:200px;height:50px\" "
      "type=\"submit\"/> <input type=\"text\" value=\"" +
      jeek->get_id() +
      "\" name = \"details\"  style = \"visibility:hidden \" /> </form> "
      "</div> ";
  return html_code;
}

std::string show_searched_username(Network *network, std::string username) {
  std::string file_content = readFile("htmlFiles/home.html");
  int index_of_file_content = file_content.find("</body>"),
      index_of_user = find_user(username.substr(1), "", network->get_users());
  file_content.erase(file_content.begin() + index_of_file_content,
                     file_content.end());
  if (index_of_user == -1)
    return file_content +
           "<p style = \"text-align:center\"> No results were found </p>" +
           " </body> </html>";
  User *new_user = network->get_users()[index_of_user];
  for (int i = 0; i < new_user->get_jeeks().size(); i++)
    file_content += jeek_in_html_generator(new_user->get_jeeks()[i]);
  file_content += " </body>  </html> ";
  return file_content;
}

std::string insert_jeeks_to_home(User *user) {
  std::string file_content = readFile("htmlFiles/home.html");
  if (user->get_jeeks().size() == 0)
    return file_content;
  int index = file_content.find("</body>");
  file_content.erase(file_content.begin() + index, file_content.end());
  for (int i = user->get_jeeks().size() - 1; i >= 0; i--)
    file_content += jeek_in_html_generator(user->get_jeeks()[i]);
  file_content += " </body> + </html> ";
  return file_content;
}

std::string show_jeek_details_html(Jeek *jeek_to_be_shown) {
  std::string html_format_content = readFile("htmlFiles/Jeek_details.html");
  int position_of_jeeker = html_format_content.find("</p>  <br>");
  std::string sub_string = html_format_content.substr(position_of_jeeker);
  html_format_content.erase(html_format_content.begin() + position_of_jeeker,
                            html_format_content.end());
  int position_of_text = sub_string.find(" </pre>");
  std::string sub_sub_string = sub_string.substr(position_of_text);
  sub_string.erase(sub_string.begin() + position_of_text, sub_string.end());
  int position_of_like = sub_sub_string.find("Like/Dislike");
  std::string sub_sub_sub_string = sub_sub_string.substr(position_of_like + 12);
  sub_sub_string.erase(sub_sub_string.begin() + position_of_like + 12,
                       sub_sub_string.end());
  int position_of_rejeek = sub_sub_sub_string.find("Rejeek");
  std::string sub_sub_sub_sub_string =
      sub_sub_sub_string.substr(position_of_rejeek + 6);
  sub_sub_sub_string.erase(sub_sub_sub_string.begin() + position_of_rejeek + 6,
                           sub_sub_sub_string.end());
  return (
      html_format_content + jeek_to_be_shown->get_author()->get_username() +
      sub_string + "text:" + jeek_to_be_shown->get_text() +
      "\ntags: " + get_all_tags(jeek_to_be_shown) +
      "\nmentions: " + get_all_mentions(jeek_to_be_shown) +
      "\n\n #Likes: " + std::to_string(jeek_to_be_shown->get_like_number()) +
      "  #Rejeeks: " + std::to_string(jeek_to_be_shown->get_rejeek_number()) +
      sub_sub_string + " " + jeek_to_be_shown->get_id() + sub_sub_sub_string +
      " " + jeek_to_be_shown->get_id() + sub_sub_sub_sub_string);
}
