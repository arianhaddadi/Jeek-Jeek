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

void add_jeeks_users(Network *network) {
  network->add_user("a", "b", "c");
  Jeek *new_jeek = new Jeek();
  new_jeek->set_features("hello", "id", network->get_users()[0]);
  new_jeek->add_a_hashtag("heell", network);
  network->get_users()[0]->add_rejeeks(new_jeek);
  network->add_jeeks(new_jeek);
}

int generate_session_Id() {
  srand(time(nullptr));
  return rand() % 1000;
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
  int index_of_file_content = file_content.find("</body>");
  User *user = network->find_user(username.substr(1), "");
  if (user == nullptr) {
    return file_content +
           "<p style = \"text-align:center\"> No results were found </p>" +
           " </body> </html>";
  }
  file_content.erase(file_content.begin() + index_of_file_content,
                     file_content.end());
  for (int i = 0; i < user->get_jeeks().size(); i++) {
    file_content += jeek_in_html_generator(user->get_jeeks()[i]);
  }
  file_content += " </body>  </html> ";
  return file_content;
}

std::string insert_jeeks_to_home(User *user) {
  std::string file_content = readFile("htmlFiles/home.html");
  if (user->get_jeeks().empty())
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
  return html_format_content + jeek_to_be_shown->get_author()->get_username() +
         sub_string + "text:" + jeek_to_be_shown->get_text() +
         "\ntags: " + jeek_to_be_shown->get_tags_formatted() +
         "\nmentions: " + jeek_to_be_shown->get_mentions_formatted() +
         "\n\n #Likes: " + std::to_string(jeek_to_be_shown->get_like_number()) +
         "  #Rejeeks: " +
         std::to_string(jeek_to_be_shown->get_rejeek_number()) +
         sub_sub_string + " " + jeek_to_be_shown->get_id() +
         sub_sub_sub_string + " " + jeek_to_be_shown->get_id() +
         sub_sub_sub_sub_string;
}
