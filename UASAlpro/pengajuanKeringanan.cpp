#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

struct Akun
{
    int nim;
    string nama;
    string password;
    int kategori;
} akun[6];

struct Ukt
{
    int kategori;
    int nominal;
} ukt[7];

struct Pengajuan
{
    int tipe[2][100];
    int kategoriNim[7][100];
    int jmlBayar[100];
    string alasan[100];
    tm *waktu[100];
    bool disetujui[100];
} pengajuan;

string nama[5] = {"John", "Doe", "Lorem", "Ipsum", "Guy"};
string pilihanCicil[5] = {
    "Surat Pernyataan Keabsahan Data bermaterai 6000.",
    "Surat permohonan keringanan UKT dalam bentuk Pengurangan besaran UKT bermaterai 6000.",
    "Surat keterangan kerugian usaha/pailit tempat kerja.",
    "Surat keterangan penutupan tempat usaha.",
    "Surat keterangan penurunan pendapatan secara signifikan.",
};
string url[5] = {
    "https://keringananukt.uinsgd.ac.id/Frontend/assets/file/keabsahan.docx",
    "https://keringananukt.uinsgd.ac.id/Frontend/assets/file/dokumen1.docx",
    "https://keringananukt.uinsgd.ac.id/Frontend/assets/file/usaha_pailit.docx",
    "https://keringananukt.uinsgd.ac.id/Frontend/assets/file/penutupan_tempat_usaha.docx",
    "https://keringananukt.uinsgd.ac.id/Frontend/assets/file/penurunan_pendapatan.docx",
};
string jawaban[2] = {"Maaf permohonan Anda belum bisa kami penuhi.", "Selamat permohonan Anda kami terima."};
char ulang;

int randomNumber(int number)
{
    return rand() % number;
}

void initAkun()
{
    for (int i = 0; i < 6; i++)
    {
        int randomFname = randomNumber(5);
        int randomLname = randomNumber(5);
        akun[i].nim = stoi("119705001" + to_string(i));
        akun[i].nama = nama[randomFname] + " " + nama[randomLname];
        akun[i].password = "password";
        akun[i].kategori = ukt[i].kategori;
    }
}

void initUkt()
{
    //inisialisasi ukt
    int nominalAwal = 3334000;
    for (int i = 0; i < 7; i++)
    {
        ukt[i].kategori = i + 1;
        ukt[i].nominal = nominalAwal;
        nominalAwal += 222000;
    }
}

void logout(int &akun)
{
    akun = -1;
}

void launchUrl(string link)
{
    cout << "Link document : " << link << endl;
    string op = string("open ").append(link);
    system(op.c_str());
}

tm *getTime()
{
    time_t now = time(0);
    tm *time = localtime(&now);
    return time;
}

int simulasiLogin();
void diskon(int &);
void cicil(int &);

