#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int baris = 2;
    int kolom = 3;
    int matriks1[baris][kolom], matriks2[baris][kolom], hasil[baris][kolom];
    cout << "Matrix " << baris << "x" << kolom << endl;
    cout << "Masukkan elemen matrix A: \n";
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            cout << "Masukkan matriks [" << i + 1 << ", " << j + 1 << "]: ";
            cin >> matriks1[i][j];
        }
    }
    cout << "Masukkan elemen matrix B: \n";
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            cout << "Masukkan matriks [" << i + 1 << ", " << j + 1 << "]: ";
            cin >> matriks2[i][j];
        }
    }
    cout << "Hasil penjumlahan matrix: \n";
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
            cout << hasil[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}