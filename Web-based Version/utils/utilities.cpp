#include "utilities.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#define BUFFER_SIZE 4145152

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
  std::string html_format_content = readFile("htmlFiles/details.html");
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

char easytolower(char in) {
  if (in <= 'Z' && in >= 'A')
    return in - ('Z' - 'z');
  return in;
}

string tolower(string s) {
  std::transform(s.begin(), s.end(), s.begin(), easytolower);
  return s;
}

bool comp::operator()(const string &lhs, const string &rhs) const {
  return tolower(lhs) < tolower(rhs);
}

string readFile(const char *filename) {
  string s = "";
  char buffer[BUFFER_SIZE];
  ifstream infile(filename);
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

vector<string> split(string s, string delimiter) {
  vector<string> tokens;
  s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  size_t pos = 0;
  string token;
  while ((pos = s.find(delimiter)) != string::npos) {
    token = s.substr(0, pos);
    tokens.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  tokens.push_back(s);
  return tokens;
}

void printVector(vector<string> v) {
  for (string s : v)
    cout << s << endl;
}

string urlEncode(string const &str) {
  char encode_buf[4];
  string result;
  encode_buf[0] = '%';
  result.reserve(str.size());

  // character selection for this algorithm is based on the following url:
  // http://www.blooberry.com/indexdot/html/topics/urlencoding.htm

  for (size_t pos = 0; pos < str.size(); ++pos) {
    switch (str[pos]) {
    default:
      if (str[pos] >= 32 && str[pos] < 127) {
        // character does not need to be escaped
        result += str[pos];
        break;
      }
      // else pass through to next case
    case '$':
    case '&':
    case '+':
    case ',':
    case '/':
    case ':':
    case ';':
    case '=':
    case '?':
    case '@':
    case '"':
    case '<':
    case '>':
    case '#':
    case '%':
    case '{':
    case '}':
    case '|':
    case '\\':
    case '^':
    case '~':
    case '[':
    case ']':
    case '`':
      // the character needs to be encoded
      sprintf(encode_buf + 1, "%02X", str[pos]);
      result += encode_buf;
      break;
    }
  };
  return result;
}

string urlDecode(string const &str) {
  char decode_buf[3];
  string result;
  result.reserve(str.size());

  for (size_t pos = 0; pos < str.size(); ++pos) {
    switch (str[pos]) {
    case '+':
      // convert to space character
      result += ' ';
      break;
    case '%':
      // decode hexidecimal value
      if (pos + 2 < str.size()) {
        decode_buf[0] = str[++pos];
        decode_buf[1] = str[++pos];
        decode_buf[2] = '\0';
        result += static_cast<char>(strtol(decode_buf, nullptr, 16));
      } else {
        // recover from error by not decoding character
        result += '%';
      }
      break;
    default:
      // character does not need to be escaped
      result += str[pos];
    }
  }
  return result;
}

std::string getExtension(string filePath) {
  size_t pos = filePath.find_last_of(".");
  return filePath.substr(pos != string::npos ? pos + 1 : filePath.size());
}
