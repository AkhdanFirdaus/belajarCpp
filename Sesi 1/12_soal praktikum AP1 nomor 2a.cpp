#include <iostream>
using namespace std;

int main()
{
	int hari, pilih;

	cout << "Keterangan Hari= \n";
	cout << "1= Senin 2= Selasa 3= Rabu 4= Kamis\n";
	cout << "5= Jumat 6= Sabtu 7= Minggu\n";
	cout << "===================================\n\n";

	cout << "masukkan angka hari= ";
	cin >> pilih;

	if (pilih == 1)
	{
		cout << "ini adalah hari SENIN\n";
	}
	else if (pilih == 2)
	{
		cout << "ini adalah hari SELASA\n";
	}
	else if (pilih == 3)
	{
		cout << "ini adalah hari RABU\n";
	}
	else if (pilih == 4)
	{
		cout << "ini adalah hari KAMIS\n";
	}
	else if (pilih == 5)
	{
		cout << "ini adalah hari JUM'AT\n";
	}
	else if (pilih == 6)
	{
		cout << "ini adalah hari SABTU\n";
	}
	else if (pilih == 7)
	{
		cout << "ini adalah hari MINGGU\n";
	}
	else
	{
		cout << "DASAR!!!!!! Bid'ah kamu ini!!!\n";
	}
	cout << endl;

	system("pause");
}