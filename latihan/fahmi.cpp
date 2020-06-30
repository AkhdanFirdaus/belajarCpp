#include <iostream>

using namespace std;

char *nama_bulan(int n)
{
    char *bulan[] = {"Kode bulan Salah!!", "Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    return bulan[0];
}

int main()
{

    int bln;

    printf("Bulan (1-12) : ");
    scanf("%d", &bln);
    printf("Bulan ke- %d adalah bulan %s\n", bln, nama_bulan(bln));
}