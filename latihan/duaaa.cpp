#include <iostream>

using namespace std;

int tunjangan(int gaji, int jmlAnak)
{
    int tunjangan = 0;
    if (jmlAnak > 0 && jmlAnak < 3)
    {
        tunjangan = (gaji * 0.10) * jmlAnak;
    }
    else
    {
        tunjangan = 400000;
    }
    return tunjangan;
}

int main()
{
    int gaji, jmlAnak;
    cout << "Masukkan Gaji Pokok : ";
    cin >> gaji;
    cout << "Masukkan Jumlah Anak: ";
    cin >> jmlAnak;
    cout << "Gaji Pokok     : " << gaji << endl;
    cout << "Tunjangan Anak : " << tunjangan(gaji, jmlAnak) << endl;
    cout << "Gaji Bersih    : " << gaji + tunjangan(gaji, jmlAnak) << endl;
}