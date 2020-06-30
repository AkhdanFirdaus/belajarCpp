#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, a, b, c, x;
	int array[10];
	char kode;
	char huruf[20];
	float n, bil, rat, sum, total = 0;

	do
	{
		printf("MENU PROGRAM PEMANGGILAN PROSEDUR\n");
		printf(" ______________________ \n");
		printf("| a. Mengitung rata rata N buah bilangan bulat dari input        |\n");
		printf("| b. Memasukan dan menampilkan N buah array 1 dimensi dari input |\n");
		printf("| c. Selection sort huruf yang dibaca dari input                 |\n");
		printf("| d. Keluar                                                      |\n");
		printf("|______________________|\n");
		printf("Silahkan pilih huruf anda (a-d) : ");
		scanf("%c", &kode);

		switch (kode)
		{
		case 'a':
			printf(" __________________\n");
			printf("|Mengitung rata rata N buah bilangan bulat dari input|\n");
			printf("|__________________|\n");
			printf("Masukan jumlah bilangan yang akan di input : ");
			scanf("%f", &n);
			for (j = 1; j <= n; j++)
			{
				printf("Masukan bilangan ke-%i = ", j);
				scanf("%f", &bil);
				sum = sum + bil;
			}
			rat = sum / n;
			printf("Rata rata bilangan : %.1f\n", rat);
			break;
		case 'b':
			printf(" _____________ \n");
			printf("| PROGRAM MENAMPILKAN DATA DENGAN ARRAY |\n");
			printf("|_____________|\n");
			printf("Masukkan Banyaknya Data: ");
			scanf("%f", &n);

			for (i = 0; i < n; i++)
			{
				printf("Data ke-%d: ", i + 1);
				scanf("%d", &array[i]);
			}
			printf("____________\n");
			printf("Datanya adalah sebagai berikut! \n");
			printf("____________\n");
			for (i = 0; i < n; i++)
			{
				printf("Data ke-%d: %d", i + 1, array[i]);
				printf("\n");
			}
			break;
		case 'c':
			printf(" _________ \n");
			printf("| PROGRAM SORTING HURUF |\n");
			printf("|_________|\n");
			printf("\n");
			printf("Masukkan jumlah maksimal: ");
			scanf("%d", &x);
			printf("\n");
			for (i = 0; i < x; i++)
			{
				printf("Masukkan huruf ke-%d = ", (i + 1));
				scanf("%s", &huruf[i]);
			}
			printf("\nData sebelum diurutkan: \n");
			for (i = 0; i < x; i++)
			{
				printf("%c ", huruf[i]);
			}
			printf("\n");
			for (i = 0; i < x - 1; i++)
			{
				for (j = 0; j < x - 1 - i; j++)
				{
					if (huruf[j] > huruf[j + 1])
					{
						int tmp;
						tmp = huruf[j];
						huruf[j] = huruf[j + 1];
						huruf[j + 1] = tmp;
					}
				}
			}
			printf("\n");
			printf("\nUrutan berdasarkan huruf: \n");
			for (i = 0; i < x; i++)
			{
				printf("%c ", huruf[i]);
			}
			printf("\n");
			break;
		case 'd':
			break;
		}

	} while (kode != 'd');
	printf("____________\n\n");
	printf("Anda telah keluar dari program ini\n");
	return 0;
}