#include <iostream>
#include <iomanip>
#include <ctime>
#include <string.h>

using namespace std;

int konfirmProvinsi[34];

string provinsi[34] = {
    "N.A.D.",
    "Sumatera Utara",
    "Sumatera Barat",
    "Riau",
    "Kepulauan Riau",
    "Jambi",
    "Bengkulu",
    "Sumatera Selatan",
    "Kep. Bangka Bel.",
    "Lampung",
    "Banten",
    "DKI Jakarta",
    "Jawa Barat",
    "Jawa Tengah",
    "Jawa Timur",
    "DI Yogyakarta",
    "Bali",
    "NTB",
    "NTT",
    "Kalimantan Barat",
    "Kalimantan Selatan",
    "Kalimantan Tengah",
    "Kalimantan Timur",
    "Kalimantan Utara",
    "Gorontalo",
    "Sulawesi Barat",
    "Sulawesi Selatan",
    "Sulawesi Tenggara",
    "Sulawesi Tengah",
    "Sulawesi Utara",
    "Maluku",
    "Maluku Utara",
    "Papua",
    "Papua Barat",
};

struct Wilayah
{
    int kodeWilayah;
    string namaWilayah;
    int terkonfirm;
    int sembuh;
    int meninggal;
    tm *waktu;
} wilayah[200], selectedWilayah;

struct DataCovid
{
    int totalKasus;
    int totalterkonfirm;
    int totalSembuh;
    int totalMeninggal;
    int kodeWilayah[34][50];
    tm *waktu;
} covid;

