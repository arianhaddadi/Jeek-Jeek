#ifndef _JEEK_
#define _JEEK_
#include "User.hpp"

class Jeek 
{
public:
	string get_text () ;
	void set_text ( string content ) ;
	void mention(string , vector<User*> & users , User* );
	void add_a_hashtag (string , Network &);
	void show_after_search();
	void add_comment ( Comment * );
	string get_id() ;
	void set_rejeek (User * , Jeek* ) ;
	vector<Hashtag*> get_hashtags () ;
	vector<User*> get_mentions() ;
	void add_rejeek_number() ;
	void show_full_info() ;
	void get_liked() ;
	void get_disliked() ;
	User* get_author() ;
	void set_features ( string , string , User* );
	int get_like_number () ;
	int get_rejeek_number () ;
private:
	User* author;
	string text;
	string Id;
	vector<Comment*> comments;
	vector<Hashtag*> hashtags;
	vector<User*> mentions;
	int rejeek_number ;
	int like_number ;
};
#endif