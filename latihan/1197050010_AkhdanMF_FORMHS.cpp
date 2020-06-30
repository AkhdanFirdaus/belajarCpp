#include <iostream>
#include <iterator>

using namespace std;

struct mahasiswa
{
    string nim;
    string nama;
    string semester;
    float ipk;
} mhs[100];

struct ipk
{
    int nilai;
    int angka;
    string huruf;
} ip[100];

struct matkul
{
    string namaMatkul;
    int semester;
} mat[100];

int tambahData(int jumlahArray);
void lihatData(int jumlahArray);
int tambahMatkul(int jumlahMatkul);
void lihatMatkul(int jumlahArray);
void hitungIPK(int jumlahMatkul);
void updateIPK(int jumlahArray, int jumlahMatkul);

int cariIndex(int jumlahArray, string nim)
{
    int index;
    //cari index
    for (int i = 0; i < jumlahArray; i++)
    {
        if (nim == mhs[i].nim)
        {
            index = i;
            break;
        }
        else
        {
            cout << "NIM tidak ada\n";
            return -1;
        }
    }
    return index;
}

void tidakada(int i)
{
    if (i == 1)
    {
        cout << "Tambah Data Mahasiswa dulu\n";
    }
    else if (i == 2)
    {
        cout << "Tambah Data Matkul dulu\n";
    }
    else
    {
        cout << "Tambah Data Mahasiswa dan Matkul dulu\n";
    }
}

int main()
{
    int n, jumlahArray = 0, jumlahMatkul = 0;
    char ulang = 'y';

    string menu[7] = {"Tambah Data Mahasiswa", "Lihat Data Mahasiswa", "Tambah Mata Kuliah", "Lihat Mata Kuliah", "Hitung IPK Mahasiswa", "Update IPK Mahasiswa", "Exit"};

    do
    {
        cout << "\n\n========================\n";
        cout << "Menu Data Mahasiswa\n";
        cout << "========================\n";
        for (int i = 0; i < 7; i++)
        {
            cout << i + 1 << " " << menu[i] << endl;
        }
        cout << "========================\n";
        cout << "Masukkan pilihan: ";
        cin >> n;

        switch (n)
        {
        case 1:
            jumlahArray = tambahData(jumlahArray);
            break;
        case 2:
            jumlahArray == 0 ? tidakada(1) : lihatData(jumlahArray);
            break;
        case 3:
            jumlahMatkul = tambahMatkul(jumlahMatkul);
            break;
        case 4:
            jumlahMatkul == 0 ? tidakada(2) : lihatMatkul(jumlahMatkul);
            break;
        case 5:
            jumlahMatkul == 0 ? tidakada(2) : hitungIPK(jumlahMatkul);
            break;
        case 6:
            if (jumlahMatkul == 0 && jumlahArray == 0)
            {
                tidakada(3);
            }
            else
            {
                updateIPK(jumlahArray, jumlahMatkul);
            }
            break;
        case 7:
            ulang = 't';
            break;
        default:
            cout << "Menu tidak ada\n";
            break;
        }
    } while (ulang == 'y');
}

int tambahData(int jumlahArray)
{
    cout << "Masukkan jumlah Mahasiswa[maks 100]: ";
    cin >> jumlahArray;

    for (int i = 0; i < jumlahArray; i++)
    {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "NIM\t: ";
        cin >> mhs[i].nim;
        cout << "Nama\t: ";
        getline(cin >> ws, mhs[i].nama);
        cout << "Semester: ";
        cin >> mhs[i].semester;
        cout << "IPK[1..4]: ";
        cin >> mhs[i].ipk;
        cout << "-------------------\n";
    }
    cout << "Data Sukses ditambahkan";
    return jumlahArray;
}

void lihatData(int jumlahArray)
{
    cout << "Jumlah Data Mahasiswa = " << jumlahArray << endl;
    for (int i = 0; i < jumlahArray; i++)
    {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "NIM\t: " << mhs[i].nim << endl;
        cout << "Nama\t: " << mhs[i].nama << endl;
        cout << "Semester: " << mhs[i].semester << endl;
        cout << "IPK[1..4]: " << mhs[i].ipk << endl;
        cout << "-------------------\n";
    }
}

