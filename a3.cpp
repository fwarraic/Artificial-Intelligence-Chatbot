// a3.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <Fazal Dad Warraich>
// St.# : <301319108>
// Email: <fwarraic@sfu.ca>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include "cmpt_error.h"    // These are the only permitted includes!
#include "Chatbot.h"       //
#include <iostream>        // Don't include anything else.
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <cassert>

using namespace std;

// Chatbot 1 (Mirrored Replies)
class Mirror_bot : public Chatbot
{
private:
	string mbot;
	string reply;
public:
	Mirror_bot(const string& name, const string& getReply)
	: mbot(name), reply(getReply)
	{
	}

	string name() const { return mbot; }
	
	void tell(const string& s)
	{
		reply = s;
	}

	string get_reply() { return reply; }

};

// Chatbot 2 (Random Replies)
class Random_bot : public Chatbot
{
private:
	string rbot;
	vector<string> v;
public:
	Random_bot(const string& name, const vector<string>& getReply)
	: rbot(name), v(getReply)
	{
		if (getReply.size() < 1)
		{
			cmpt::error("vector must have atleast one word\n");
		}
	}

	string name() const { return rbot; }
	
	void tell(const string& s)
	{
		const int MAX_NUM = v.size();
		int randomNum;
		srand(clock());
		randomNum = rand() % MAX_NUM;
		v[randomNum] = s;
	}

	string get_reply() 
	{
		const int MAX_NUM = v.size();
		int randomNum;
		srand(clock());
		randomNum = rand() % MAX_NUM; 
		return v[randomNum];
	}

};

// Chatbot 3 (The User)
class User_bot : public Chatbot
{
private:
	string ubot;
	string reply;
public:
	User_bot(const string& name)
	: ubot(name)
	{
	}

	string name() const { return ubot; }
	
	void tell(const string& s)
	{
		reply = s;
		cout << s;
		cout << "\n";
	}

	string get_reply() 
	{
		cout << "Please enter a line of text: ";
		getline(cin,reply);
		return reply; 
	}

};

// Chatbot 4 (Current Time and Date)
class Datetime_bot : public Chatbot
{
private:
	string dtbot;
	vector<string> v;
	string reply;
public:
	Datetime_bot(const string& name, const vector<string> &getReply)
	: dtbot(name), v(getReply)
	{
		
	}

	string name() const { return dtbot; }
	
	void tell(const string& s)
	{
		cout << s;
		cout << "\n";

		//if (/* last string told s == date || time */)
		//{
			auto start = std::chrono::system_clock::now();
    		auto end = std::chrono::system_clock::now();

    		std::chrono::duration<double> elapsed_seconds = end-start;
    		std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    		std::cout << "The Date and time is: " << std::ctime(&end_time) << "\n";
		//}
		//else
		//{
		//	reply = s;
		//}


		
	}

	string get_reply() 
	{
    	const int MAX_NUM = v.size();
		int randomNum;
		srand(clock());
		randomNum = rand() % MAX_NUM; 
		return v[randomNum];
	}

};

// Chatbot 5 (Smart Bot)
class Smart_bot : public Chatbot
{
private:
	string sbot;
	vector<string> v;
public:
	Smart_bot(const string& name, const vector<string>& getReply)
	: sbot(name), v(getReply)
	{
		if (getReply.size() < 1)
		{
			cmpt::error("vector must have atleast one word\n");
		}
	}

	string name() const { return sbot; }
	
	void tell(const string& s)
	{
		const int MAX_NUM = v.size();
		int randomNum;
		srand(clock());
		randomNum = rand() % MAX_NUM;
		v[randomNum] = s;
	}

	string get_reply() 
	{
		const int MAX_NUM = v.size();
		int randomNum;
		srand(clock());
		randomNum = rand() % MAX_NUM; 
		return v[randomNum];
	}

};


void converse(Chatbot* a, Chatbot* b, int max_turns = 50) {
  for(int turn = 1; turn <= max_turns; turn++) {
    string a_msg = a->get_reply();
    cout << "(" << turn << ") " << a->name() << ": " << a_msg << "\n";

    turn++;
    if (turn > max_turns) return;

    b->tell(a_msg);
    string b_msg = b->get_reply();

    cout << "(" << turn << ") " << b->name() << ": " << b_msg << "\n";
    a->tell(b_msg);
  } // for
}



int main() 
{
	Smart_bot sbot("Eve", {"My name is Eve.", "I am fine.", "How are you?", 
					"I don't understand.", "Tell me about the weather?", "Ok."});
	User_bot user("Fazal");
	converse(&sbot, &user);mail
}