#pragma once
using namespace std;

class Record
{
private:
	int ID;
	char User[20]; //10

	char Title[20];
	//string fullName;

public:
	void setID(int n)
	{
		ID = n;
	}

	int getID()
	{
		return ID;
	}

	//void setName(char name[20])//10
	//{
	//	strcpy_s(User, name);
	//}
	//void getName(char CopyArr[20])//10
	//{
	//	strcpy_s(CopyArr, 20, User);//10
	//}

	//Sets FullName to equal name entered
	void setFullName(string name)
	{
		strcpy_s(User, name.c_str()); //sort of works
	}

	//Sets Copy To equal FullName's Contents
	void getFullName(char Copy[20])//10
	{
		//Copy[10] = fullName[10];
		strcpy_s(Copy, 20,User);//10
	}

	void setTitle(string m_Title)
	{
		strcpy_s(Title, m_Title.c_str());
	}

	void getTitle(char m_copyTitle[20])
	{
		strcpy_s(m_copyTitle, 20, Title);
	}


};