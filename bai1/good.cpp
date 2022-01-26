#include "good.h"
#include<iostream>;
#include<string>
using namespace std;
int main()
{
	Good a;
	a.input();
	ShipGood b = ShipGood(a);
	b.CalculateShippingPrice();
	b.payment();
	return 0;
}