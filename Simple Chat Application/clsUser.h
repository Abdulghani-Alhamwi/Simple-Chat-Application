#pragma once
#include <iostream>
#include<map>
#include<vector>
#include "clsString.h"

using namespace std;

class clsUser
{
private:
	enum enStatus;
	string _UserName="";
	enStatus _Status = OffLine;
	
	map<string,string> _RecievedMessages;
	map<string,string> _SentMessages;

	vector<string>_ListUsers;

public:
	enum enStatus { OffLine = 0, Online = 1 };

	clsUser(string UserName , enStatus Status)
	{
		if(!_ListUsers.empty())
		{
			for (string s : _ListUsers)
			{
				if (UserName == s)
				{
					cout << "User already exist " << UserName;
					return;
				}
			}
		}
		_Status = Status;

		_UserName = UserName;
		
	}

	string GetStatus()
	{
		return (_Status == enStatus::OffLine) ? "Offline" : "Online";
	}

	/*
	1]Pair is a simple Data Structure in C++.
	2]It holds exactly two values -> not less and not more.
	2]it can hold any types -> they don't have to be the same and they can be the same		
	*/

	pair<string,string> SentMessage(string Title,string Body)
	{
		_SentMessages[Title] = Body;

		return { Title,Body };
	}
	
	void RecieveMessage(string Title,string Body)
	{
		if(_Status==Online)
		{
			_RecievedMessages[Title] = Body;
		}

	}

	void RetriveAllSentMessages()
	{
		if (_UserName!="")
		{
			if (!_SentMessages.empty())
			{
				cout << "\n\t\t\t\tAll Sent Messages from  : " << _UserName << "\n";
				cout << "\n\t\t--------------------------------------------------------------------\n";
				for (const auto& i : _SentMessages)
				{
					cout << "\n\t\tTitle : " << i.first << "\n\n\t\tBody: " << i.second << "\n";
					cout << endl;
				}
			}
			else
			{
				cout << "\n\t\t--------------------------------------------------------------------\n";
				cout << "\n\t\t\t\t\tNo Sent Messages\n";
				cout << "\n\t\t--------------------------------------------------------------------\n";
			}
		}
	
	}

	void RetriveAllRecievedMessages()
	{
		if(_UserName != "")
		{
			if (!_RecievedMessages.empty())
			{
				cout << "\n\t\t\t\tAll Recieved Messages to : " << _UserName << "\n";
				cout << "\n\t\t--------------------------------------------------------------------\n";
				for (const auto& i : _RecievedMessages)
				{
					cout << "\n\t\tTitle : " << i.first << "\n\n\t\tBody: " << i.second << "\n";
					cout << endl;
				}
			}
			else
			{
				cout << "\n\t\t--------------------------------------------------------------------\n";
				cout << "\n\t\t\t\t\tNo Recieved Messages\n";
				cout << "\n\t\t--------------------------------------------------------------------\n";
			}

		}
		else
			cout << "\nyou dont have permission to do that\n";
	}

	void ChangeStatus(enStatus Status)
	{
		_Status = Status;
	}

};

