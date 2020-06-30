#include <iostream>
using namespace std;

int main()
{
	float x, y;

	cout << "selamat datang dan salam sejahtera!!\n";
	cout << "-------------------------------------\n";
	cout << "silahkan masukkan bilangan positif atau negatif\n";
	cout << "masukkan nilai x : ";
	cin >> x;
	cout << endl;

	cout << "masukkan nilai y : ";
	cin >> y;
	cout << endl;

	if ((x - 2) && (y - 2))
	{
		cout << "x dan y bernilai positif!!\n";
	}
	else
	{
		cout << "x, y : ternyata ada yang negatif\n";
	}

	system("pause");
}