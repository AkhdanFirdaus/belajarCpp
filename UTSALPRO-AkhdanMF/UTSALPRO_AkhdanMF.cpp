#include <iostream>

using namespace std;

int main()
{
    char ulang = 'y';
    int i = 0, n;

    string nim, nama;
    char indeks[3];
    int nilai[3], sks[3], jumlahSks = 0, jumlahNilai = 0, jumlahBil = 0, bilangan, suhu;
    float ipk;

    do
    {
        cout << "==========================\n";
        cout << "Program UTS Semester Genap\n";
        cout << "==========================\n";
        cout << "1. Menghitung IPK Mahasiswa\n";
        cout << "2. Membaca temperatur air\n";
        cout << "3. Menjumlahkan bilangan genap\n";
        cout << "4. Keluar\n";
        cout << "==========================\n";
        cout << "Pilih Menu[1-4]: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "------------------------\n";
            cout << "Menghitung IPK Mahasiswa\n";
            cout << "------------------------\n";
            cout << "NIM\t: ";
            cin >> nim;
            cout << "Nama\t: ";
            getline(cin >> ws, nama);
            for (i = 0; i < 3; i++)
            {
                cout << "Nilai MK " << i + 1 << " [A-E]: ";
                cin >> indeks[i];
                cout << "SKS\t: ";
                cin >> sks[i];

                if (indeks[i] == 'A' || indeks[i] == 'a')
                {
                    nilai[i] = 4;
                }
                else if (indeks[i] == 'B' || indeks[i] == 'b')
                {
                    nilai[i] = 3;
                }
                else if (indeks[i] == 'C' || indeks[i] == 'c')
                {
                    nilai[i] = 2;
                }
                else if (indeks[i] == 'D' || indeks[i] == 'd')
                {
                    nilai[i] = 1;
                }
                else
                {
                    nilai[i] = 0;
                }
                jumlahNilai += (nilai[i] * sks[i]);
                jumlahSks += sks[i];
            }
            ipk = jumlahNilai / jumlahSks;
            cout << "Total SKS: " << jumlahSks << endl;
            cout << "IPK\t: " << ipk << endl
                 << endl;
            break;
        case 2:
            cout << "------------------------\n";
            cout << "Menghitung Suhu Air\n";
            cout << "------------------------\n";
            cout << "Masukan suhu air : ";
            cin >> suhu;
            if (suhu <= 0)
            {
                cout << "wujud air tersebut dalam kedaan padat\n";
            }
            else if (suhu > 0 && suhu < 100)
            {
                cout << "wujud air tersebut dalam kedaan cair\n";
            }
            else
            {
                cout << "wujud air tersebut dalam kedaan gas\n";
            }
            cout << endl
                 << endl;
            break;
        case 3:
            cout << "------------------------\n";
            cout << "Menghitung Bil Genap\n";
            cout << "------------------------\n";
            cout << "Masukkan jumlah bil: ";
            cin >> n;
            i = 0;
            do
            {
                cout << "Masukkan Bilangan ke-" << i + 1 << ": ";
                cin >> bilangan;
                if (bilangan % 2 == 0)
                {
                    jumlahBil += bilangan;
                    i++;
                }
                else
                {
                    cout << bilangan << " bukan bilangan genap\n";
                }
            } while (i < n);
            cout << "Jumlah Bilangan: " << jumlahBil << endl
                 << endl;
            break;
        case 4:
            ulang = 't';
            break;
        default:
            break;
        }

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}