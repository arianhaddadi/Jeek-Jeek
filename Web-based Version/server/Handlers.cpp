#include "Handlers.hpp"

LoginHandler::LoginHandler(Network *new_network) { network = new_network; }

Response *LoginHandler::callback(Request *req) {
  int random_number = generate_session_Id();
  Response *res = new Response();
  std::string username = req->getBodyParam("username");
  std::string password = req->getBodyParam("password");
  res->setHeader("Content-Type", "text/html");
  if (network->user_exists(username, password) != nullptr) {
    network->user_exists(username, password)
        ->set_session_Id(std::to_string(random_number));
    res->setBody(
        insert_jeeks_to_home(network->user_exists(username, password)));
  } else
    res->setBody(readFile("htmlFiles/loginerror.html"));
  res->setSessionId(std::to_string(random_number));
  return res;
}
HomepageHandler::HomepageHandler(Network *new_network) {
  network = new_network;
}

Response *HomepageHandler::callback(Request *req) {
  Response *res = new Response();
  res->setHeader("Content-Type", "text/html");
  User *user = network->find_user_by_sessionId(req->getSessionId());
  if (user == nullptr) {
    res->setBody(readFile("htmlFiles/loginerror.html"));
  } else {
    res->setBody(insert_jeeks_to_home(user));
  }
  return res;
}

SignupAttemptHandler::SignupAttemptHandler(Network *new_network) {
  network = new_network;
}

Response *SignupAttemptHandler::callback(Request *req) {
  Response *res = new Response();
  std::string name = req->getBodyParam("name");
  std::string username = req->getBodyParam("username");
  std::string password = req->getBodyParam("password");
  res->setHeader("Content-Type", "text/html");
  if (username.size() != 0 && name.size() != 0 && password.size() != 0 &&
      network->username_not_used(username)) {
    network->add_user(username, password, name);
    res->setBody(readFile("htmlFiles/Successsignup.html"));
  } else
    res->setBody(readFile("htmlFiles/signuperror.html"));
  return res;
}

SearchHandler::SearchHandler(Network *new_network) { network = new_network; }

Response *SearchHandler::callback(Request *req) {
  Response *res = new Response();
  std::string searched_content = req->getBodyParam("searched_content");
  res->setHeader("Content-Type", "text/html");
  if (searched_content[0] == '@')
    res->setBody(show_searched_username(network, searched_content));
  else if (searched_content[0] == '#')
    res->setBody(show_searched_hashtags(network, searched_content));
  else
    res->setBody(readFile("htmlFiles/home.html"));
  return res;
}
JeekDetailHandler::JeekDetailHandler(Network *new_network) {
  network = new_network;
}

Response *JeekDetailHandler::callback(Request *req) {
  Response *res = new Response();
  std::string jeek_id = req->getBodyParam("details");
  res->setBody(show_jeek_details_html(find_jeek(jeek_id, *network)));
  res->setHeader("Content-Type", "text/html");
  return res;
}

SuccessfullLikeDislikeHandler::SuccessfullLikeDislikeHandler(
    Network *new_network) {
  network = new_network;
}

Response *SuccessfullLikeDislikeHandler::callback(Request *req) {
  User *liker = network->find_user_by_sessionId(req->getSessionId());
  Response *res = new Response();
  std::string jeek_id = req->getBodyParam("details");
  jeek_id.erase(jeek_id.begin(), jeek_id.begin() + 13);
  if (liker->like_does_not_exist(find_jeek(jeek_id, *network)) == true) {
    liker->like(find_jeek(jeek_id, *network));
    res->setBody(readFile("htmlFiles/Successlike.html"));
  } else {
    liker->dislike(find_jeek(jeek_id, *network));
    res->setBody(readFile("htmlFiles/Successfulldislike.html"));
  }
  res->setHeader("Content-Type", "text/html");
  return res;
}
SuccessfulRejeekHandler::SuccessfulRejeekHandler(Network *new_network) {
  network = new_network;
}

Response *SuccessfulRejeekHandler::callback(Request *req) {
  Response *res = new Response();
  std::string jeek_id = req->getBodyParam("details");
  jeek_id.erase(jeek_id.begin(), jeek_id.begin() + 7);
  network->set_user(network->find_user_by_sessionId(req->getSessionId()));
  network->add_rejeek(jeek_id);
  res->setBody(readFile("htmlFiles/Successrejeek.html"));
  res->setHeader("Content-Type", "text/html");
  return res;
}
