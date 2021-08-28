#include "functions.hpp"



void Hashtag::add_jeek ( Jeek & jeek ) 
{
	Jeek * new_jeek = & jeek ;
	pointed_jeeks.push_back(new_jeek);
}

void Hashtag::show_info() 
{
	for ( int i = 0 ; i < pointed_jeeks.size() ; i++ ) 
		pointed_jeeks[i] -> show_after_search ();
}

string Hashtag::get_text() 
{
	return text ;
}

void Hashtag::set_text (string content) 
{ 
	text = content; 
}

vector<Jeek*> Hashtag::get_jeeks() 
{
	return pointed_jeeks ;
}