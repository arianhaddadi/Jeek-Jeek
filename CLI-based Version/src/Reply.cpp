#include "functions.hpp"


void Reply::set_features ( User* replier , string reply_text ) 
{
	text = reply_text ;
	author = replier ;
	Id = "repl" + replier->get_username () + to_string(replier -> get_replies().size() ) ;
}

void Reply::show_full_info () 
{
	cout << author -> get_display_name () << endl;
	cout << text << endl;
	cout << "replies:" << endl;
	for ( int i = 0 ; i < replies.size () ; i++ ) 
		cout << replies[i] -> get_id() << endl;
}

string Reply::get_id() 
{
	return Id;
}

void Reply::add_reply ( Reply* new_reply ) 
{
	replies.push_back(new_reply);
}

