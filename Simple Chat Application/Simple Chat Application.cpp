// Simple Chat Application :
#include<iostream>
#include "clsUser.h"

using namespace std;

int main()
{
	clsUser User1("Abdulghani",clsUser::Online);
	clsUser User2("Ali",clsUser::Online);

	cout << "\t\tUser1 Status : " << User1.GetStatus()<<endl;
	cout << "\t\tUser2 Status : " << User2.GetStatus() <<"\n\n";
	
	pair<string, string>msg1 = User1.SentMessage("Welcome", "Hello Ali How are you.");
	//.First gives the first value storedd at the pair.
	//.second gives the second value stored at the pair.

	pair<string, string> msg2 = User1.SentMessage("Our App:", "this is our simple Chat App.");

	User2.RecieveMessage(msg1.first,msg1.second);
	User2.RecieveMessage(msg2.first, msg2.second);

	User2.RetriveAllRecievedMessages();
	User2.RetriveAllSentMessages();


	pair<string, string>msg3 = User2.SentMessage
	("Welcome", "Hello Abdulghani How are you , am fine thank you for asking");

	pair<string, string>msg4 = User2.SentMessage
	("Amazing", "This is a very good project that enhances our understanding for Data Structure and OOP.");

	User1.RecieveMessage(msg3.first,msg3.second);
	User1.RecieveMessage(msg4.first,msg4.second);

	User1.RetriveAllRecievedMessages();
	User1.RetriveAllSentMessages();
	
	User2.ChangeStatus(clsUser::OffLine);
	cout << "\n\t\tUser2 Status after change: " << User2.GetStatus() << endl;

	
	system("pause > 0");
	return 0;
}