#include <iostream>
using namespace std;

int main()
{
	int F, C;

	cout << " SELAMAT DATANG DI APLIKASI KONVERSI SUHU INI \n";
	cout << "==============================================\n";
	cout << "masukkan nilai suhu Fahrenheit= ";
	cin >> F;

	C = 5 * (F - 32) / 9;

	cout << "Suhu dalam derajat Celsius adalah= " << C << " Celsius\n";

	system("pause");
}