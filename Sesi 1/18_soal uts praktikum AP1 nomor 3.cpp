#include <iostream>
using namespace std;

int main()
{
	int baris, kolom, hitung = 1;

	cout << "    Selamat datang    \n";
	cout << "======================\n";

	cout << "masukkan jumlah baris= ";
	cin >> baris;
	cout << "masukkan jumlah kolom= ";
	cin >> kolom;
	cout << endl;

	for (int i = 0; i < baris; i++)
	{
		for (int j = 0; j < kolom; j++)
		{
			cout << hitung << " ";
			hitung += baris;
		}
		hitung = i + 2;
		cout << endl;
	}
	baris = 0;
	kolom = 0;

	system("pause");
}