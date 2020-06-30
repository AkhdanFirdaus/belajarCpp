#include <iostream>
#include <iomanip>

using namespace std;

struct Mahasiswa
{
    string nim;
    string nama;
    int nilai;
};

int main()
{
    int jumlah;
    cout << "Program input data mahasiswa\n";
    cout << "----------------------------\n";
    cout << "Masukkan jumlah data: ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];

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

    cout << "\n\tOutput data\n";
    cout << "-----------------------------------------\n";
    cout << "|\tNIM\t|\tNama\t| Nilai |\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < jumlah; i++)
    {
        cout << "| " << setw(13) << mhs[i].nim << " | ";
        cout << setw(13) << mhs[i].nama << " | ";
        cout << setw(5) << mhs[i].nilai << " | ";
        cout << endl;
    }
    cout << "-----------------------------------------\n";
    cout << endl;
}