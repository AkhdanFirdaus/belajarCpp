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
} mhs[100];

struct Ukt
{
    int kategori;
    int nominal;
} ukt[7];
;

struct Pembayaran
{
    string nim;
    tm *jatuhTempo;
    tm *tglBayar;
    int bayar;
    int kembalian;
} bayar[100];

int n;
int pilih;

// void gotoxy(int x, int y)
// {
//     COORD k = {x, y};
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
// }

tm *getTime()
{
    time_t now = time(0);
    tm *time = localtime(&now);
    return time;
}

int randomUkt()
{
    return rand() % 7;
}

void initUkt()
{
    //inisialisasi ukt
    int jmlKategori = 7;
    int nominalAwal = 3334000;
    for (int i = 0; i < jmlKategori; i++)
    {
        ukt[i].kategori = i + 1;
        ukt[i].nominal = nominalAwal;
        nominalAwal += 222000;
    }
}

void inputMahasiswa()
{
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

        mhs[i].kategori = randomUkt();
        cout << endl;
    }
}

void inputBayar()
{
    tm *jatuhTempo = getTime();
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

        bayar[i].tglBayar = getTime();
        cout << setw(5) << "  | Rp. " << bayar[i].tglBayar->tm_mday << "-" << 1 + bayar[i].tglBayar->tm_mon << "-" << 1900 + bayar[i].tglBayar->tm_year;
    }
}

void tampilData()
{
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

int main()
{
    cout << "\tProgram Bayar UKT\n";
    cout << "-------------------------------------------------\n";
    initUkt();
    srand((unsigned)time(0));
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

            system("cls");
            inputMahasiswa();
            inputBayar();
            cout << "\n\n";
            break;
        case 2:
            if (n > 0)
            {
                system("cls");
                tampilData();
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