int main()
{
    srand((unsigned)time(0));
    initUkt();
    initAkun();
    int login = simulasiLogin();
    do
    {
        int pilih;
        if (login != -1)
        {
            cout << "---------------------------------------------------\n";
            cout << "Halo " << akun[login].nama << endl;
            cout << "Kategori UKT : " << ukt[login].kategori << endl;
            cout << "Nominal UKT  : " << ukt[login].nominal << endl;
            int bayar = ukt[login].nominal;
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (pengajuan.kategoriNim[i][j] == akun[login].nim)
                    {
                        bayar = pengajuan.jmlBayar[login];
                        break;
                    }
                }
            }
            cout << "Harus bayar  : " << bayar << endl;
            if (pengajuan.waktu[login] != NULL)
            {
                cout << "Tgl Pengajuan: " << pengajuan.waktu[login]->tm_mday << "-" << 2 + pengajuan.waktu[login]->tm_mon << "-" << 1900 + pengajuan.waktu[login]->tm_year << endl;
                cout << "Alasan       : " << pengajuan.alasan[login] << endl;
                cout << "Disetujui    : ";
                pengajuan.disetujui[login] == 1 ? cout << "disetujui" : cout << "tidak disetujui";
                cout << endl;
            }
            cout << "---------------------------------------------------\n";
            cout << "Keringanan Pengurangan UKT\n";
            cout << "1. Pengurangan biaya\n";
            cout << "\t-100% bagi mhs yg ortu nya meninggal karena covid\n";
            cout << "\t-10% bagi mhs yg terdampak covid\n";
            cout << "2. Pembayaran cicilan\n";
            cout << "\tMhs membayar 2 tahap dengan masing-masing 50%\n";
            cout << "3. Logout\n";
            cout << "---------------------------------------------------\n";
            cout << "Pilih: ";
            cin >> pilih;
            switch (pilih)
            {
            case 1:
                cout << "Permohonan Keringanan UKT - Diskon\n";
                diskon(login);
                break;
            case 2:
                cout << "Permohonan Keringanan UKT - Cicil\n";
                cicil(login);
                break;
            case 3:
                logout(login);
                cout << "Login lagi[y/n]? ";
                cin >> ulang;
                break;
            default:
                break;
            }
        }
        else
        {
            login = simulasiLogin();
        }
    } while (ulang != 'n');
}

int simulasiLogin()
{
    int nim;
    string password;
    cout << "Login\n";
    cout << "-----------\n";
    cout << "NIM        : ";
    cin >> nim;
    cout << "Password   : ";
    cin >> password;

    for (int i = 0; i < 5; i++)
    {
        if (nim == akun[i].nim && password == akun[i].password)
        {
            cout << "Berhasil login\n";
            return i;
        }
    }
    return -1;
}

void diskon(int &i)
{
    int pilihPermohonan;
    string alasan;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << pilihanCicil[i];
        // cout << " [" << url[i] << "]";
        cout << endl;
    }
    cout << "Pilih Permohonan: ";
    cin >> pilihPermohonan;
    launchUrl(url[pilihPermohonan - 1]);
    cout << "Masukkan alasan: ";
    getline(cin >> ws, alasan);
    cout << "Mohon tunggu...\n";

    for (int i = 0; i <= 15; i++)
    {
        cout << "-";
        for (int j = 0; j <= 1e8; j++)
            ;
    }
    cout << endl;
    pengajuan.kategoriNim[ukt[i].kategori - 1][i] = akun[i].nim;
    pengajuan.tipe[0][i] = pilihPermohonan;
    pengajuan.waktu[i] = getTime();
    pengajuan.alasan[i] = alasan;
    int rand = randomNumber(2);
    if (rand == 1)
    {
        pengajuan.jmlBayar[i] = ukt[i].nominal - ukt[i].nominal * 0.10;
        pengajuan.disetujui[i] = true;
    }
    else
    {
        pengajuan.jmlBayar[i] = ukt[i].nominal;
        pengajuan.disetujui[i] = false;
    }
    cout << jawaban[rand] << endl;
    cout << "Anda harus membayar Rp. " << pengajuan.jmlBayar[i] << endl;
}

void cicil(int &i)
{
    string alasan;
    cout << "Masukkan alasan: ";
    getline(cin >> ws, alasan);
    pengajuan.kategoriNim[ukt[i].kategori - 1][i] = akun[i].nim;
    pengajuan.tipe[1][i] = akun[i].nim;
    pengajuan.waktu[i] = getTime();
    pengajuan.alasan[i] = alasan;
    int rand = randomNumber(2);
    if (rand == 1)
    {
        pengajuan.jmlBayar[i] = ukt[i].nominal / 2;
        pengajuan.disetujui[i] = true;
    }
    else
    {
        pengajuan.jmlBayar[i] = ukt[i].nominal;
        pengajuan.disetujui[i] = false;
    }
    cout << jawaban[rand] << endl;
    cout << "Anda harus membayar Rp. " << pengajuan.jmlBayar[i] << " pada pembayaran pertama" << endl;
}