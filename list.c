#include "list .h"

void createList(list *L) {
	first(*L) = NULL;
	last(*L) = NULL;
}

void addFirst(char huruf, list *L) {
	element *baru;
	baru = (element *) malloc(sizeof(element));
	huruf(*baru) = huruf;
	
	if(baru != NULL) {
		if(first(*L) == NULL) {
			next(*baru) = NULL;
			last(*L) = baru;
		} else {
			prev(*first(*L)) = baru;
			next(*baru) = first(*L);
		}
		prev(*baru) = NULL;
		first(*L) = baru; 
		printf("Menambah huruf berhasil\n");
	} else {
		printf("Memori penuh\n");
	}
}

void addAfter(element *prev, char huruf, list *L) {
	if(prev != NULL) {
		element *baru;
		baru = (element *) malloc(sizeof(element));
		huruf(*baru) = huruf;
		if(next(*prev) == NULL) {
			next(*baru) = NULL;
			last(*L) = baru;
		} else {
			next(*baru) = next(*prev);
			prev(*next(*prev)) = baru;
		}
		prev(*baru) = prev;
		next(*prev) = baru;
		printf("Menambah huruf berhasil\n");
	}
}

void addLast(char huruf, list *L) {
	element *baru;
	baru = (element *) malloc(sizeof(element));
	huruf(*baru) = huruf;
	if(first(*L) == NULL) {
		addFirst(huruf, L);
	} else {
		element *beforeLast, *last;
		last = first(*L);
		beforeLast = NULL;
		
		while(last != NULL) {
			beforeLast = last;
			last = next(*last);
		}
		addAfter(beforeLast, huruf, L);
	}
}

void delFirst(list *L) {
	element *hapus;
	hapus = first(*L);
	
	if(hapus != NULL) {
		if(next(*hapus) == NULL) {
			first(*L) = NULL;
			last(*L) = NULL;
		} else {
			first(*L) = next(*hapus);
			prev(*first(*L)) = NULL;
		}
		free(hapus);
		printf("Menghapus huruf berhasil");
	} else {
		printf("Data Kosong\n");
	}
}

void delAfter(element *prev, list *L) {
	if(prev != NULL) {
		element *hapus;
		hapus = next(*prev);
		if(hapus != NULL) {
			if(next(*hapus) == NULL) {
				last(*L) = prev;
				next(*prev) = NULL;
			} else {
				next(*prev) = next(*hapus);
				prev(*next(*hapus)) = prev;
			}
			free(hapus);
			printf("Menghapus huruf berhasil");
		} else {
			printf("Data Kosong");
		}
	}
}

void delLast(list *L) {
	if(first(*L) != NULL) {
		element *last, *beforeLast;
		last = first(*L);
		beforeLast = NULL;
		if(next(*last) == NULL) {
			delFirst(L);
		} else {
			while(last != NULL) {
				beforeLast = last;
				last = next(*last);
			}
			delAfter(beforeLast, L);
		}
	} else {
		printf("Data Kosong\n");
	}
}

void printHurufFirst(list L) {
	element *bantu;
	bantu = first(L);
	
	while(bantu != NULL) {
		printf("%c ", huruf(*bantu));
		bantu = next(*bantu);
	}
}

void printHurufLast(list L) {
	element *bantu;
	bantu = last(L);
	
	while(bantu != NULL) {
		printf("%c ", huruf(*bantu));
		bantu = prev(*bantu);
	}
}

void tampilkanMenuUtama(list *L) {
	system("cls");
	int pilih;
	
	printf("1. Tambahkan huruf.\n");
	printf("2. Hapus huruf. \n");
	printf("3. Tampilkan huruf\n");
	printf("99. Keluar Program.\n");
	scanf("%d", &pilih);
	pilihMenuUtama(pilih, L);
}


