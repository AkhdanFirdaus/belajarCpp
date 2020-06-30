#include <iostream>

using namespace std;

float hitungLuas(int alas, int tinggi)
{
    return 0.5 * (alas * tinggi);
}

void luasSegitiga()
{
    int jumlah, total = 0;
    cout << "Masukkan jumlah segitiga: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++)
    {
        int alas, tinggi;
        cout << "Menghitung luas segitiga " << i + 1 << endl;
        cout << "Masukkan alas: ";
        cin >> alas;
        cout << "Masukkan tinggi: ";
        cin >> tinggi;
        float luas = hitungLuas(alas, tinggi);
        cout << "Luas segitiga = " << luas << "\n\n";
        total += luas;
    }
    cout << "Luas Total " << jumlah << " segitiga = " << total << endl;
}

void matriks()
{
    int i, j, baris, kolom;

    cout << "Matriks berordo m x n\n\n";
    cout << "Masukkan jumlah baris matriks: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom matriks: ";
    cin >> kolom;

    int matriksA[baris][kolom], matriksB[baris][kolom], hasil[baris][kolom];

    cout << "\nMasukkan elemen matrix A: \n";
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            cout << "Elemen Matriks A[" << i + 1 << "," << j + 1 << "] = ";
            cin >> matriksA[i][j];
        }
    }

    cout << "\nMasukkan elemen matrix B: \n";
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            cout << "Elemen Matriks B[" << i + 1 << "," << j + 1 << "] = ";
            cin >> matriksB[i][j];
        }
    }

    cout << "\nHasil penjumlahan matrix A+B = \n";
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << "\n";
    }
}

int mencari(int data[], int jumlah, int dicari)
{
    int hasil;
    for (int i = 0; i < jumlah; i++)
    {
        if (data[i] == dicari)
        {
            hasil = i;
            break;
        }
        else
        {
            hasil = -1;
        }
    }
    return hasil;
}

void sequentialSearch()
{
    int jumlah, dicari, hasil;
    cout << "Sequential Search\n";
    cout << "Jumlah input data: ";
    cin >> jumlah;

    int data[jumlah];

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukkan indeks ke-" << i << ": ";
        cin >> data[i];
    }

    cout << "Masukkan angka yang dicari: ";
    cin >> dicari;
    hasil = mencari(data, jumlah, dicari);
    cout << "Nilai ";
    hasil == -1 ? cout << "tidak ditemukan" : cout << "ditemukan pada indeks ke-" << hasil << endl;
}

int main()
{
    char pilihan;

    do
    {
        cout << "\nMenu\n";
        cout << "----------------------------------\n";
        cout << "a. Luas N buah segitiga\n";
        cout << "b. m x n buah array\n";
        cout << "c. Sequential search angka\n";
        cout << "d. Keluar\n";
        cout << "----------------------------------\n";
        cout << "Silahkan pilih huruf anda (a-d): ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 'a':
            luasSegitiga();
            break;
        case 'b':
            matriks();
            break;
        case 'c':
            sequentialSearch();
            break;
        case 'd':
            cout << "Program selesai\n";
            break;
        default:
            cout << "Menu harus huruf kecil\n";
            cout << "Menu tidak ada\n";
        }
    } while (pilihan != 'd');
}