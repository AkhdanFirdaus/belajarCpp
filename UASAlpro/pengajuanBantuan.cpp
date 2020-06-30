#include <iostream>

using namespace std;

struct Mahasiswa
{
    string nim;
    string nama;
    string jurusan;
    string fakultas;
    string tmpTinggal;
} mhs[100];

void inputData(int i);
void listData(int jmlData);
void data(int i);

int main()
{
    int pilih, pilihData, jmlData, i = 0;
    do
    {
        cout << "Form Pengajuan Bantuan\n";
        cout << "Mahasiswa di sekitaran kampus\n";
        cout << "1. Input data\n";
        cout << "2. Lihat data\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";

        switch (pilih)
        {
        case 1:
            system("clear");
            inputData(i);
            break;
        case 2:
            cout << "Lihat data\n";
            cout << "1. Lihat List Penerima\n";
            cout << "2. Lihat Status Penerima\n";
            cin >> pilihData;
            break;
        case 3:
            cout << "Keluar Aplikasi\n";
            break;
        default:
            cout << "Menu tidak ada\n";
            break;
        }
        i++;
    } while (pilih != 3);
}

void inputData(int i)
{
    cout << "Nama       : ";
    cin >> mhs[i].nama;
    cout << "NIM        : ";
    cin >> mhs[i].nim;
    cout << "Jurusan    : ";
    cin >> mhs[i].jurusan;
    cout << "Fakultas   : ";
    cin >> mhs[i].fakultas;
    cout << "Tmp Tinggal: ";
    cin >> mhs[i].tmpTinggal;
}

void listData(int jmlData)
{
    for (int i = 0; i < jmlData; i++)
    {
        cout << "Nama       : " << mhs[i].nama;
        cout << "NIM        : " << mhs[i].nim;
        cout << "Jurusan    : " << mhs[i].jurusan;
        cout << "Fakultas   : " << mhs[i].fakultas;
        cout << "Tmp Tinggal: " << mhs[i].tmpTinggal;
    }
}

void data(int i)
{
    cout << "Nama       : " << mhs[i].nama;
    cout << "NIM        : " << mhs[i].nim;
    cout << "Jurusan    : " << mhs[i].jurusan;
    cout << "Fakultas   : " << mhs[i].fakultas;
    cout << "Tmp Tinggal: " << mhs[i].tmpTinggal;
}