#include <iostream>
using namespace std;

int main()
{
	int i, n;
	float rata, jumlah;
	int data[10];
	jumlah = 0;

	cout << "masukan jumlah array :";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "masukan data ke- " << i + 1 << ":";
		cin >> data[i];
		jumlah = jumlah + data[i];
	}
	rata = jumlah / n;

	cout << " Jumlah ke- " << i << "data diatas adalah : " << jumlah << endl;
	cout << "Rata-rata ke- " << i << " data diatas adalah : " << rata;

	system("pause");
}