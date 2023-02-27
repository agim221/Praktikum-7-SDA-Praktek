#include "list.c"

int main() {
	list L;
	createList(&L);
	
	printHurufFirst(L);
	tampilkanMenuUtama(&L);
	
	return 0;
}