int main()
{
    int pilihan, pilihDetail;
    int jmlProv = 34;
    int jmlDaerah;
    int posisiAkhir = 0, posisi = 0, max;
    covid.totalKasus = 0;
    covid.totalterkonfirm = 0;
    covid.totalMeninggal = 0;
    covid.totalSembuh = 0;
    cout << "Masukkan Jumlah Daerah per Provinsi: ";
    cin >> jmlDaerah;
    do
    {
        cout << "------------------------------\n";
        cout << "\tData Covid-19\n";
        cout << "------------------------------\n";
        if (covid.waktu != NULL)
        {
            cout << "Update Tanggal = " << covid.waktu->tm_mday << "-" << 2 + covid.waktu->tm_mon << "-" << 1900 + covid.waktu->tm_year << endl;
        }
        cout << "Total Kasus    = " << covid.totalKasus << endl;
        cout << "Dalam Perawatan= " << covid.totalterkonfirm - covid.totalSembuh - covid.totalMeninggal << endl;
        cout << "Total Sembuh   = " << covid.totalSembuh << endl;
        cout << "Total Meninggal= " << covid.totalMeninggal << endl;
        cout << "------------------------------\n";
        cout << "1. Input Data\n";
        cout << "2. Lihat Data Wilayah\n";
        cout << "3. Keluar\n";
        cout << "------------------------------\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("clear");
            cout << "-------------------------------------------------\n";
            for (int i = 0; i < jmlProv; i++)
            {
                cout << i + 1 << ". " << provinsi[i] << endl;
            }
            cout << "-------------------------------------------------\n";
            cout << "Pilih wilayah: ";
            cin >> pilihDetail;
            system("clear");
            cout << "Input Data Covid " << provinsi[pilihDetail - 1] << endl;
            max = jmlDaerah + posisiAkhir;
            for (int i = posisiAkhir; i < max; i++)
            {
                cout << "Daerah-" << i + 1 << endl;
                covid.kodeWilayah[pilihDetail - 1][i] = posisiAkhir;
                wilayah[i].kodeWilayah = posisiAkhir;
                cout << "-------------------\n";
                cout << "Nama Wilayah   : ";
                getline(cin >> ws, wilayah[i].namaWilayah);
                cout << "Terkonfirmasi  : ";
                cin >> wilayah[i].terkonfirm;
                cout << "Sembuh         : ";
                cin >> wilayah[i].sembuh;
                cout << "Meninggal      : ";
                cin >> wilayah[i].meninggal;
                cout << endl;
                covid.totalKasus += wilayah[i].terkonfirm;
                covid.totalterkonfirm += wilayah[i].terkonfirm;
                covid.totalSembuh += wilayah[i].sembuh;
                covid.totalMeninggal += wilayah[i].meninggal;
                time_t now = time(0);
                tm *updatedAt = localtime(&now);
                wilayah[i].waktu = updatedAt;
                covid.waktu = wilayah[i].waktu;
                if (i == max - 1)
                {
                    posisiAkhir += jmlDaerah;
                }
            }
            break;
        case 2:
            system("clear");
            if (covid.totalKasus != 0)
            {
                cout << "-------------------------------------------------\n";
                cout << "| No |\tNama Wilayah\t  | Kasus | Updated At   |\n";
                cout << "-------------------------------------------------\n";
                for (int i = 0; i < jmlProv; i++)
                {
                    for (int j = posisi; j < jmlDaerah + posisi; j++)
                    {

                        if (covid.kodeWilayah[i][j] == wilayah[j].kodeWilayah)
                        {
                            konfirmProvinsi[i] += wilayah[j].terkonfirm;
                        }
                    }
                    posisi += jmlDaerah;
                    cout << "|" << setw(2) << i + 1 << " | ";
                    cout << setw(19) << provinsi[i] << " |";
                    cout << setw(6) << konfirmProvinsi[i] << " |";
                    if (wilayah[i].waktu != NULL)
                    {
                        cout << setw(6) << wilayah[i].waktu->tm_mday << "-" << 2 + wilayah[i].waktu->tm_mon << "-" << 1900 + wilayah[i].waktu->tm_year << "|";
                    }
                    else
                    {
                        cout << setw(8) << "\t|";
                    }
                    cout << endl;
                    cout << "-------------------------------------------------\n";
                }
                cout << "-------------------------------------------------\n";
                cout << "Lihat Detail[1-34]: ";
                cin >> pilihDetail;

                selectedWilayah.namaWilayah = "Nama Wilayah";
                selectedWilayah.terkonfirm = 0;
                selectedWilayah.sembuh = 0;
                selectedWilayah.meninggal = 0;

                for (int i = 0; i < posisiAkhir; i++)
                {
                    if (covid.kodeWilayah[pilihDetail - 1][i] == wilayah[i].kodeWilayah)
                    {
                        selectedWilayah.namaWilayah = wilayah[i].namaWilayah;
                        selectedWilayah.terkonfirm += wilayah[i].terkonfirm;
                        selectedWilayah.sembuh += wilayah[i].sembuh;
                        selectedWilayah.meninggal += wilayah[i].meninggal;
                    }
                }

                cout << "\nData Covid-19 " << selectedWilayah.namaWilayah << endl;
                cout << "------------------------------\n";
                if (selectedWilayah.waktu != NULL)
                {
                    cout << "Update Tanggal = " << selectedWilayah.waktu->tm_mday << "-" << 2 + selectedWilayah.waktu->tm_mon << "-" << 1900 + selectedWilayah.waktu->tm_year << endl;
                }
                cout << "Total Kasus    = " << selectedWilayah.terkonfirm << endl;
                cout << "Dalam Perawatan= " << selectedWilayah.terkonfirm - selectedWilayah.sembuh - selectedWilayah.meninggal << endl;
                cout << "Total Sembuh   = " << selectedWilayah.sembuh << endl;
                cout << "Total Meninggal= " << selectedWilayah.meninggal << endl;
                cout << "------------------------------\n";
            }
            else
            {
                cout << "Tampilkan data\n";
            }
            break;
        case 3:
            cout << "Keluar aplikasi\n";
            break;
        default:
            cout << "Pilihant tidak ada\n";
            break;
        }
    } while (pilihan != 3);
}