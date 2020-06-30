#include <iostream>

using namespace std;

void tukarNilaiRupiah(float &val)
{
    val = val * 0.000070;
}

void tukarNilaiDollar(float &val)
{
    val = val * 14191.27;
}

int main()
{
    int pilih;
    float nilai;
    do
    {
        cout << "Program Tukar Nilai per Tgl 27 Juni 2020\n";
        cout << "1. IDR to USD\n";
        cout << "2. USD to IDR\n";
        cout << "3. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Nilai: ";
            cin >> nilai;
            tukarNilaiRupiah(nilai);
            cout << "Nilai tukar = USD. " << nilai << endl;
            break;
        case 2:
            cout << "Nilai: ";
            cin >> nilai;
            tukarNilaiDollar(nilai);
            cout << "Nilai tukar = Rp. " << nilai << endl;
            break;
        default:
            cout << "Program Selesai\n";
            break;
        }
        cout << endl;
    } while (pilih != 3);
}