int tambahMatkul(int jumlahMatkul)
{
    cout << "Masukkan Mata Kuliah\n";
    cout << "Masukkan Jumlah Matkul[maks 100]: ";
    cin >> jumlahMatkul;

    for (int i = 0; i < jumlahMatkul; i++)
    {
        cout << "Matkul ke-" << i + 1 << ": ";
        getline(cin >> ws, mat[i].namaMatkul);
        cout << "Semester: ";
        cin >> mat[i].semester;
    }
    return jumlahMatkul;
}

void lihatMatkul(int jumlahMatkul)
{
    for (int i = 0; i < jumlahMatkul; i++)
    {
        cout << "Semester-" << mat[i].semester << ": " << mat[i].namaMatkul << endl;
    }
}

void hitungIPK(int jumlahMatkul)
{
    int n;
    float ipkumulatif = 0;

    cout << "Hitung IPK\n";

    for (int i = 0; i < jumlahMatkul; i++)
    {
        cout << "Semester-" << mat[i].semester << " " << mat[i].namaMatkul << " = Nilai [1-100]: ";
        cin >> ip[i].nilai;
        if (ip[i].nilai <= 100 && ip[i].nilai >= 80)
        {
            ip[i].angka = 4;
            ip[i].huruf = 'A';
        }
        else if (ip[i].nilai < 80 && ip[i].nilai >= 70)
        {
            ip[i].angka = 3;
            ip[i].huruf = 'B';
        }
        else if (ip[i].nilai < 70 && ip[i].nilai >= 60)
        {
            ip[i].angka = 2;
            ip[i].huruf = 'C';
        }
        else if (ip[i].nilai < 60 && ip[i].nilai >= 50)
        {
            ip[i].angka = 1;
            ip[i].huruf = 'D';
        }
        else
        {
            ip[i].angka = 0;
            ip[i].huruf = 'E';
        }
        cout << "IP Angka = " << ip[i].angka << endl;
        cout << "IP Huruf = " << ip[i].huruf << endl;
        ipkumulatif += ip[i].angka;
    }
    ipkumulatif = ipkumulatif / jumlahMatkul;
    cout << "IPK mahasiswa = " << ipkumulatif << endl;
}

void updateIPK(int jumlahArray, int jumlahMatkul)
{
    float ipkumulatif = 0;
    string nim;

    lihatData(jumlahArray);
    cout << "------------------------\n";
    cout << "Masukkan nim: ";
    cin >> nim;

    int index = cariIndex(jumlahArray, nim);

    if (index != -1)
    {
        cout << "Update IPK " << mhs[index].nama << endl;

        for (int i = 0; i < jumlahMatkul; i++)
        {

            cout << "Semester-" << mat[i].semester << " " << mat[i].namaMatkul << " = Nilai [1-100]: ";
            cin >> ip[index].nilai;
            if (ip[index].nilai <= 100 && ip[index].nilai >= 80)
            {
                ip[index].angka = 4;
                ip[index].huruf = 'A';
            }
            else if (ip[index].nilai < 80 && ip[index].nilai >= 70)
            {
                ip[index].angka = 3;
                ip[index].huruf = 'B';
            }
            else if (ip[index].nilai < 70 && ip[index].nilai >= 60)
            {
                ip[index].angka = 2;
                ip[index].huruf = 'C';
            }
            else if (ip[index].nilai < 60 && ip[index].nilai >= 50)
            {
                ip[index].angka = 1;
                ip[index].huruf = 'D';
            }
            else
            {
                ip[index].angka = 0;
                ip[index].huruf = 'E';
            }
            cout << "IP Angka = " << ip[index].angka << endl;
            cout << "IP Huruf = " << ip[index].huruf << endl;
            ipkumulatif += ip[index].angka;
        }
        ipkumulatif = ipkumulatif / jumlahMatkul;
        mhs[index].ipk = ipkumulatif;
        cout << "IPK " << mhs[index].nim << "-" << mhs[index].nama << " = " << ipkumulatif << endl;
    }
}