//soal uts teori nomor 3
#include <iostream>
using namespace std;

int main()
{
	int n, kali, star;

	star = 0;
	kali = 0;
	cout << "Masukkan bilangan= ";
	cin >> n;

	while (kali < n)
	{
		kali++;
		while (star < kali)
		{
			cout << "*";
			star++;
		}
		cout << "\n\n";
	}
	system("pause");
}