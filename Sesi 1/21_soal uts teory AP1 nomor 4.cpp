#include <iostream>
using namespace std;

int main()
{
	int pilihan, AF = 0, BD = 0, SR = 0, pemilih = 10, index = 0;

	cout << "--------PEMILU BERINTEGRITAS--------\n";
	cout << "====================================\n";

	cout << "=====DAFTAR CALON KETUA DAN WAKIL KETUA HIMATIF====\n";
	cout << "___________________________________________________\n\n";

	cout << "1. Arif - Rahman (AF)\n";
	cout << "2. Bambang - Devina (BD)\n";
	cout << "3. Sri - Rahman (SR)\n\n";
	cout << "======================================\n\n";

	do
	{

		cout << "Masukkan Calon Pilihan Anda (1, 2, 3)= ";
		cin >> pilihan;

		if (pilihan == 1)
		{
			cout << "Anda telah memilih Arif dan Firman\n";
			AF++;
		}
		else if (pilihan == 2)
		{
			cout << "Anda Telah Memilih Bambang dan De vina\n";
			BD++;
		}
		else if (pilihan == 3)
		{
			cout << "Anda Telah Memilih Sri dan Rahman\n";
			SR++;
		}
		index++;
		system("pause");
		system("cls");
	} while (index < pemilih);

	cout << "Ketua dan Wakil Ketua Terpilih adalah\n";
	cout << "======================================\n\n";
	if ((AF > BD) && (AF > SR))
	{
		cout << "Peringkat 1 = Arif dan Firman\n\n";
		if (BD > SR)
		{
			cout << "Peringkat 2 = Bambang - Devina\n";
			cout << "Peringkat 3 = Sri dan Rahman\n\n";
		}
		else if (SR > BD)
		{
			cout << "Peringkat 2 = Sri dan Rahman\n";
			cout << "Peringkat 3 = Bambang dan Devina\n\n";
		}
	}
	else if ((BD > AF) && (BD > SR))
	{
		cout << "Bambang dan Devina\n\n";
		if (AF > SR)
		{
			cout << "Peringkat 2 = Arif dan Firman\n";
			cout << "peringkat 3 = Sri dan Rahman\n\n";
		}
		else if (SR > AF)
		{
			cout << "Peringkat 2 = Sri dan Rahman\n";
			cout << "Peringkat 3 = Arif dan Rahman\n\n";
		}
	}
	else if ((SR > BD) && (SR > AF))
	{
		cout << "Sri dan Rahman\n\n";
		if (AF > BD)
		{
			cout << "Peringkat 2 = Arif dan Firman\n";
			cout << "peringkat 3 = Bambang dan Devina\n\n";
		}
		else if (BD > AF)
		{
			cout << "Peringkat 2 = Bambang dan Devina\n";
			cout << "Peringkat 3 = Arif dan Rahman\n\n";
		}
	}
	cout << "selamat kepada Ketua dan Wakil Ketua Terpilih!!!\n\n";

	system("pause");
}