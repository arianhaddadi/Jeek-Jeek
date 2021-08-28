#include "Handlers.hpp"

using namespace std;

int main( int argc , char **argv ) {
  Network* network = new Network;
  add_jeeks_users(network);
  try {
    Server server(argc > 1 ? atoi(argv[1]) : 5000);
    server.get("/", new ShowPage("htmlFiles/Jeek_Jeek.html"));
    server.get("/home" , new HomepageHandler(network) );
    server.get("/signup", new ShowPage("htmlFiles/signup.html"));
    server.get("/login_page", new ShowPage("htmlFiles/login.html"));
    server.get("/1.jpg", new ShowImage("htmlFiles/1.jpg"));
    server.post("/login", new LoginHandler(network));
    server.post("/login_page", new ShowPage("htmlFiles/login.html"));
    server.post("/signup", new ShowPage("htmlFiles/signup.html"));
    server.post("/signupAttempt", new SignupAttemptHandler(network));
    server.post("/search", new SearchHandler(network));
    server.post("/jeek_details" , new JeekDetailHandler(network)) ;
    server.post("/likeDislike_successful" , new SuccessfullLikeDislikeHandler(network)) ;
    server.post("/rejeek_successful" , new SuccessfulRejeekHandler(network)) ;
    server.run();
  } catch (Server::Exception e) {
    cout << e.getMessage() << endl;
  }
}
