#ifndef _COMMENT_
#define _COMMENT_
#include "Reply.hpp"

class Comment 
{
public:
	void set_features (string , string , User * );
	string get_id () ;
	void add_reply(Reply*);
	void show_full_info() ;
	User* get_author() ;
private:
	User * author ;
	string Id ;
	string text;
	vector<Reply*> replies;
};

#endif