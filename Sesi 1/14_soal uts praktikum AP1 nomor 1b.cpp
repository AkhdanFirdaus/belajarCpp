#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "masukkan jumlah bilangan= ";
	cin >> n;

	for (int kali = 0; kali < n; kali++)
	{
		for (int bintang = n; bintang > kali; bintang--)
		{
			cout << bintang << " ";
		}
		cout << endl;
	}
	n = 0;

	system("pause");
}