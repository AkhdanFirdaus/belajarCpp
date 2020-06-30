#include <iostream>
using namespace std;

int main()
{
	int bil, n, t = 0, i = 1;

	cout << "masukkan berapa kali input= " << endl;
	cin >> n;

	do
	{
		cout << "masukkan bilangan " << i << "= ";
		cin >> bil;

		if (bil % 2 == 0)
		{
			t = t + bil;
		}
		i++;
	} while (i <= n);

	cout << "total bilangan genap adalah = " << t << endl;

	system("pause");
}