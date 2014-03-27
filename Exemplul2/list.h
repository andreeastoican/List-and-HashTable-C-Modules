/* Stoican Elena-Andreea */

typedef struct lista {
	void *value;
	struct lista *next;
} List;

List* create_list (void* value);
void add_to_list (List* list, void* value);
void delete_from_list (List** list, void* value);
int exists_in_list (List* list, void* value);