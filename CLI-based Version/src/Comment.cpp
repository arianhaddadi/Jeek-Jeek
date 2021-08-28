#include "functions.hpp"

void Comment::add_reply ( Reply* new_reply ) 
{
	replies.push_back(new_reply);
}

void Comment::set_features ( string content , string id , User* comment_author ) 
{
	text = content ;
	author = comment_author ;
	Id = "commy" + id ;
}

string Comment::get_id () 
{
	return Id ;
}

void Comment::show_full_info() 
{
	cout << author -> get_display_name() << endl;
	cout << text << endl ;
	cout << "replies:" << endl;
	for ( int i = 0 ; i < replies.size() ; i++ )
		cout << replies[i] -> get_id() << endl ;
}

User* Comment::get_author() 
{
 	return author ;
}
