#include "functions.hpp"

Reply* Network::find_reply (string id) {
	for ( int i = 0 ; i < replies.size() ; i++ ) 
		if ( replies[i]->get_id() == id ) return replies[i];
	return NULL ;
}

vector<User*> Network::get_users()
{
	return users;
}

void Network::add_reply(Reply * new_reply) 
{
	replies.push_back(new_reply);
}

void Network::add_comment ( Comment * new_comment ) 
{
	comments.push_back ( new_comment );
}

void Network::add_jeeks ( Jeek * new_jeek ) 
{
	all_jeeks.push_back(new_jeek);
}

void Network::add_hashtag ( Hashtag* new_hashtag) 
{
	hashtags.push_back(*new_hashtag);
}

bool Network::username_not_used ( string username_to_be_checked ) 
{
	for ( int i = 0 ; i < users.size() ; i++ ) 
		if ( users[i] -> get_username() == username_to_be_checked ) return false;
	return true;
}

void Network::signup ()  
{
	string username , display_name , password ;
	cin >> username >> display_name >> password ;
	User *new_user = new User;
	new_user -> set_features ( username , display_name , password );
	if ( username_not_used (username) != true ) {
		cout << "this username is used before.Signing up failed" << endl;
		return;
	}
	cout << "user succesfully signed up" << endl;
	users.push_back(new_user);
}

void Network::search_users(string content) 
{
	content.erase ( content.begin() , content.begin() + 2 );
	for ( int i = 0 ; i < users.size() ; i ++ ) 
		if ( users[i] -> get_username() == content ) {
			users[i] -> show_jeeks();
			return ;
		}
	cout << "user doesn't exist" << endl;
}

void Network::search_hashtags ( string content ) 
{
	content.erase(content.begin() , content.begin() + 2 ) ;
	for ( int i = 0 ; i < hashtags.size() ; i++ ) 
		if ( hashtags[i].get_text() == content ) {
			hashtags[i].show_info();
			return;
		}
	cout << "Hashtag doesn't exist" << endl;
}

void Network::search () 
{
	string content;
	getline ( cin , content );
	if ( content[1] == '@') search_users(content);
	else if ( content[1] == '#' ) search_hashtags(content);
}

void Network::add_rejeek (string jeek_id) 
{
	Jeek * new_jeek = new Jeek;
	new_jeek->set_rejeek( current_user , find_jeek ( jeek_id , *this ) );
	all_jeeks.push_back(new_jeek);
	current_user -> add_rejeeks(new_jeek);
	cout << "jeek was succesfully rejeeked" << endl;
}

void Network::choose_action_after_login ( string command ) 
{
	if ( command == "jeek" ) current_user -> add_jeek(users,*this);
	else if ( command == "search"  ) search();
	else if ( command == "comment" ) current_user -> add_comment(*this);
	else if ( command == "reply" ) current_user -> add_reply(*this);
	else if ( command == "showReply" || command == "showComment" || command == "showJeek" ) show(command);
	else if ( command == "follow" || command == "unfollow" ) follow_unfollow(command);
	else if ( command == "like" || command == "dislike" ) like_dislike(command);
	else if ( command == "notifications" ) current_user -> show_notifications();
	else if ( command == "logout" ) throw command ;
	else if ( command == "rejeek" ) { 
		string jeek_id ; 
		cin >> jeek_id ;
		add_rejeek(jeek_id); 
	}
	else cout << "wrong command.PLease try again" << endl;
}

void Network::user_logined () 
{
	cout << current_user -> get_username() << " succesfully logined " << endl;
	string command ;
	while (true) {
		cout << "enter your command" << endl;
		cin >> command ;
		choose_action_after_login ( command ) ;
	}
}

void Network::login () 
{
	string userName , passWord;
	cin >> userName >> passWord ;
	if ( find_user(userName , passWord , users ) < 0 ) {
		cout << "Invalid information" << endl;
		return;
	}
	current_user = users[find_user ( userName , passWord , users )];
	user_logined ();
}

void Network::choose_action ( string command  ) 
{
	if ( command == "signup" )  signup();
	else if ( command == "login" ) login();
	else throw command;
}

