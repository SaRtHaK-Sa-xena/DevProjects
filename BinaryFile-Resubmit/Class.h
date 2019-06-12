#pragma once
using namespace std;
#include <string>

class Record
{
private:
	int ID;
	char User[50]; 
	char Title[50];
	char Date[50];
	char Author[50];
	char BookStatus[50];

public:

	//===ID
	void setID(int n)
	{
		ID = n;
	}
	int getID()
	{
		return ID;
	}

	//====FullName
	void setFullName(string name)
	{
		strcpy_s(User, name.c_str());
	}
	//Sets Copy To equal FullName's Contents
	void getFullName(char Copy[50])//10
	{
		//Copy[10] = fullName[10];
		strcpy_s(Copy, 50,User);//10
	}

	//===Title
	void setTitle(string m_Title)
	{
		strcpy_s(Title, m_Title.c_str());
	}
	void getTitle(char m_copyTitle[50])
	{
		strcpy_s(m_copyTitle, 50, Title);
	}

	//===Date
	void setDate(char dateSet[50])
	{
		strcpy_s(Date, dateSet);
	}
	void getDate(char copyDate[50])
	{
		strcpy_s(copyDate, 50, Date);
	}

	//===Author
	void setAuthor(string m_Author)
	{
		strcpy_s(Author, m_Author.c_str());
	}
	void getAuthor(char m_copyAuthor[50])
	{
		strcpy_s(m_copyAuthor, 50, Author);
	}

	//===Status
	void setStatus(string m_Status)
	{
		strcpy_s(BookStatus, m_Status.c_str());
	}
	void getStatus(char m_copyStatus[50])
	{
		strcpy_s(m_copyStatus, 50, BookStatus);
	}

};