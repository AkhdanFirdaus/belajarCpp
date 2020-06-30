#include <iostream>
using namespace std;

int main()
{
	int x;

	cout << "masukkan bilangan apa saja = ";
	cin >> x;

	if (x > 0)
	{
		cout << "x is positif" << endl;
	}
	else if (x < 0)
	{
		cout << "x is negative" << endl;
	}
	else
	{
		cout << "x is nol" << endl;
	}

	system("pause");
}