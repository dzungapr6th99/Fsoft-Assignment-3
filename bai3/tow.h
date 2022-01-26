/*Code by Nguyen Tuan Dung*/
#pragma once
#include<iostream>
#include<string>
using namespace std;
class person
{
private:
	string name;
	string ID;
	int age;
	int YearOfBirth;
public: 
	person(){}
	person(string name, string ID, int age, int YearOfBirth)
	{
		this->name = name;
		this->age = age;
		this->ID = ID;
		this->YearOfBirth = YearOfBirth;
	}
	~person(){}
	void getInfor()
	{
		cout << "Name: " << endl;
		getline(cin, name);
		cout << "ID: " << endl;
		getline(cin, ID);
		cout << "Age: " << endl;
		cin >> age;
		cout << "Year Of Birth: " << endl;
		cin >> YearOfBirth;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "ID: " << ID << endl;
		cout << "Age: " << age << endl;
		cout << "Year of birth: " << YearOfBirth << endl;
	}
	bool CheckPerson(string ID)
	{
		if (this->ID == ID)
			return true;
		else return false;
	}
};
class house
{
private:
	int NumberOfPartner;
	int HouseNumber;
	person* Partner;
public:
	house(){}
	void getInfor()
	{
		cout << "House Number: "<< endl;
		cin >> HouseNumber;
		cout << "How many partner?" << endl;
		cin >> NumberOfPartner;
		Partner = new person[NumberOfPartner];
		for (int i = 0; i < NumberOfPartner; i++)
		{
			Partner[i].getInfor();
		}
	}
	void display()
	{
		cout << "House number: " << HouseNumber << endl;
		cout << "List of partner: " << endl;
		for (int i = 0; i < NumberOfPartner; i++)
		{
			Partner[i].display();
		}
	}
	bool SearchPerson(string ID)
	{
		bool check = false;
		for (int i = 0; i <= NumberOfPartner; i++)
		{
			if (Partner[i].CheckPerson(ID))
			{
				Partner[i].display();
				break;
				check = true;
			}

		}
		return check;
	}
};
class tow
{
private:
	string name;
	house* h;
	int NumberOfHouse;
public:
	tow(){}
	void getInfor()
	{
		cout << "How many houses?" << endl;
		cin >> NumberOfHouse;
		h = new house[NumberOfHouse];
		for (int i = 0; i < NumberOfHouse; i++)
			h[i].getInfor();
	}
	void SearchPerson(string ID)
	{
		int count = 0;
		for (int i = 0; i < NumberOfHouse; i++)
		{
			if(h->SearchPerson(ID))
				break;
			count++;
		}
		if (count >= NumberOfHouse)
			cout << "Can not find";
	}
};