void pilihMenuUtama(int pilih, list *L) {
	switch(pilih) {
		case 1: 
			tampilkanMenuTambahkanHuruf(L);
			break;
		case 2: 
			tampilkanMenuHapusHuruf(L);
			break;
		case 3: 
			tampilkanMenuTampilkanHuruf(L);
			break;
		case 99: 
			exit(0);
			break;
		default:
			printf("Pilihan tidak valid\n");
			tampilkanMenuUtama(L);
	}
}

void tampilkanMenuTambahkanHuruf(list *L) {
	system("cls");
	
	int pilih;
	
	printf("1. Tambah diawal.\n");
	printf("2. Tambah ditengah.\n");
	printf("3. Tambah diakhir.\n");
	printf("99. Kembali.\n");
	scanf("%d", &pilih);
	pilihMenuTambahkanHuruf(pilih, L);
}

void pilihMenuTambahkanHuruf(int pilih, list *L) {
	char huruf;
	char prev;
	element *bantu;
	switch(pilih) {
		case 1: 
			huruf = inputHuruf();
			addFirst(huruf, L);
			break;
		case 2: 
			printHurufFirst(*L);
			printf("\ngin menambahkan setelah huruf apa ? \n");
			scanf (" %c", &prev);
			bantu = Search(prev, *L);
			huruf = inputHuruf();
			addAfter(bantu, huruf, L);
			break;
		case 3:
			huruf = inputHuruf();
			addLast(huruf, L);
			break;
		case 99: 
			tampilkanMenuUtama(L);
			break;
		default:
			printf("Pilihan Tidak valid\n");
			tampilkanMenuTambahkanHuruf(L);
	}
	
	printf("\n");
	system("pause");
	tampilkanMenuUtama(L);
}

void tampilkanMenuHapusHuruf(list *L) {
	system("cls");
	
	int pilih;
	
	printf("1. Hapus diawal.\n");
	printf("2. Hapus ditengah.\n");
	printf("3. Hapus diakhir.\n");
	printf("99. Kembali.\n");
	scanf("%d", &pilih);
	pilihMenuHapusHuruf(pilih, L);
}

void pilihMenuHapusHuruf(int pilih, list *L) {
	element *bantu;
	char huruf;
	switch(pilih) {
		case 1: 
			delFirst(L);
			break;
		case 2: 
			printHurufFirst(*L);
			printf("\nIngin menghapus huruf apa ? ");
			scanf(" %c", &huruf);
			bantu = first(*L);
			while(huruf != huruf(*next(*bantu))) {
				bantu = next(*bantu);
			}
			delAfter(bantu, L);
			break;
		case 3: 
			delLast(L);
			break;
		case 99: 
			tampilkanMenuUtama(L);
			break;
		default:
			printf("Pilihan tidak valid\n");
			tampilkanMenuHapusHuruf(L);
	}
	
	printf("\n");
	system("pause");
	tampilkanMenuUtama(L);
} 

void tampilkanMenuTampilkanHuruf(list *L) {
	system("cls");
	
	int pilih;
	
	printf("1. Tampilkan dari Kiri.\n");
	printf("2. Tampilkan dari kanan.\n");
	printf("99. Kembali.\n");
	scanf("%d", &pilih);
	pilihMenuTampilkanHuruf(pilih, L);
}

void pilihMenuTampilkanHuruf(int pilih, list *L) {
	switch(pilih) {
		case 1:
			printf("\n");
			printHurufFirst(*L);
			break;
		case 2: 
			printf("\n");
			printHurufLast(*L);
			break;
		case 99: 
			tampilkanMenuUtama(L);
			break;
		default:
			printf("Pilihan tidak valid\n");
			tampilkanMenuTampilkanHuruf(L);
	}
	
	printf("\n");
	system("pause");
	tampilkanMenuUtama(L);
}

char inputHuruf() {
	char huruf;
	printf("Masukan huruf : ");
	scanf(" %c", &huruf);
	
	return huruf;
}

almtelmt Search(char huruf, list L) {
	element *P;
	P = first(L);
	
	while(huruf != huruf(*P)) {
		P = next(*P);
	}
	
	return (P);
}