vector<Reply*> Network::get_replies () 
{ 
	return replies ; 
}

void Network::follow_unfollow ( string command ) 
{
	string following_username ;
	cin >> following_username ;
	if ( find_user ( following_username , "" , users ) < 0 ) {
		cout << "user you wanted to follow/unfollow doesn't exist" << endl;
		return ;
	}
	User* following_unfollowing_user = ( users[ find_user ( following_username , "" , users ) ]) ;
	if ( command == "follow" ) 
		if ( current_user -> following_does_not_exist(following_unfollowing_user) == true ) {
			current_user -> follow(following_unfollowing_user);
			following_unfollowing_user -> add_follower (current_user);
			cout << "user succesfully followed" << endl;
		}
	else if ( command == "unfollow" ) 
		if ( current_user -> following_does_not_exist (following_unfollowing_user) == false ) { 
			current_user -> unfollow(following_unfollowing_user);
			following_unfollowing_user -> delete_follower ( current_user );
			cout << "user succesfully unfollowed" << endl;
		}
}

void Network::like_dislike (string command ) 
{
	string liked_jeek_id ;
	cin >> liked_jeek_id ;
	Jeek* jeek_to_get_liked_disliked = find_jeek ( liked_jeek_id , *this ); 
	if ( jeek_to_get_liked_disliked == NULL ) {
		cout << "jeek you wanted to like/dislike doesn't exist" << endl;
		return ;
	}
	if ( command == "like" ) 
		if ( current_user -> like_does_not_exist(jeek_to_get_liked_disliked) == true ) {
			current_user -> like(jeek_to_get_liked_disliked);
			cout << "jeek succesfully liked" << endl;
			jeek_to_get_liked_disliked -> get_author() -> add_notifications ( current_user -> get_username() + " liked " + jeek_to_get_liked_disliked -> get_id());
		}
		else cout << "this jeek was liked by you before so you can't like it anymore" << endl;
	else if ( command == "dislike" ) 
		if ( current_user -> like_does_not_exist(jeek_to_get_liked_disliked) == false ) {
			current_user -> dislike(jeek_to_get_liked_disliked);
			cout << "jeek succesfully disliked" << endl;
			jeek_to_get_liked_disliked -> get_author() -> add_notifications ( current_user -> get_username() + " disliked " + jeek_to_get_liked_disliked -> get_id());
		}
		else cout << "this jeek is not liked by you so you can't dislike it" << endl;
}

vector<Jeek*> Network::get_jeeks () 
{
	return all_jeeks;
}

vector<Comment*> Network::get_comments () 
{
	return comments;
}

void Network::show(string command) {
	string id;
	cin >> id;
	if ( command == "showReply" ) {
		Reply * reply_to_get_shown = find_reply (id);
		if ( reply_to_get_shown == NULL ) {
			cout << "the reply you wanted to be shown doesn't exist" << endl;
			return ;
		}
		reply_to_get_shown -> show_full_info () ;
	}
	else if ( command == "showComment" ) {
		Comment* comment_to_get_shown = find_comment (id , *this);
		if ( comment_to_get_shown == NULL ) {
			cout << "the comment you wanted to be shown doesn't exist" << endl;
			return ;
		}
		comment_to_get_shown -> show_full_info();
	}
	else {
		Jeek * jeek_to_get_shown = find_jeek ( id , *this ) ;
		if ( jeek_to_get_shown == NULL ) {
			cout << "the jeek you wanted to be shown doesn't exist" << endl;
			return ;
		}
		jeek_to_get_shown -> show_full_info();
	}
}

User* Network::user_exists ( string username, string password ) 
{
	for ( int i = 0 ; i < users.size() ; i++ )
		if ( users[i] -> get_username() == username && users[i] -> get_password() == password ) return users[i];
	return NULL ;
}

void Network::set_user ( User* user ) 
{
	current_user = user ;
}

void Network::add_user ( string username , string password , string display_name )
{
	User* new_user = new User;
	new_user -> set_features ( username , display_name , password );
	users.push_back(new_user);
}

User* Network::get_current_user () 
{
	return current_user ;
}