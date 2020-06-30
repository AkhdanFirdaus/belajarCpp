#include <iostream>
using namespace std;

int main()
{
	char abjad;
	abjad = 'A';
	do
	{
		cout << abjad << " ";
		abjad += 1;
	} while (abjad <= 'Z');
	cout << "\n";

	system("pause");
}
