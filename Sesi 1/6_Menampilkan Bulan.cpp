#include <iostream>
using namespace std;

int main()
{
	int kode_bulan;

	cout << "selamat datang dan salam sejahtera!!\n\n";

	cout << "keterang kode bulan :\n\n";
	cout << "1 = januari 2 = februari   3 = maret   4 = april     5 = mei 6 = juni 7  = juli\n";
	cout << "8 = agustus 9 = september  10= oktober 11= november  12= desember\n\n";
	cout << "masukkan kode bulan : ";
	cin >> kode_bulan;
	cout << endl;

	if (kode_bulan == 1)
		cout << "ini bulan = Januari\n";
	else if (kode_bulan == 2)
		cout << "ini bulan = Februari\n";
	else if (kode_bulan == 3)
		cout << "ini bulan = maret\n";
	else if (kode_bulan == 4)
		cout << "ini bulan = April\n";
	else if (kode_bulan == 5)
		cout << "ini bulan kesayangan = Mei\n";
	else if (kode_bulan == 6)
		cout << "ini bulan = juni\n";
	else if (kode_bulan == 7)
		cout << "ini bulan = Juli\n";
	else if (kode_bulan == 8)
		cout << "ini bulan = agustus \n";
	else if (kode_bulan == 9)
		cout << "ini bulan = September\n";
	else if (kode_bulan == 10)
		cout << "ini bulan = Oktober\n";
	else if (kode_bulan == 11)
		cout << "ini bulan = november\n";
	else if (kode_bulan == 12)
		cout << "ini bulan = desember \n";

	else
		cout << "Maaf, Kode bulan yang anda masukkan salah!!\n";

	system("pause");
}