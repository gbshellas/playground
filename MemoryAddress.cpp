#include <iostream>

using namespace std;

void main()
{
	int a = 10;
	int &b = a;
	cout << "a = " << a << ", b = " << b << endl;

	b = 20;
	cout << "a = " << a << ", b = " << b << endl;

}