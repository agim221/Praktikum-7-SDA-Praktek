#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>

#define first(L) (L).first
#define last(L) (L).last
#define next(L) (L).next
#define prev(L) (L).prev
#define huruf(L) (L).huruf

typedef struct almt *almtelmt;
typedef struct almt {
	char huruf;
	almtelmt next;
	almtelmt prev;
} element;

typedef struct {
	element *first;
	element *last;
} list;

//set first and last to NULL
void createList(list *L);

//add node
void addFirst(char huruf, list *L);
void addAfter(element *prev, char huruf, list *L);
void addLast(char huruf, list *L);

//delete node
void delFirst(list *L);
void delAfter(element *prev, list *L);
void delLast(list *L);

//print all node
void printHurufFirst(list L);
void printHurufLast(list  L);

void tampilkanMenuUtama(list *L);
void pilihMenuUtama(int pilih, list *L);

void tampilkanMenuTambahkanHuruf(list *L);
void pilihMenuTambahkanHuruf(int pilih, list *L);

void tampilkanMenuTampilkanHuruf(list *L);
void pilihMenuTampilkanHuruf(int pilih, list *L);

void tampilkanMenuHapusHuruf(list *L);
void pilihMenuHapusHuruf(int pilih, list *L);

almtelmt Search(char huruf, list L);

char inputHuruf();
