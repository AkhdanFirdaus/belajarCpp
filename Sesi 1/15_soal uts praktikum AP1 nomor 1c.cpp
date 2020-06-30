#include <iostream>
using namespace std;

int main()
{
	int n; // n adalah jumlah bilangan

	cout << "--- Selamat Datang di Aplikasi Ini --\n";
	cout << "=====================================\n";
	cout << "masukkan jumlah bilangan= ";
	cin >> n;

	for (int kali = 0; kali < n; kali++)
	{
		for (int kali = 0; kali < n; kali++)
		{
			cout << n << " ";
		}
		cout << endl;
	}
	n = 0;

	system("pause");
}