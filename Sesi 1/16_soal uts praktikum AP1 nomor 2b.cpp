//menampilkan kata menjadi angka
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string kata;

	cout << "     MASUKKAN 0 ATAU 1      \n";
	cout << "============================\n";

	cout << "masukkan kata= ";
	cin >> kata;
	if (kata == "nol")
	{
		cout << "0" << endl;
	}
	else if (kata == "satu")
	{
		cout << "1 " << endl;
	}
	else
	{
		cout << "Kata katanya gak ada!!!" << endl;
	}
	cout << endl;

	system("pause");
}