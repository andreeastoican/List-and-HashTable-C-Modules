
#include "hash.h"

/**
 * Functie de hash bazata pe djb2 a lui Dan Bernstein
 * http://www.cse.yorku.ca/~oz/hash.html
 * @return valoarea de dispersie (cheia)
 */
unsigned int hash(const void *element, unsigned int element_size, unsigned int hash_length)
{
	unsigned int hash = 5381;
	int c;
	unsigned int i;
	unsigned char* elementP = element;

	for (i = 0; i < element_size; i++) {
		c = *elementP++;
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return (hash % hash_length);
}