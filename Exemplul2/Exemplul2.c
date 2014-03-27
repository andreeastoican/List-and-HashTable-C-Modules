/*
	Stoican Elena-Andreea
	HashTable

	Exemplul 2 - Crearea unui HashTable de siruri de caractere
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#include "hashtable.h"

int main (int argc, char *argv[]) {

	int hashtable_size, i;
	char value[20];
	char* element;
	HashTable *hashTable;

	hashtable_size = 10;
	hashTable = createHashtable(10);

	for (i = 0; i < 20; i++) {
		sprintf(value, "string%i", i);
		addElementToHashtabel(hashTable, value, strlen(value));
	}

	while (1) {
		element = nextHashTableElement(hashTable);
		if (element == NULL) {
			break;
		}
		printf("%s\n", (char*)element);
	}

	if (findElementInHashtable(hashTable, value, strlen(value)) == 1) {
		printf("Elementul %s se afla in hashTable.\n", value);
	} else {
		printf("Elementul %s nu se afla in hashTable.\n", value);
	}

	return 0;
}