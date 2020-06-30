#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
// #include <windows.h>

using namespace std;

struct Mahasiswa
{
    string nim;
    string nama;
    string semester;
    int kategori;
};

struct Ukt
{
    int kategori;
    int nominal;
};

struct Pembayaran
{
    string nim;
    tm *jatuhTempo;
    tm *tglBayar;
    int bayar;
    int kembalian;
};

// void gotoxy(int x, int y)
// {
//     COORD k = {x, y};
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
// }

int main()
{
    cout << "\tProgram Bayar UKT\n";
    cout << "-------------------------------------------------\n";
    //inisialisasi ukt
    int jmlKategori = 7;
    Ukt ukt[jmlKategori];
    int nominalAwal = 3334000;
    for (int i = 0; i < jmlKategori; i++)
    {
        ukt[i].kategori = i + 1;
        ukt[i].nominal = nominalAwal;
        nominalAwal += 222000;
    }

    //input data mahasiswa
    Mahasiswa mhs[100];
    Pembayaran bayar[100];
    srand((unsigned)time(0));
    // random jatuh tempo
    time_t now = time(0);
    tm *jatuhTempo = localtime(&now);

    int n;
    int pilih;
    do
    {
        cout << "1. Bayar\n";
        cout << "2. Riwayat\n";
        cout << "3. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Jumlah mahasiswa : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "NIM     : ";
                cin >> mhs[i].nim;
                cout << "Nama    : ";
                getline(cin >> ws, mhs[i].nama);
                cout << "Semester: ";
                cin >> mhs[i].semester;

                //random ukt
                int randomUkt = rand() % 7;
                mhs[i].kategori = randomUkt;
                cout << endl;
            }
            system("cls");
            cout << "--------------------------------------------------------------------------------------------------------------------\n";
            cout << "|\tNIM\t|\tNama\t| UKT |\tNominal\t| Jatuh Tempo | Nominal Bayar |   Kembalian   | Tanggal Pembayaran |\n";
            cout << "--------------------------------------------------------------------------------------------------------------------\n";

            for (int i = 0; i < n; i++)
            {
                int kategori = mhs[i].kategori - 1;
                bayar[i].nim = mhs[i].nim;
                bayar[i].jatuhTempo = jatuhTempo;

                cout << "| " << setw(13) << mhs[i].nim << " | ";
                cout << setw(13) << mhs[i].nama << " | ";
                cout << setw(3) << ukt[kategori].kategori << " | ";
                cout << setw(3) << ukt[kategori].nominal << " | ";
                cout << setw(4) << jatuhTempo->tm_mday << "-" << 2 + jatuhTempo->tm_mon << "-" << 1900 + jatuhTempo->tm_year << " | ";
                cout << setw(3) << "Rp.\t      | ";
                cout << setw(3) << "Rp.\t      | ";
                cout << setw(3) << "\t\t   | ";
                cout << endl;
            }
            cout << "--------------------------------------------------------------------------------------------------------------------\n";

            for (int i = 0; i < n; i++)
            {
                int kategori = mhs[i].kategori - 1;

                // gotoxy(68, i + 3);
                cin >> bayar[i].bayar;
                bayar[i].kembalian = bayar[i].bayar - ukt[kategori].nominal;

                // gotoxy(84, i + 3);
                cout << setw(5) << bayar[i].kembalian;

                time_t now = time(0);
                tm *tglBayar = localtime(&now);
                bayar[i].tglBayar = tglBayar;
                cout << setw(5) << "  | Rp. " << tglBayar->tm_mday << "-" << 1 + tglBayar->tm_mon << "-" << 1900 + tglBayar->tm_year;
            }
            cout << "\n\n";
            break;
        case 2:
            if (n > 0)
            {
                system("cls");
                //tampil data
                cout << "--------------------------------------------------------------------------------------------------------------------\n";
                cout << "|\tNIM\t|\tNama\t| UKT |\tNominal\t| Jatuh Tempo | Nominal Bayar |   Kembalian   | Tanggal Pembayaran |\n";
                cout << "--------------------------------------------------------------------------------------------------------------------\n";
                for (int i = 0; i < n; i++)
                {
                    int kategori = mhs[i].kategori - 1;
                    cout << "| " << setw(13) << mhs[i].nim << " | ";
                    cout << setw(13) << mhs[i].nama << " | ";
                    cout << setw(3) << ukt[kategori].kategori << " | ";
                    cout << setw(3) << ukt[kategori].nominal << " | ";
                    cout << setw(4) << bayar[i].jatuhTempo->tm_mday << "-" << 2 + bayar[i].jatuhTempo->tm_mon << "-" << 1900 + bayar[i].jatuhTempo->tm_year << " | ";
                    cout << setw(3) << "Rp. " << bayar[i].bayar << " | ";
                    cout << setw(3) << "Rp. " << bayar[i].kembalian << " | ";
                    cout << setw(4) << bayar[i].tglBayar->tm_mday << "-" << 2 + bayar[i].tglBayar->tm_mon << "-" << 1900 + bayar[i].tglBayar->tm_year << " | ";
                    cout << endl;
                }
                cout << "--------------------------------------------------------------------------------------------------------------------\n";
            }
            else
            {
                cout << "Data tidak ada\n";
            }
            break;
        default:
            cout << "Menu tidak ada\n";
            break;
        }
    } while (pilih != 3);
}