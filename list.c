/* Stoican Elena-Andreea */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* functie ce returneaza o lista cu un singur element,
care contine valoarea data ca parametru */
List* create_list (void* value) {
	List* list = malloc(sizeof(List));
	list->value = malloc(sizeof(void) * (strlen(value) + 1));
	strcpy(list->value, value);
	list->next = NULL;
	return list;
}

/* functie ce adauga valoarea value in lista list */
void add_to_list (List* list, void* value) {
	List* new_list;
	List *l;
	l = list;

	new_list = create_list(value);
	while(list->next != NULL) {
		list = list->next;
	}

	list->next = new_list;
}

/* functie ce sterge valoarea value din lista list daca valoarea exista */
void delete_from_list (List** list, void* value) {
	List* l = *list;
	List* l2;

	if (l == NULL) {
		return;
	}

	// daca valoarea e pe prima pozitie din lista
	if (strcmp(l->value, value) == 0) {
		*list = l->next;
		free(l);
		return;
	}

	// se parcurg elementele din lista
	while (l->next != NULL) {

		// daca valoarea exista se va sterge
		if (strcmp(l->next->value, value) == 0) {
			l2 = l->next;
			l->next = l->next->next;

			// se elibereaza spatiul ocupat
			free(l2);

			return;
		}

		l = l->next;
	}
}

/* functie ce intoarce 1 daca valoarea value se gaseste in list si 0 altfel */
int exists_in_list (List* list, void* value) {

	while (list != NULL) {
		if (strcmp(list->value, value) == 0) {
			return 1;
		}
		list = list->next;
	}

	return 0;
}