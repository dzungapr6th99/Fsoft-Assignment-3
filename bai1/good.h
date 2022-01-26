/*Code by Nguyen Tuan Dung*/
#pragma once
#include <iostream>
#include<string>
using namespace std;
class Good
{
public:
	char Code[6];
	string Name;
	double Price;
	int NumberOfGood;
	double Value;
public:
	Good(){ }
	void input()
	{
		cout << "Input Code: " << endl;
		cin >> Code;
		cout << "Input Name: " << endl;
		cin >> Name;
		cout << "Input Price: " << endl;
		cin >> Price;
		cout << "Input Number: " << endl;
		cin >> NumberOfGood;
		Value = NumberOfGood * Price;
	}
	void output()
	{
		cout << "Code: " << Code << endl;
		cout << "Name: " << Name << endl;
		cout << "Price: " << Price << endl;
		cout << "Number of good: " << NumberOfGood << endl;
		cout << "Value: " << Value;
	}
	void payment()
	{
		cout <<"Payment: "<< Value;
	}
};
class ShipGood : private Good
{
private:
	double TransCost;
	double ShippingPrice;
public:
	ShipGood() {};
	ShipGood(Good a)
	{
		*this->Code = *a.Code;
		this->Name = a.Name;
		this->Price = a.Price;
		this->NumberOfGood = a.NumberOfGood;
		this->Value = a.Value;
	}
	void CalculateShippingPrice()
	{
		cout << "Input Shipping Price: ";
		cin >> ShippingPrice;
		TransCost = Value + ShippingPrice;
	}
	void payment()
	{
		cout << "Payment: " << TransCost;
	}
};

