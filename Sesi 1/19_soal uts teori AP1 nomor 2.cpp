//soal uts teori nomor 2
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;

	cout << " SELAMAT DATANG DI APLIKASI KONVERSI SUHU INI \n";
	cout << "==============================================\n";

	cout << "Masukkan Nilai Awal A= ";
	cin >> a;
	cout << "Masukkan Nilai Awal B= ";
	cin >> b;
	cout << endl;

	cout << "Setelah Di Tukar..." << endl;

	c = a;
	a = b;
	b = c;

	cout << "Nilai A= " << a << endl;
	cout << "Nilai B= " << b << endl;

	system("Pause");
}