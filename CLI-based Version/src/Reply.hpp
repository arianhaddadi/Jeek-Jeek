#ifndef _REPLY_
#define _REPLY_
#include "Hashtag.hpp"

class Reply 
{
public:
	string get_id() ;
	void set_features (User* , string);
	void show_full_info () ;
	void add_reply ( Reply* );
private:
	User* author ;
	string Id ;
	string text ;
	vector<Reply*> replies;
};

#endif