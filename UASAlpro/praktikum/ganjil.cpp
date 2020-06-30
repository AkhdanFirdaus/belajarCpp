#include <iostream>

using namespace std;

void avgBilBulat()
{
    int jumlah, total = 0;
    cout << "Menghitung Rata-rata bilangan bulat\n";
    cout << "Input jumlah bilangan: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++)
    {
        int angka;
        cout << "Bilangan ke-" << i + 1 << ": ";
        cin >> angka;
        total += angka;
    }
    cout << "Rata-rata bilangan tsb = " << total / jumlah << endl;
}

void array1D()
{
    int i, n;

    cout << "Array 1 Dimensi\n";
    cout << "Masukkan jumlah data: ";
    cin >> n;
    int array[n];

    cout << "Masukkan Nilai\n";
    for (i = 0; i < n; i++)
    {
        cout << "Data indeks ke-" << i << ": ";
        cin >> array[i];
    }

    cout << "--------------\n";
    cout << "Tampilan Nilai\n";
    for (i = 0; i < n; i++)
    {
        cout << "Data indeks ke-" << i << " = " << array[i] << endl;
    }
}

void display(char huruf[], int jumlah)
{
    for (int i = 0; i < jumlah; i++)
    {
        cout << huruf[i] << "\t ";
    }
    cout << endl;
}

void sortHuruf(char huruf[], int jumlah)
{
    int pos, i, j;
    for (i = 0; i < jumlah - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < jumlah; j++)
        {
            if (huruf[j] < huruf[pos])
                pos = j;
        }
        if (pos != i)
        {
            int t;
            t = huruf[i];
            huruf[i] = huruf[pos];
            huruf[pos] = t;
        }
    }

    display(huruf, jumlah);
}

void selectionSortHuruf()
{
    int jumlah;
    cout << "Selection Sort Huruf\n";
    cout << "Masukkan jumlah huruf: ";
    cin >> jumlah;
    char huruf[jumlah];
    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukkan huruf ke-" << i + 1 << ": ";
        cin >> huruf[i];
    }
    cout << "Tampilan sebelum di sorting : \n";
    display(huruf, jumlah);
    cout << "Tampilan setelah di sorting : \n";
    sortHuruf(huruf, jumlah);
}

int main()
{
    char pilihan;

    do
    {
        cout << "\nMenu\n";
        cout << "----------------------------------\n";
        cout << "a. Rata-rata N buah bilangan bulat\n";
        cout << "b. array satu dimensi\n";
        cout << "c. selection sort huruf\n";
        cout << "d. Keluar\n";
        cout << "----------------------------------\n";
        cout << "Silahkan pilih huruf anda (a-d): ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 'a':
            avgBilBulat();
            break;
        case 'b':
            array1D();
            break;
        case 'c':
            selectionSortHuruf();
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