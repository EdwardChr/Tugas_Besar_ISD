#include "header.h"
#include "color.h"


DataChild makeDataChild(int noProperti, string jenis, string alamat, float harga){
	DataChild data;
	
	data.noProperti = noProperti;
	strcpy(data.jenis, jenis);
	strcpy(data.alamat, alamat);
	data.harga = harga;
	
	return data;
}


addressChild alokasiChild(DataChild data){
	addressChild ac;
	ac = (addressChild)malloc(sizeof(NodeChild));
	
	ac->next = NULL;
	ac->dataChild = data;
	
	return ac;
}


void insertFirstChild(Multilist l, string nip, DataChild data){
    addressParent p = findParent(l, nip);
    addressChild c;

    if(p != NULL){
        c = alokasiChild(data);
        c->next = p->firstChild;
        p->firstChild = c;
    }
}

bool findNodeChild(addressParent parent, DataChild data) {
    addressChild current = parent->firstChild;

    while (current != NULL) {
        if (current->dataChild.noProperti == data.noProperti) {
            return true; 
        }
        current = current->next;
    }

    return false; 
}


void insertLastChild(Multilist l, string nip, DataChild data){
	addressParent p = findParent(l, nip);
	addressChild temp, newData;
	
	if(p!=NULL){
		if(!haveChild(p))
			insertFirstChild(l, nip, data);
		else{
			temp = p->firstChild;
			newData = alokasiChild(data);
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newData;
		}
	}
}


void deleteFirstChild(Multilist l, string nip){
	addressParent p = findParent(l, nip);
	
	if(p != NULL){
		if(haveChild(p)){
			addressChild temp = p->firstChild;
			p->firstChild = p->firstChild->next;
			
			free(temp);
		}
	}
}

void deleteAtChild(Multilist *l, string nip, DataChild data) {
    addressParent parent = findParent(*l, nip);

    if (parent == NULL) {
        printf(HRED"\n\t[!] Data Sales dengan NIP tersebut tidak ditemukan [!]\n"reset);
        return;
    }

    addressChild current = parent->firstChild;
    addressChild prev = NULL;

    while (current != NULL && current->dataChild.noProperti != data.noProperti) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf(HRED"\n\t\t[!] Nomor Properti tidak ditemukan [!]\n"reset);
        return;
    }

    parent->dataParent.totalPenjualan += current->dataChild.harga;

    if (prev == NULL) {
        parent->firstChild = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void deleteAtChild2(Multilist *l, string nip, DataChild data) {
    addressParent parent = findParent(*l, nip);

    if (parent == NULL) {
        printf(HRED"\n\t[!] Data Sales dengan NIP tersebut tidak ditemukan [!]\n"reset);
        return;
    }

    addressChild current = parent->firstChild;
    addressChild prev = NULL;

    while (current != NULL && current->dataChild.noProperti != data.noProperti) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf(HRED"\n\t\t[!] Nomor Properti tidak ditemukan [!]\n"reset);
        return;
    }

    if (prev == NULL) {
        parent->firstChild = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

int propertiByJenis(Multilist l, string jenis) {
    int count = 0;

    addressParent current = l.firstParent;

    while (current != NULL) {
        addressChild child = current->firstChild;

        while (child != NULL) {
            if (strcmpi(child->dataChild.jenis, jenis) == 0) {
                count++;
            }

            child = child->next;
        }

        current = current->next;
    }

    return count;
}


void printChild(addressChild child){
	printf(HCYN"\n\t\t No Properti    : %d", child->dataChild.noProperti);
	printf("\n\t\t Jenis Properti : %s", child->dataChild.jenis);
	printf("\n\t\t Alamat         : %s", child->dataChild.alamat);
	printf("\n\t\t Harga          : %2.f", child->dataChild.harga);
	printf("\n"reset);
    
}

void printAllChild(addressParent parent) {
    addressChild child = parent->firstChild;

    while (child != NULL) {
        printChild(child);
        child = child->next;
    }
}

void ubahData(addressChild c){
	printf(HGRN"\n\t\t--== Ubah Data ==--"reset);
	
	while(true){
		printf(HCYN"\n\t Jenis Properti : "); fflush(stdin); gets(c->dataChild.jenis);
		
		if(strcmpi(c->dataChild.jenis, "tanah")!=0 && strcmpi(c->dataChild.jenis, "rumah")!=0){
			printf(HRED"\n\t\t[!] Jenis Invalid [!]"reset);
		}
		else{
			break;
		}
	}
	printf("\n\t Alamat         :  "); fflush(stdin); gets(c->dataChild.alamat);
	printf("\n\t Harga Properti : "); scanf("%f", &c->dataChild.harga);
	printf(" "reset);
}

addressChild findChild(addressParent p, int nomor)
{
	addressChild temp = p->firstChild;
	
	while(temp!=NULL && temp->dataChild.noProperti != nomor)
	{
		temp=temp->next;
	}
	return temp;
}
