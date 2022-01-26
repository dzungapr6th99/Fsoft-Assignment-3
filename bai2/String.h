/*Code by Nguyen Tuan Dung*/
#pragma once
#include<iostream>
using namespace std;
class String
{
public:
	char* c;
	int size;
public:
	String() {}
	String(char* d)
	{
		*this->c = *d;
		int i = 0;
		while (c[i] != NULL)
			i++;
		this->size = i;
	}
	~String()
	{
		this->c = NULL;
	}
	int length()
	{
		int i = 0;
		while (c[i] != NULL)
			i++;
		return i;
	}
	String inverse()
	{
		char* d = new char[this->size];
		int di = 0, ci = this->size;
		while (ci > 0)
		{
			d[di] = this->c[ci - 1];
			ci--;
			di++;
		}
		String b;
		b.c= d;
		return b;
	}
	bool operator == (String s)
	{
		if (this->size != s.size)
			return false;
		else
		{
			int i = 0;
			while (i < this->size && this->c[i] == s.c[i])
				i++;
			if (i == s.size)
				return true;
			else return false;
		}
	}
	char &operator [](int index)
	{
		if (index >= 0 && index <= this->size)
			return c[index];
		else cout<<"Invalid index";
	}
	friend String operator +(String s1, String s2)
	{
		String b;
		b.c = new char[s1.size + s2.size];
		b.size = s1.size + s2.size;
		for (int i = 0; i < s1.size; i++)
			b.c[i] = s1.c[i];
		int j = 0;
		for (int i = s1.size; i < b.size; i++)
		{
			b.c[i] = s2.c[j];
			j++;
		}
		return b;
	}
	String copy( int begin, int end)
	{
		String b;
		if (end >= this->size - 1 || begin < 0)
		{
			cout << "Invalid Value";
		}
		else
		{
			int size = end - begin;
			b.c = new char[size];
			for (int i = 0; i < b.size; i++)
			{
				b.c[i] = this->c[begin + i];
			}
		}
			return b;
	}
	String erase(int begin, int end)
	{
		String b;
		String a;
		String c;
		a.c = this->c;
		b= a.copy(0, begin);
		c = a.copy(end, a.size);
		b = b + c;
		return b;
	}
	friend ostream& operator<<(ostream& os, const String& s)
	{
		os << s.c;
		return os;
	}

	friend istream& operator>>(istream& is, String& s)
	{
		s.size = 50;
		s.c = new char[s.size];
		is.getline(s.c, s.size);
		s.size = s.length();
		return is;
	}

};

