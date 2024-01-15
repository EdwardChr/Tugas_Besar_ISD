#include "header.h"
#include "color.h"


int main(int argc, char *argv[]) 
{
	Multilist l;
	DataParent S,SPengirim,SPenerima;
	DataChild P;
	addressParent Parent,temp;
	addressChild cari;
	
	int menu, submenu, submenu1,id,idP,noProperti;
	int cek, totalPenjualan;
	float harga;
	char idc, idcsebelum;
	string jenis, nip, nama, noTlp;
	string alamat;
	
	createEmpty(&l);
	
	
	do
	{
		tampilMenu();
		printf(HCYN"\n\tMasukan Pilihan : "); scanf("%d" ,&menu);
	
		
		
		switch(menu)
		{
			case 1:
				do{
					printf(HCYN"\n\tNIP		: "); fflush(stdin); gets(nip);
					if(strlen(nip) < 5)
					{
						printf(HRED"\n\t\t[!] NIP Tidak Boleh Kosong dan Minimal 5 digit [!]\n"reset);
						cek=0;
					}else if(findParent(l,nip))
					{
						printf(HRED"\n\t\t[!] NIP Harus Unik [!]\n"reset);
						cek=0;
					}
					else
					{
						cek=1;
					}
				}while(cek==0);	
				
				do{
					printf(HCYN"\n\tNama		: ");fflush(stdin); gets(nama);
					if(strlen(nama) == 0)
					{
						printf(HRED"\n\t\t[!] Data tidak boleh kosong! [!]\n"reset);
					}

				}while(strlen(nama) == 0);

				do{
					printf(HCYN"\n\tNomor Telepon	: ");fflush(stdin); gets(noTlp);
					printf(" "reset);
					if(strlen(noTlp) < 9)
					{
						printf(HRED"\n\t\t[!] Data tidak boleh kosong! [!]\n"reset);
					}

				}while(strlen(noTlp) <9);
				totalPenjualan = 0;
				
							
				insertFirstParent(&l, makeDataParent(nip, nama, noTlp, totalPenjualan)); 
				printf(HGRN"\n\t-------------------------------------------------------");
				printf("\n\n\t\t[+] Data berhasil diinput! [+]"reset);
				
				break;
				
			case 2:
				if(isEmpty(l))
				{
					system("cls");
					printf(HRED"\n\n\n\t\t[!] List Kosong [!]"reset);
				}else
				{
					printf(HCYN"\n\tMasukan NIP Sales	: ");fflush(stdin); gets(nip);
					if(!findParent(l,nip))
					{
						printf(HRED"\n\t\t[!] Data Sales dengan NIP tersebut tidak ditemukan! [!]"reset);
					}
					else
					{
//						printf("\n\tTesss");
						addressParent temp = findParent(l, nip);
						do
						{
							printf(HCYN"\n\tNo Properti		: "); scanf("%d", &noProperti);
							if(noProperti < 1)
							{
								printf(HRED"\n\t[\t!] Data tidak valid! [!]"reset);
								cek=0;
							}
							else if(findNodeChild(temp, makeDataChild(noProperti, "-", "-", 0.0f)))
							{
								printf(HRED"\n\t\t[!] No Properti tidak boleh sama [!]"reset);
								cek=0;
							}
							else
							{
								cek=1;
							}
						}while(cek==0);	
					
						do{
							printf(HCYN"\n\tJenis (tanah/rumah)	: ");fflush(stdin); gets(jenis);
							if(strlen(jenis) == 0)
							{
								printf(HRED"\n\t[!] Data tidak valid! [!]"reset);
							}
							else if(strcmpi(jenis, "Tanah") != 0 && strcmpi(jenis, "Rumah") != 0 )
							{
								printf(HRED"\n\t[!] Jenis tidak tersedia! [!]\n"reset);
							}
						

						}while(strlen(jenis) == 0 || strcmpi(jenis, "Tanah") != 0 && strcmpi(jenis, "Rumah") != 0 );

						do{
							printf(HCYN"\n\tAlamat			: ");fflush(stdin); gets(alamat);
							if(strlen(alamat) == 0)
							{
								printf(HRED"\n\t\t[!] Data tidak boleh kosong [!]\n"reset);
							}

						}while(strlen(alamat) == 0);
					
						do{
							printf(HCYN"\n\tHarga			: "); scanf("%f", &harga);
							if(harga < 1)
							{
								printf(HRED"\n\t[!] Data tidak valid! [!]"reset);
								cek=0;
							}else if(harga == 0)
							{
								printf(HRED"\n\t[!] Harga Tidak Boleh Kosong [!]"reset);
								cek=0;
							}else
							{
								cek=1;
							}
				
						}while(cek==0);
					
						insertFirstChild(l,nip,makeDataChild(noProperti, jenis, alamat, harga));
						printf(HGRN"\n\t------------------------------------------------------");
						printf("\n\n\t\t[+] Data berhasil diinput! [+]"reset);

					}
				}
				
				
				break;
				
			case 3:
				if(isEmpty(l))
				{
					system("cls");
					printf(HRED"\n\n\n\t\t[!] List Kosong [!]"reset);
				}else
				{
					do
					{
						tampilMenu3();
						printf(HCYN"\n\tMasukkan Pilihan : "); scanf("%d", &submenu);

						switch(submenu)
						{
							case 1:
								printAll(l,l.firstParent);
							
								break;
							
            	            case 2:
         	                   printf("\n\tMasukan NIP Sales : "); fflush(stdin); gets(S.nip);
                            	if (!findParent(l, S.nip)) {
                                	printf(HRED"\n\t[!] Data Sales dengan NIP tersebut tidak ditemukan! [!]"reset);
                        	    } else {
                       	    	    printf("\n\tJenis Properti : "); fflush(stdin); gets(P.jenis);
                       	        	if (findJenis(findParent(l, S.nip), P.jenis)) {
                    	                printProperti(l, S.nip, P.jenis);
                    	            } else {
                    	                printf(HRED"\n\t\t[!] Jenis Properti tidak ditemukan [!]\n"reset);
                    	            }
                    	        }
                    	        break;
						
							case 3:
							    do
								{
									printf(HCYN"\n\tJenis Properti (tanah/rumah)	: ");fflush(stdin); gets(jenis);
									if(strlen(jenis) == 0)
									{
										printf(HRED"\n\t[!] Data tidak valid! [!]"reset);
									}
									else if(strcmpi(jenis, "Tanah") != 0 && strcmpi(jenis, "Rumah") != 0 )
									{
										printf(HRED"\n\t[!] Jenis tidak tersedia! [!]\n"reset);
									}
							    	
						    	}while(strlen(jenis) == 0 || strcmpi(jenis, "Tanah") != 0 && strcmpi(jenis, "Rumah") != 0 );
						    	printf("\n\tBanyak Properti dengan Jenis %s : %d", jenis, propertiByJenis(l,jenis));
							    break;
								
							case 0:
								system("cls");
								printf(HGRN"\n\t\t[~] Kembali ke Main Menu [~]"reset);
								break;
							default:
								system("cls");
								printf(HRED"\n\n\n\t\t[!] Input Menu Salah [!]"reset);
							
						}getch();
					}while(submenu!=0);
				}
				
				
				break;
				
				case 4:
					if(isEmpty(l))
					{
						system("cls");
						printf(HRED"\n\n\n\t\t[!] List Kosong [!]"reset);
					}else
					{
						do
						{
							tampilMenu4();
							printf(HCYN"\n\tMasukkan Pilihan : "); scanf("%d", &submenu);
							
							switch(submenu)
							{
								case 1:
									printf("Masukan NIP Sales : "); fflush(stdin); gets(S.nip);
                            		if (!findParent(l, S.nip)) 
									{
                            	    	printf("\nData Sales dengan NIP tersebut tidak ditemukan!");
                        		    }else
                        		    {
                        		    	ubahDataParent(&l, nip);
									}
									break;
									
								case 2:
									printf(HCYN"\n\tMasukan NIP Sales : "); fflush(stdin); gets(nip);
                            		temp = findParent(l, nip);
                            		
                            		if(temp != NULL)
                            		{
                            			printf("\n\tNomor Properti yang ingin di Ubah	: ");scanf("%d", &noProperti);
                            			
                            			cari = findChild(temp, noProperti);
                            			
                            			if(cari != NULL)
                            			{
                            				ubahData(cari);
                            				printf(" "reset);
										}else
										{
											printf(HRED"\n\t\t[!] Nomor Properti Tidak Ditemukan [!]"reset);
										}
									}else
									{
										printf(HRED"\n\t\t[!] Data Sales dengan NIP tersebut tidak ditemukan [!]"reset);
									}
                        		    
									break;
									
								case 3:
									printf(HCYN"\n\tMasukan NIP Sales : "); fflush(stdin); gets(S.nip);
                            		if (!findParent(l, S.nip)) 
									{
                            	    	printf(HRED"\n\t\t[!] Data Sales dengan NIP tersebut tidak ditemukan [!]"reset);
                        		    }else
                        		    {
                        		    	printf("Masukkan Nomor properti yang ingin di Hapus : "); scanf("%d", &P.noProperti);
										addressParent temp = findParent(l, S.nip);
										printf(" "reset);

        								if (findNodeChild(temp, P)) 
										{
            							deleteAtChild2(&l, S.nip, P);
            							printf(HGRN"\n\t\t[~] Properti berhasil di Hapus [~]"reset);
										}
									}
									break;
									
								case 0:
									system("cls");
									printf(HGRN"\n\t\t[~] Kembali ke Main Menu [~]"reset);
									break;
								
								default:
									system("cls");
									printf(HRED"\n\n\n\t\t[!] Input Menu Salah [!]"reset);
								
							}getch();
							
						}while(submenu!=0);
						
					}
					break;
					
				
				case 5:
					if(isEmpty(l))
					{
						system("cls");
						printf(HRED"\n\n\n\t\t[!] List Kosong [!]"reset);
					}else
					{
						printf("\n\tMasukkan NIP Sales : "); fflush(stdin); gets(S.nip);
					    if (!findParent(l, S.nip)) 
						{
        					printf(HRED"\n\t\t[!] Data Sales dengan NIP tersebut tidak ditemukan [!]\n"reset);
    					} else 
						{
        					printf("\n\tMasukkan Nomor properti yang ingin dijual : "); scanf("%d", &P.noProperti);
							addressParent temp = findParent(l, S.nip);

        					if (findNodeChild(temp, P)) 
							{
            					deleteAtChild(&l, S.nip, P);
            					printf("\n\t\t[~] Properti berhasil dijual [~]");
       				  		}else 
							{
            				printf(HRED"\n\t\tNomor Properti tidak ditemukan [!]"reset);
        					}
    					}
					}
   					
    			break;
				
			case 6:
				if(isEmpty(l))
				{
					system("cls");
					printf(HRED"\n\n\n\t\t[!] List Kosong [!]"reset);
				}else
				{
					do
					{
						printf(HCYN"\n\tMasukkan NIP sales yang mengundurkan diri : ");fflush(stdin); gets(SPengirim.nip);
						if (!findParent(l, SPengirim.nip)) 
						{
        					printf(HRED"\n\t[!] Data Sales dengan NIP tersebut tidak ditemukan! [!]\n"reset);
        					cek=0;
        			
    					} else 
						{
        					printf("\n\tMasukkan NIP sales yang akan menerima tanggungan : ");fflush(stdin); gets(SPenerima.nip);
        					if (!findParent(l, SPenerima.nip)) 
							{
        						printf(HRED"\n\t[!] Data Sales dengan NIP tersebut tidak ditemukan! [!]\n"reset);
        						cek=0;
        				
    						}else
    						{
    							addressParent temp = findParent(l, S.nip);
							}
							
							cek=1;
						}
					}while(cek==0);
				

					transferProperti(&l,SPengirim,SPenerima);
				}
				

				break;
				
			case 0:
				printf(BHCYN"\n\tNama Anggota : ");
				printf("\n\t1. Alya Nur Hanifah          / 200710650");
				printf("\n\t2. Jhery Pranata Sebayang    / 210711375");
				printf("\n\t3. Edward Christian Pasaribu / 210711360");
				printf("\n\t4. Bima Wahyu Laksono        / 210711339");
				printf("\n\t5. Yosep Fery Pernando       / 210711479",reset);
				
				
				printf(HGRN"\n\n\t\t [~] Have nice Day [~]"reset);
				break;
				
			default:
				system("cls");
				printf(HRED"\n\n\n\t\t[!] Input Menu Salah [!]"reset);
		}getch();
		
	}while(menu!=0);
	return 0;
}


