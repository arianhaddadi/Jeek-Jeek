#include "functions.hpp"

void Jeek::show_full_info() 
{
	cout << author -> get_display_name () << endl;
	cout << text << endl ;
	for ( int i = 0 ; i < hashtags.size() ; i++ )
		cout << "#" << hashtags[i] -> get_text () << endl ;
	for ( int i = 0 ; i < mentions.size() ; i++ )
		cout << "@" << mentions[i] -> get_username() << endl ;
	cout << "Likes " << like_number << endl << "Rejeeks " << rejeek_number << endl << "Comments:" << endl ;
	for ( int i = 0 ; i < comments.size() ; i++ ) 
		cout << comments[i] -> get_id() << endl ;
}

void Jeek::set_features ( string jeek_text , string id , User* jeek_author ) 
{
	this -> set_text (jeek_text);
	Id = id ;
	author = jeek_author ;
	like_number = 0 ;
	rejeek_number = 0 ;
}

void Jeek::add_comment(Comment * new_comment) 
{
	comments.push_back ( new_comment );
}

string Jeek::get_text () 
{
	return text ; 
}

User* Jeek::get_author() 
{
 	return author ;
}

void Jeek::set_text ( string content ) 
{ 
	if ( content.size() > 140 ) content.erase(content.begin() + 140 , content.end() );
	text = content; 
}

void Jeek::get_disliked() 
{ 
	like_number -- ; 
}

void Jeek::get_liked() 
{ 
	like_number ++ ; 
}

vector<Hashtag*> Jeek::get_hashtags () 
{ 
	return hashtags ;
}

vector<User*> Jeek::get_mentions() 
{ 
	return mentions ; 
}

void Jeek::add_rejeek_number() 
{ 
	rejeek_number++; 
}

string Jeek::get_id() 
{
	return Id ; 
}

void Jeek::set_rejeek (User *rejeeker , Jeek* rejeeked_jeek ) 
{
	if (rejeeked_jeek == NULL ) {
		cout << "the jeek you want to rejeek doesn't exist" << endl;
		return;
	}
	text = "Rejeeked:" + rejeeked_jeek -> get_text() ;
	Id = rejeeker -> get_username() + to_string (rejeeker -> get_jeeks().size() );
	author = rejeeker ;
	hashtags = rejeeked_jeek->get_hashtags();
	mentions = rejeeked_jeek->get_mentions();
	rejeeked_jeek->add_rejeek_number();
	rejeeked_jeek -> author -> add_notifications ( rejeeker -> get_username() + " rejeeked " + rejeeked_jeek -> get_id() ) ;
}

void Jeek::show_after_search() 
{
	cout << Id << " " << author->get_display_name() << endl << text << endl << endl ;
}

void Jeek::mention(string content , vector<User*> &all_users ,User* mentioner ) {
	if ( find_user (content , "" , all_users ) < 0 ) {
		cout << "user you wanted to mention doesn't exist" << endl;
		return;
	}
	User * mentioned_user = all_users [ find_user ( content , "" , all_users ) ];
	mentions.push_back(mentioned_user);
	mentioned_user -> add_notifications ( mentioner -> get_username() + " mentioned you in " + this -> get_id() );
}

void Jeek::add_a_hashtag ( string content , Network & network ) 
{
	if ( find_hashtag ( content , network ) == NULL ) { 
		Hashtag *new_hashtag = new Hashtag;
		new_hashtag->set_text ( content );
		new_hashtag->add_jeek(*this);
		hashtags.push_back(new_hashtag);
		network.add_hashtag (new_hashtag);
	} 
	else {
		Hashtag* hashtag = find_hashtag ( content , network ) ;
		hashtag -> add_jeek ( *this ) ;
		hashtags.push_back(hashtag);
	}
}

int Jeek::get_like_number () 
{
	return like_number ;
}

int Jeek::get_rejeek_number() 
{
	return rejeek_number ;
}