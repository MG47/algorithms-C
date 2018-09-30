/*
* Hash Table - Separate Chaining
* INCOMPLETE
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct entry {
	char *key;
	char *data;
	struct entry *next;
};

struct hash_table {
	// Array of linked lists
	struct entry **head;
	int size;
};

struct entry *create_list_node(char *key, char *data)
{
	struct entry *new;
	int len;

	new = malloc(sizeof(struct entry));
	if (!new)
		return NULL;

	len = strlen(key);
	new->key = malloc(sizeof(char) * len);
	if (!new->key)
		exit(EXIT_FAILURE);

	len = strlen(data);
	new->data = malloc(sizeof(char) * len);
	if (!new->data)
		exit(EXIT_FAILURE);

	strcpy(new->key, key);
	strcpy(new->data, data);
	new->next = NULL;
	return new;
}

void remove_list_node(struct entry **node)
{
	if (!node)
		return;
	free((*node)->key);
	free((*node)->data);
	free(*node);
	*node = NULL;
}

/* K & R hash function */
int hash_function(char *key, int size)
{
	unsigned int hashval;
	for (hashval = 0; *key != '\0'; key++)
		hashval = *key + 31 * hashval;
	return hashval % size;
}

int insert_data(struct hash_table *ht, char *key, char *data)
{
	int index;
	struct entry *new_ent;

	if (!ht)
		return -1;

	index = hash_function(key, ht->size);

	new_ent = create_list_node(key, data);
	if (!(ht->head[index])) {
		ht->head[index] = new_ent;
	} else {
		struct entry *cur;
		cur = ht->head[index];
		while (cur->next != NULL) 
			cur = cur->next;
		cur->next = new_ent;
	}
	return index;
}
 
int remove_data(struct hash_table *ht, char *key)
{
	return 0;
	// TODO
#if 0
	int index;
	struct entry *cur;

	if (!ht)
		return -1;

	index = hash_function(key, ht->size);

	cur = ht->head[index];
	while (!cur) {
		if (!strcmp(key, ht->head[index]->key)) {
			remove_list_node(&ht->head[index]);
			return 0;
		}
		cur = cur->next;
	}
	return 0;
#endif
}

char *search(struct hash_table *ht, char *key)
{
	int index, size;
	char *data = NULL;
	struct entry *cur;

	if (!ht)
		return NULL;

	size = ht->size;
	index = hash_function(key, size);

	cur = ht->head[index];
	while (cur) {
		if (!strcmp(key, cur->key)) {
			data = malloc(sizeof(char) * strlen(cur->data));
			strcpy(data, cur->data);
			return data;
		}
		cur = cur->next;
	}
	return data;
}

struct hash_table *init_table(int size)
{
	struct hash_table
	*ht = malloc(sizeof(struct hash_table));
	if (!ht)
		exit(EXIT_FAILURE);

	ht->size = size;
	ht->head = malloc(sizeof(struct entry *) * size);
	if (!(ht->head))
		exit(EXIT_FAILURE);
	return ht;
}

int delete_table(struct hash_table **ht)
{
	int i;
	struct entry *cur;
	if (!ht)
		return 0;

	i = 0;
	while (i < (*ht)->size)	{
		cur = (*ht)->head[i];
		if (cur)
			remove_list_node(&cur);
		i++;
	}
	*ht = NULL;
	return 0;
}

void print_table(struct hash_table *ht)
{
	int i = 0;
	struct entry *cur;

	if (!ht) {
		printf("Table does not exist\n");
		return;
	}

	while (i < ht->size) {
		cur = ht->head[i];
		printf("Index %d: ", i);
		while (cur) {
			printf("Key:%s::", cur->key);
			printf("data:%s--->", cur->data);
			cur = cur->next;
		}
		printf("\n");
		i++;
	}
}

int main()
{
	printf("\nHash Table - Separate Chaining\n\n");

	int option;

	struct hash_table *ht = NULL;
	while (1) {
		printf("\nEnter the option number:\n");
		printf("1. Create a hash table \n");
		printf("2. Insert data \n");
		printf("3. Remove data \n");
		printf("4. Search data\n");
		printf("5. Delete hash table \n");
		printf("6. Print Table\n");
		printf("7. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int val;
		char key[50], data[50];


		switch (option) {
		case 1:
			if (ht) {
				printf("Hash table already exists\n");
				continue;
			}
			printf("Enter the size of the table");
			scanf("%d", &val);
			ht = init_table(val);
			break;
		case 2:
			printf("Enter key to be inserted: ");
			scanf("%s", key);
			printf("Enter data to be inserted: ");
			scanf("%s", data);
			insert_data(ht, key, data);
			break;
		case 3:
			printf("Enter key to be removed: ");
			scanf("%s", key);
			remove_data(ht, key);
			break;
		case 4:
			printf("Enter key to search:");
			scanf(" %s", key);
			char *find = search(ht, key);
			if (find)
				printf("Data found: %s\n", find);
			break;
		case 5:
			delete_table(&ht);
			break;
		case 6:
			print_table(ht);
			break;
		case 7:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid Option\n");
		}
	}
	return 0;
}

