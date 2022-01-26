#include "String.h"
#include<iostream>
using namespace std;
int main()
{
	String a;
	cin >> a;
	String b;
	cin >> b;
	cout << b.size << endl;
	String c = a + b;
	//String d = a.erase(3, 5);
	cout << c << endl;
	cout << c.size;
}