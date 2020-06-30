#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;
main(){
	
	string matkul[3] = {"alpro", "kalkulus", "inggris"};
	int nilai[3];
	string indeks[3];
	int sks[3];
	float j[3];
	float ip;
	
	for (int i=0; i<3; i++){
		cout << matkul[i]<<endl;
		cout << "\nNilai(A-E)		:";cin>>indeks[i];
		if (indeks[i] == "A" || indeks[i] == "a"){
			nilai[i] = 4;
		}
		else if (indeks[i] == "B" || indeks[i] == "b"){
			nilai[i] = 3;
		}
		else if (indeks[i] == "C" || indeks[i] == "c"){
			nilai[i] = 2;
		}
		else if (indeks[i] == "D" || indeks[i] == "d"){
			nilai[i] = 1;
		}
		else if (indeks[i] == "E" || indeks[i] == "e"){
			nilai[i] = 0;
		}
		cout << "Beban Sks		:";cin>> sks[i];
	}
	for(int i=0; i <3; i++){
		j[i] = nilai[i]*sks[1];
	}
	ip = (j[0]+j[1]+j[2])/(sks[0]+sks[1]+sks[2]);
	cout << "IP = "<<ip;
	
}
