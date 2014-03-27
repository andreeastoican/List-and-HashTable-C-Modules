/* Stoican Elena-Andreea */

typedef struct ht {
	List** buckets;
	unsigned int size;
	unsigned int element_size;
	unsigned int current_bucket;
	List* current_element;
} HashTable;

HashTable* createHashtable (int size);
void addElementToHashtabel (HashTable* hashtable, void* element, unsigned int element_size);
void removeElementFromHashtable (HashTable* hashtable, void* element, unsigned int element_size);
int findElementInHashtable (HashTable* hashtable, void* element, unsigned int element_size);
void clearHshtable (HashTable* hashtable);
void* nextHashTableElement(HashTable* hashTable);