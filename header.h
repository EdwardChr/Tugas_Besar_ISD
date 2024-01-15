#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[100];

typedef struct Child* addressChild;
typedef struct Parent* addressParent;


typedef struct DataChild{
	int noProperti;
	string jenis; // (tanah / rumah)
	string alamat;
	float harga;
}DataChild;

typedef struct DataParent{
	string nip;
	string nama;
	string noTlp;
	int totalPenjualan;
}DataParent;

typedef struct Child{
	DataChild dataChild;
	addressChild next;
}NodeChild;

typedef struct Parent{
	DataParent dataParent;
	addressParent next;
	addressChild firstChild;
}NodeParent;

typedef struct{
	addressParent firstParent;
}Multilist;


// umum+mainFull
// Bima+Alya
void tampilMenu();
void tampilMenu3();
void tampilMenu4();
void tampilMenuUDP();
void createEmpty(Multilist *l);
bool isEmpty(Multilist l);



// parent
// Jhery
DataParent makeDataParent(string nip, string nama, string telepon, int totPenjualan);
addressParent alokasiParent(DataParent data);
addressParent findParent(Multilist l, string nip);
bool haveChild(addressParent ap);
bool findNodeChild(addressParent parent, DataChild data);
void insertFirstParent(Multilist *l, DataParent data);
bool findJenis(addressParent parent, string jenis);
bool findnoProperti(addressParent parent, int noProperti);
void printProperti(Multilist l, string nip, string jenis);
int propertiByJenis(Multilist l, string jenis);
void insertLastChild(Multilist l, string nip, DataChild data);
void transferProperti(Multilist *l, DataParent SPengirim, DataParent SPenerima);
void deleteParentAt(Multilist *l, string nip);
void freeParent(addressParent parent);
// yosep
void insertLastParent(Multilist *l, DataParent data);
void deleteFirstParent(Multilist *l);
void deleteLastParent(Multilist *l);
void printParent(addressParent parent);
void ubahDataParent(Multilist *l, string nip);
void printAll(Multilist l, addressParent parent);
void deleteAtChild2(Multilist *l, string nip, DataChild data);
void deleteAtChild(Multilist *l, string nip, DataChild data);


// child
// Edward
DataChild makeDataChild(int noProperti, string jenis, string alamat, float harga);
addressChild alokasiChild(DataChild data);

void insertFirstChild(Multilist l, string nip, DataChild data);
void insertLastChild(Multilist l, string nip, DataChild data);

void deleteFirstChild(Multilist l, string nip);
//void deleteLastChild(Multilist l, string nip);

void printChild(addressChild child);
void printAllChild(addressParent parent);

void ubahData(addressChild c);
addressChild findChild(addressParent p, int nomor);
