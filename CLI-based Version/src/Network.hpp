#ifndef _NETWORK_
#define _NETWORK_
#include "Jeek.hpp"

class Network 
{
public:
	void signup();
	void login();
	bool username_not_used ( string ) ;
	void choose_action ( string );
	void user_logined ();
	void choose_action_after_login (string);
	void search();
	void show ( string );
	void follow_unfollow(string);
	void add_rejeek(string);
	void like_dislike(string);
	void add_hashtag(Hashtag *);
	void search_users ( string ) ;
	void search_hashtags ( string );
	void add_jeeks(Jeek *);
	vector<Jeek*> get_jeeks () ;
	vector<Comment*> get_comments () ;
	void add_comment( Comment* );
	void add_reply( Reply* ) ;
	Reply* find_reply (string id) ;
	vector<Hashtag> hashtags;
	vector<Reply*> get_replies () ;
	User* user_exists (string , string) ;
	void set_user ( User* );
	void add_user (string , string , string ) ;
	User* get_current_user () ;
	vector<User*> get_users();
private:
	User* current_user;
	vector<User*> users;
	vector<Comment*> comments;
	vector<Jeek*> all_jeeks;
	vector<Reply*> replies;
	
};
#endif