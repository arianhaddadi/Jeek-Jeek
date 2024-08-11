#include "../../Phase1/functions.hpp"
#include "../utils/utilities.hpp"
#include "server.hpp"

class LoginHandler : public RequestHandler {
  Network *network;

public:
  LoginHandler(Network *new_network);
  Response *callback(Request *req);
};

class HomepageHandler : public RequestHandler {
  Network *network;

public:
  HomepageHandler(Network *new_network);
  Response *callback(Request *req);
};

class SignupAttemptHandler : public RequestHandler {
  Network *network;

public:
  SignupAttemptHandler(Network *new_network);
  Response *callback(Request *req);
};

class SearchHandler : public RequestHandler {
  Network *network;

public:
  SearchHandler(Network *new_network);
  Response *callback(Request *req);
};

class JeekDetailHandler : public RequestHandler {
  Network *network;

public:
  JeekDetailHandler(Network *new_network);
  Response *callback(Request *req);
};

class SuccessfullLikeDislikeHandler : public RequestHandler {
  Network *network;

public:
  SuccessfullLikeDislikeHandler(Network *new_network);
  Response *callback(Request *req);
};

class SuccessfulRejeekHandler : public RequestHandler {
  Network *network;

public:
  SuccessfulRejeekHandler(Network *new_network);
  Response *callback(Request *req);
};
