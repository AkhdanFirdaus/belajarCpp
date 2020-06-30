#include <iostream>
using namespace std;

int main()
{
    int banyak;

    cout << "Inputkan banyak looping = ";
    cin >> banyak;
    cout << endl;
    cout << "coba akan melooping " << banyak << " kali";
    cout << endl;
    cout << endl;

    for (int i = 0; i < banyak; i++)
    {
        cout << "looping ke " << i + 1 << endl;
        ;
    }

    system("pause");
}