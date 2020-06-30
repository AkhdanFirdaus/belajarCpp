#include <iostream>
#include <iomanip>

using namespace std;

struct Mahasiswa
{
    string nim;
    string nama;
    int nilai;
};

void inputData(Mahasiswa *mhs, int jumlah);
void outputData(Mahasiswa *mhs, int jumlah);
void displayData(Mahasiswa mhs);

int main()
{
    int jumlah;

    cout << "Program input data mahasiswa\n";
    cout << "----------------------------\n";
    cout << "Masukkan jumlah data: ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];
    inputData(mhs, jumlah);
    outputData(mhs, jumlah);
}

void inputData(Mahasiswa *mhs, int jumlah)
{
    for (int i = 0; i < jumlah; i++)
    {
        cout << "---------------\n";
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "---------------\n";
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "Nama  : ";
        getline(cin >> ws, mhs[i].nama);
        cout << "Nilai : ";
        cin >> mhs[i].nilai;
        cout << "\n";
    }
}

void outputData(Mahasiswa *mhs, int jumlah)
{
    cout << "\n\tOutput data\n";
    cout << "-----------------------------------------\n";
    cout << "|\tNIM\t|\tNama\t| Nilai |\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < jumlah; i++)
    {
        displayData(mhs[i]);
    }
    cout << "-----------------------------------------\n";
    cout << endl;
}

void displayData(Mahasiswa mhs)
{
    cout << "| " << setw(13) << mhs.nim << " | ";
    cout << setw(13) << mhs.nama << " | ";
    cout << setw(5) << mhs.nilai << " | ";
    cout << endl;
}