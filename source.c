#include "header.h"
#include "color.h"

void tampilMenu()
{
	system("cls");
	printf(HYEL"\n\t===============================================");
	printf("\n\t|| 	  Perusahaan RealEstateXYZ 	     ||");
	printf("\n\t||	    [1]. Kontrak Sales		     ||");
	printf("\n\t||	    [2]. Input Properti		     ||");
	printf("\n\t||	    [3]. Tampil Laporan		     ||");
	printf("\n\t||	    [4]. Update 		     ||");
	printf("\n\t||	    [5]. Jual Properti		     ||");
	printf("\n\t||	    [6]. Resign			     ||");
	printf("\n\t||	    [0]. Exit			     ||");
	printf("\n\t==============================================="reset);
	
}

void tampilMenu3()
{
	system("cls");
	printf(HYEL"\n\t==========================================================================");
	printf("\n\t||									||");
	printf("\n\t|| 	  			LAPORAN  	     			||");
	printf("\n\t||									||");
	printf("\n\t||	    [1]. Tampil All		     				||");
	printf("\n\t||	    [2]. Daftar Properti yang belum terjual oleh sales	    	||");
	printf("\n\t||	    [3]. Jumlah seluruh properti yang belum terjual		||");
	printf("\n\t||	    [0]. Exit			     				||");
	printf("\n\t||									||");
	printf("\n\t=========================================================================="reset);
}

void tampilMenu4()
{
	system("cls");
	printf(HYEL"\n\t===============================================");
	printf("\n\t|| 	  	   Update 	     	     ||");
	printf("\n\t||	[1]. Update Sales		     ||");
	printf("\n\t||	[2]. Update Properti		     ||");
	printf("\n\t||	[3]. Delete Properti		     ||");
	printf("\n\t||	[0]. Exit			     ||");
	printf("\n\t==============================================="reset);
}

void createEmpty(Multilist *l)
{
	l->firstParent = NULL;
}
bool isEmpty(Multilist l)
{
	return l.firstParent == NULL;
}
