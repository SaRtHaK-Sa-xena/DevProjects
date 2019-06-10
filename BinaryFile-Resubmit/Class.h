#pragma once
using namespace std;

class Record
{
private:
	int ID;
	char User[50]; //10
	char Title[50];
	char Date[50];

public:
	void setID(int n)
	{
		ID = n;
	}

	int getID()
	{
		return ID;
	}

	void setFullName(string name)
	{
		strcpy_s(User, name.c_str()); //sort of works
	}

	//Sets Copy To equal FullName's Contents
	void getFullName(char Copy[50])//10
	{
		//Copy[10] = fullName[10];
		strcpy_s(Copy, 50,User);//10
	}

	void setTitle(string m_Title)
	{
		strcpy_s(Title, m_Title.c_str());
	}

	void getTitle(char m_copyTitle[50])
	{
		strcpy_s(m_copyTitle, 50, Title);
	}


	void setDate(char dateSet[50])
	{
		strcpy_s(Date, dateSet);
	}

	void getDate(char copyDate[50])
	{
		strcpy_s(copyDate, 50, Date);
	}
};