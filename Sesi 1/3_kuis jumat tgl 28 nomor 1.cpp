#include <iostream>
using namespace std;

int main()
{
	int bil, n, t = 0, I = 1;

	cout << "masukkan berapa kali input= ";
	cin >> n;

	do
	{
		cout << "masukkan bilangan " << I << "= ";
		cin >> bil;

		if (bil % 2 == 0)
		{
			t = t + bil;
		}
		I++;
	} while (I <= n);

	cout << "total bilangan genap adalah = " << t << endl;

	system("pause");
}
