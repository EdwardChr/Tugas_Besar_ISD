#include "header.h"
#include "color.h"

DataParent makeDataParent(string nip, string nama, string telepon, int totPenjualan){
	DataParent data;
	
	strcpy(data.nip, nip);
	strcpy(data.nama, nama);
	strcpy(data.noTlp, telepon);
	data.totalPenjualan = totPenjualan;
	
	return data;
	
}

addressParent alokasiParent(DataParent data){
	addressParent ap;
	
	ap = (addressParent)malloc(sizeof(NodeParent));
	ap->next = NULL;
	ap->firstChild = NULL;
	ap->dataParent = data;
	 
	return ap;
	
}

addressParent findParent(Multilist l, string nip) 
{
    addressParent ap = l.firstParent;

    while (ap != NULL) 
	{
        if (strcmpi(ap->dataParent.nip, nip) == 0) 
		{
            return ap;
        }
        ap = ap->next;
    }

    return NULL;
}

bool haveChild(addressParent ap){
	return ap->firstChild != NULL;
}

bool findJenis(addressParent parent, string jenis) {
    addressChild dapat = parent->firstChild;

    while (dapat != NULL) {
        if (strcmpi(dapat->dataChild.jenis, jenis) == 0) {
            return true; 
        }
        dapat = dapat->next;
    }

    return false;
}

bool findnoProperti(addressParent parent, int noProperti) {
    addressChild dapat = parent->firstChild;

    while (dapat != NULL) {
        if (dapat->dataChild.noProperti== noProperti) {
            return true; 
        }
        dapat = dapat->next;
    }

    return false;
}

void printProperti(Multilist l, string nip, string jenis) {
    addressParent parent = findParent(l, nip);

    if (parent != NULL) {
        addressChild dapat = parent->firstChild;

        printf(BHBLU"\n\tJenis Properti %s dengan NIP Sales %s:\n", jenis, nip);
    

        while (dapat != NULL) {
            if (strcmpi(dapat->dataChild.jenis, jenis) == 0) {
                printChild(dapat);
            }
            dapat = dapat->next;
        }
    } else {
        printf(HRED"\n\t\t[!] Data Sales dengan NIP %s tidak ditemukan [!]\n", nip);
    	printf(" "reset);
	}
}

void transferProperti(Multilist *l, DataParent SPengirim, DataParent SPenerima) {
    addressParent pengirim = findParent(*l, SPengirim.nip);
    addressParent penerima = findParent(*l, SPenerima.nip);

    if (pengirim == NULL || penerima == NULL) {
        printf(reset"\n\t[!] Data Sales tidak ditemukan [!]\n"reset);
        return;
    }

   
    addressChild current = pengirim->firstChild;
    while (current != NULL) {
        insertLastChild(*l, SPenerima.nip, current->dataChild);
        current = current->next;
    }

   
    penerima->dataParent.totalPenjualan += pengirim->dataParent.totalPenjualan;

    deleteParentAt(l, SPengirim.nip);

    printf(HGRN"\n\t\t[~] Tanggungan properti berhasil dialihkan ke sales yang baru [~]\n"reset);
}

void insertFirstParent(Multilist *l, DataParent data){
	addressParent p = alokasiParent(data);
	
	p->next = l->firstParent;
	l->firstParent = p;
}



void printAllParent(Multilist l){

 	addressParent temp = l.firstParent;

	while(temp != NULL){
		printParent(temp);
		printf("\n");
		temp = temp->next;
	}
}



void printAll(Multilist l, addressParent parent) {
    addressParent temp = l.firstParent;
    while (temp != NULL) {
        printf(HCYN"\n\t---== Sales ==---");
		printParent(temp);
        printf("\n");
        printf(HCYN"\n\t\t---== Properti ==--");
        printAllChild(temp);
        printf(HGRN"\n\t-------------------------------------"reset);
        temp = temp->next;
        printf("\n");
    }
}

void insertLastParent(Multilist *l, DataParent data){
    addressParent newParent = alokasiParent(data);

    if (isEmpty(*l)) {
        (*l).firstParent = newParent;
    } else {
        addressParent current = (*l).firstParent;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newParent;
    }
}

void deleteFirstParent(Multilist *l) {
    if (isEmpty(*l)) {
        printf(HRED"\n\t\t [!] Data Masih Kosong [!]\n"reset);
        return;
    }
    addressParent temp = (*l).firstParent;

    (*l).firstParent = temp->next;

    free(temp);
    temp = NULL;
}

void deleteLastParent(Multilist *l) {
    if (isEmpty(*l)) {
        printf(HRED"\n\t\t [!] Data Masih Kosong [!]\n"reset);
        return;
    }
    addressParent current = (*l).firstParent;
    addressParent prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        (*l).firstParent = NULL;
    } else {
        prev->next = NULL;
    }

    free(current);
    current = NULL;
}

void deleteParentAt(Multilist *l, string nip) {
    if (isEmpty(*l)) {
        printf(HRED"\n\t\t [!] Data Masih Kosong [!]\n"reset);
        return;
    }

    addressParent current = l->firstParent;
    addressParent prev = NULL;

    while (current != NULL && strcmpi(current->dataParent.nip, nip) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf(HRED"\n\t\t[!] Data Sales dengan NIP %s tidak ditemukan [!] \n", nip);
        printf(" "reset);
        return;
    }

    if (prev == NULL) {
        l->firstParent = current->next;
    } else {
        prev->next = current->next;
    }

    freeParent(current);
    printf(HGRN"\n\t\t\t[~] Data Sales dengan NIP %s berhasil dihapus [~]\n", nip);
    printf(" "reset);
}

void freeParent(addressParent parent) {
    addressChild current = parent->firstChild;
    while (current != NULL) {
        addressChild temp = current;
        current = current->next;
        free(temp);
    }

    free(parent);
}


void printParent(addressParent parent){
	printf(HCYN"\n\t NIP             : %s", parent->dataParent.nip);
	printf("\n\t Nama            : %s", parent->dataParent.nama);
	printf("\n\t No Telepon      : %s", parent->dataParent.noTlp);
	printf("\n\t Total Penjualan : %d", parent->dataParent.totalPenjualan);
}

void ubahDataParent(Multilist *l, string nip) {
    addressParent current = findParent(*l, nip);

    if (current != NULL) {
        printf("\tMasukkan data baru:\n");
        printf("\tNama: "); scanf("%s", current->dataParent.nama);
        printf("\tNomor Telepon: "); scanf("%s", current->dataParent.noTlp);
//        printf("\tTotal Penjualan: "); scanf("%d", &current->dataParent.totalPenjualan);
        printf(HGRN"\n\t\t[+] Data berhasil diubah. [+]\n"reset);
    } else {
        printf(HRED"\n\t[!] Data dengan NIP %s tidak ditemukan. [!]\n"reset, nip);
    }
}

