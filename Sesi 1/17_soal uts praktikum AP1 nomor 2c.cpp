//menampilkan angka ganjil dan angka genap
#include <iostream>
using namespace std;

int main()
{
	int angka;

	cout << "Masukkan angka= ";
	cin >> angka;

	if (angka % 2)
	{
		cout << "ganjil\n";
	}
	else if (angka == 0)
	{
		cout << "tidak ganjil dan tidak genap\n";
	}
	else
	{
		cout << "genap\n";
	}
	system("pause");
}