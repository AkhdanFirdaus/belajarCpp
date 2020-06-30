#include <iostream>
using namespace std;

int saldo = 3000000;
int ambil, transfeer;
int kredit, telepon, koran, rek;

void informasi()
{
	cout << "jumlah saldo anda adalah = " << saldo << endl;
	system("pause");
	system("cls");
}

void penarikan()
{
	cout << "masukkan jumlah uang yang ingin anda ambil = \n";
	cout << "(jumlah penarikan tidak lebih dari 2.000.000)\n";
	cout << "Rp. ";
	cin >> ambil;

	if (ambil > 2000000)
	{
		ambil = 0;
	}
	saldo = saldo - ambil;

	cout << "sisa saldo anda adalah = Rp. " << saldo << endl;
	system("pause");
	system("cls");
}

void pembayaran()
{
	cout << "Pembayaran Telepon, Kartu Kredit dan Koran\n";
	cout << "******************************************\n\n";

	cout << "masukkan pembayaran telepon = Rp. ";
	cin >> telepon;
	cout << "masukkan pembayaran kartu kredit =  Rp. ";
	cin >> kredit;
	cout << "masukkan pembayaran Tagihan Koran = Rp. ";
	cin >> koran;

	saldo = saldo - (telepon + kredit + koran);

	cout << "sisa saldo anda adalah = Rp. " << saldo;
	system("pause");
	system("cls");
}

void transfer()
{
	cout << "masukkan nomor rekening tujuan = ";
	cin >> rek;

	cout << "masukkan jumlah yanga akan di transfer = Rp. ";
	cin >> transfeer;

	saldo = saldo - transfeer;

	cout << "sisa saldo anda adalah = Rp. " << saldo << endl;
	system("pause");
	system("cls");
}

void keluar()
{
	exit(0);
}

int main()
{
	int pilih;

	cout << "Silahkan Pilih Menu: \n";
	cout << "1. Informasi Saldo\n";
	cout << "2. Pengambilan Tunai\n";
	cout << "3. Pembayaran\n";
	cout << "4. Transfer\n";
	cout << "5. keluar\n";
	cout << "Pilihan anda: ";
	cin >> pilih;
	cout << "********************************************************************\n\n";

	if (pilih == 1)
	{
		do
		{
			informasi();
			main();
		} while (true);
	}
	else if (pilih == 2)
	{
		do
		{
			penarikan();
			main();
		} while (true);
	}
	else if (pilih == 3)
	{
		do
		{
			pembayaran();
			main();
		} while (true);
	}
	else if (pilih == 4)
	{
		do
		{
			transfer();
			main();
		} while (true);
	}
	else if (pilih == 5)
	{
		do
		{
			keluar();
			main();
		} while (true);
	}
}