/* Stoican Elena-Andreea */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"
#include "hash.h"
#include "hashtable.h"

/* functie ce returneaza un hashtable de dimensiune size */
HashTable* createHashtable (int size) {
	HashTable* hashtable = malloc(sizeof(HashTable));
	hashtable->buckets = calloc(sizeof(List*), size);
	hashtable->size = size;

	hashtable->current_bucket = -1;
	hashtable->current_element = NULL;

	return hashtable;
}

/* functie ce adauga un element in hashtable-ul dat ca parametru */
void addElementToHashtabel (HashTable* hashtable, void* element, unsigned int element_size) {
	unsigned int hash_value;
	List* list;

	// se calculeaza valoarea de hash a elementului
	// pentru a se determina bucket-ul in care va fi adaugat
	hash_value = hash(element, element_size, element_size);
	list = hashtable->buckets[hash_value];

	if (list == NULL) {
		hashtable->buckets[hash_value] = create_list(element);
	} else {
		add_to_list(list, element);
	}
}

/* functie ce sterge elementul element din hashtable-ul dat ca parametru */
void removeElementFromHashtable (HashTable* hashtable, void* element, unsigned int element_size) {
	unsigned int hash_value;

	// se determina index-ul bucket-ul in care se afla elementul de sters
	hash_value = hash(element, element_size, hashtable->size);

	delete_from_list(&hashtable->buckets[hash_value], element);
}

/* functie ce returneaza 1 daca element se afla
in hashtable-ul dat ca parametru si 0 altfel */
int findElementInHashtable (HashTable* hashtable, void* element, unsigned int element_size) {
	unsigned int hash_value;
	List* list;

	// se determina bucket-ul in care se afla elementul
	hash_value = hash(element, element_size, hashtable->size);
	list = hashtable->buckets[hash_value];

	return exists_in_list(list, element);
}

/* functie ce goleste fiecare bucket din hashtable-ul dat ca parametru */
void clearHshtable (HashTable* hashtable) {
	unsigned int i;
	List *list, *l;

	for (i = 0; i < hashtable->size; i++) {
			if (hashtable->buckets[i] != NULL) {
				list = hashtable->buckets[i];
				while (list != NULL) {
					l = list->next;
					free(list->value);
					free(list);
					list = l;
				}
				hashtable->buckets[i] = NULL;
			}
	}
}

/* functie ce returneaza urmatoarea valoare din hashTable */
void* nextHashTableElement(HashTable* hashTable) {
	unsigned int i;

	int current_bucket = hashTable->current_bucket;
	List* current_element = hashTable->current_element;

	if (current_element == NULL) {
		for (i = current_bucket + 1; i < hashTable->size; i++) {
			if (hashTable->buckets[i] != NULL) {
				hashTable->current_bucket = i;
				hashTable->current_element = hashTable->buckets[i]->next;
				return hashTable->buckets[i]->value;
			}
		}
	} else {
		hashTable->current_element = current_element->next;
		return current_element->value;
	}

	return NULL;
}