#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

string zonaMerah(int data[][100], int jumlahRw, int jumlahRt)
{
    string lokasi;
    int maks = data[0][0];
    int posRw, posRt;
    for (int i = 0; i < jumlahRw; i++)
    {
        for (int j = 0; j < jumlahRt; j++)
        {
            if (maks < data[i][j])
            {
                maks = data[i][j];
                posRw = i + 1;
                posRt = j + 1;
            }
        }
    }
    lokasi = "RW " + to_string(posRw) + " RT " + to_string(posRt);
    return lokasi;
}

struct Covid
{
    string namaKecamatan;
    int rtRw[100][100];
    int totalPositif;
};

int main()
{
    int jumlahKecamatan, jumlahRw, jumlahRt;
    cout << "Program menghitung pasien Corona\n";
    cout << "----------------------------\n";
    cout << "Masukkan jumlah Kecamatan: ";
    cin >> jumlahKecamatan;

    Covid covidKecamatan[jumlahKecamatan];

    for (int i = 0; i < jumlahKecamatan; i++)
    {
        covidKecamatan[i].totalPositif = 0;
        cout << "---------------\n";
        cout << "Kota ke-" << i + 1 << endl;
        cout << "---------------\n";
        cout << "Nama Kecamatan: ";
        getline(cin >> ws, covidKecamatan[i].namaKecamatan);
        cout << "Masukkan jumlah RW: ";
        cin >> jumlahRw;
        cout << "Masukkan jumlah RT: ";
        cin >> jumlahRt;
        for (int j = 0; j < jumlahRw; j++)
        {
            for (int k = 0; k < jumlahRt; k++)
            {
                cout << "Data pasien RW " << j + 1;
                cout << " RT " << k + 1 << " : ";
                cin >> covidKecamatan[i].rtRw[j][k];
                covidKecamatan[i].totalPositif += covidKecamatan[i].rtRw[j][k];
            }
        }
    }

    cout << "\nData Persebaran covid kecamatan\n";
    cout << "----------------------------------------------\n";
    cout << "|\tKecamatan\t| Kasus | Zona Merah |\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < jumlahKecamatan; i++)
    {
        cout << "| " << setw(21) << covidKecamatan[i].namaKecamatan << " | ";
        cout << setw(5) << covidKecamatan[i].totalPositif << " | ";
        cout << setw(5) << zonaMerah(covidKecamatan[i].rtRw, jumlahRw, jumlahRt) << " | ";
        cout << endl;
    }
    cout << "----------------------------------------------\n";
    cout << endl;
}