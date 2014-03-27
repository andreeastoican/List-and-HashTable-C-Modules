/*
	Stoican Elena-Andreea
	HashTable

	Exemplul 1 - Crearea unui HashTable de int-uri
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#include "hashtable.h"

int main (int argc, char *argv[]) {

	int hashtable_size, value, i;
	int* element;
	HashTable *hashTable;

	hashtable_size = 10;
	hashTable = createHashtable(10);

	for (i = 0; i < 20; i++) {
		value = rand()%100;
		addElementToHashtabel(hashTable, &value, sizeof(int));
	}

	while (1) {
		element = nextHashTableElement(hashTable);
		if (element == NULL) {
			break;
		}
		printf("%i\n", *(int*)element);
	}

	return 0;
}