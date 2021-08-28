#ifndef _HASHTAG_
#define _HASHTAG_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Jeek;
class Like;
class Network;
class Comment;
class User;

class Hashtag  
{
public:
	void set_text (string content) ;
	void add_jeek ( Jeek &new_jeek );
	string get_text() ;
	void show_info();
	vector<Jeek *> get_jeeks();
private:
	vector<Jeek*> pointed_jeeks;
	string text;
};
#endif
