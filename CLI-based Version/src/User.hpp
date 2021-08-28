#ifndef _USER_
#define _USER_
#include "Comment.hpp"


class User {
public:
	void set_features ( string  , string  , string ) ;
	string get_username () ;
	string get_password () ;
	string get_display_name () ;
	void add_jeek( vector<User*> &users , Network& );
	void add_comment(Network &);
	void add_reply(Network &);
	void show_notifications();
	void show_jeeks () ;
	void add_rejeeks(Jeek *);
	vector<Jeek*> get_jeeks() ;
	void unfollow (User*) ;
	int find_following_index (User*) ;
	void follow (User*) ;
	bool following_does_not_exist (User*) ;
	vector<Reply*> get_replies() ;
	bool like_does_not_exist (Jeek*);
	void like(Jeek*);
	int find_likes_index (Jeek*);
	void dislike (Jeek* );
	void add_notifications (string) ;
	vector<User*> get_followings () ;
	void add_follower (User*) ;
	int find_follower_index (User*) ;
	void delete_follower (User*);
	void add_notifications_for_followers_after_jeek () ;
	void set_session_Id (string);
	string get_session_id();
private:
	vector<Jeek*> jeeks;
	vector<User*> followings;
	vector<User*> followers ;
	vector<Comment*> comments;
	vector<Reply*> replies ;
	vector<Jeek*> likes ;
	vector<string> notifications;
	string username;
	string display_name;
	string password;
	string session_Id ;
};
#endif
