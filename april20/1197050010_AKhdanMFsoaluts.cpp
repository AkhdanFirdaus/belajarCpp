#include <iostream>

using namespace std;

int main()
{
    int daftarHarga[6] = {150, 8000, 10000, 25000, 35000, 2500};
    string daftarMenu[6] = {"lembar", "jilid a4", "jilid f4", "jilid hard cover", "jilid hard cover buku", "print foto a4"};
    char ulang;
    int i, pilihMenu, jumlahLembar, sisaBagi, bonus = 0, total = 0, subtotal = 0;

    cout << "\t\t  Fotokopi\n";
    cout << "\t\tDaftar Harga\n";
    cout << "|================================================\n";
    cout << "| No |\t\tJasa\t\t|\tHarga\t|\n";
    cout << "|================================================\n";
    for (i = 0; i < 6; i++)
    {
        cout << "| " << i + 1 << "  | " << daftarMenu[i] << "\t\t| " << daftarHarga[i] << "\t|\n";
    }
    cout << "|================================================\n";

    do
    {
        cout << "Pilih menu[1-6]: ";
        cin >> pilihMenu;

        if (pilihMenu > 0 && pilihMenu <= 6)
        {
            cout << "-----------------\n";
            cout << "Print " << daftarMenu[pilihMenu - 1] << endl;
            cout << "Harga\t\t: " << daftarHarga[pilihMenu - 1] << endl;
            cout << "Jumlah lembar\t: ";
            cin >> jumlahLembar;

            if (pilihMenu == 4)
            {
                if (jumlahLembar > 100)
                {
                    sisaBagi = jumlahLembar % 100;
                    jumlahLembar -= sisaBagi;
                    jumlahLembar = jumlahLembar / 100;
                    if (sisaBagi != 0)
                    {
                        jumlahLembar++;
                    }
                }
                else
                {
                    jumlahLembar = 1;
                }
                cout << "Jumlah kelipatan: " << jumlahLembar << endl;
                subtotal = daftarHarga[pilihMenu - 1] * jumlahLembar;
            }
            else if (pilihMenu == 5)
            {
                if (jumlahLembar > 250)
                {
                    sisaBagi = jumlahLembar % 250;
                    jumlahLembar -= sisaBagi;
                    jumlahLembar = jumlahLembar / 250;
                    if (sisaBagi != 0)
                    {
                        jumlahLembar++;
                    }
                }
                else
                {
                    jumlahLembar = 1;
                }
                cout << "Jumlah kelipatan: " << jumlahLembar << endl;
                subtotal = daftarHarga[pilihMenu - 1] * jumlahLembar;
            }
            else if (pilihMenu == 6)
            {
                sisaBagi = jumlahLembar % 3;
                if (sisaBagi == 1)
                {
                    bonus = jumlahLembar - 1;
                }
                bonus = bonus / 3;
                cout << "Jumlah Bonus\t: " << bonus << endl;
                subtotal = daftarHarga[pilihMenu - 1] * jumlahLembar;
            }
            else
            {
                subtotal = daftarHarga[pilihMenu - 1] * jumlahLembar;
            }
        }
        else
        {
            cout << "maaf pilihan tidak ada\n";
            subtotal = 0;
        }

        total += subtotal;

        cout << "\nSubtotal\t: Rp." << subtotal;

        cout << "\nTambah print lagi (y/t)? ";
        cin >> ulang;
        cout << endl;
    } while (ulang == 'y' || ulang == 'Y');

    cout << "-----------------\n";
    cout << "\nTotal pembayaran: Rp." << total;
    cout << "\nTerimakasih\n";

    system("PAUSE");
    return 0;
}