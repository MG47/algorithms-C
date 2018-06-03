/*
* Hash Table - Linear Probing
* INCOMPLETE
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct entry {
	char *key;
	char *data;
};

struct hash_table {
	struct entry *ent;
	int size;
};

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
	int index, size, i = 0;
	size = ht->size;

	if (!ht)
		return -1;

	index = hash_function(key, size);

	while (i < ht->size) {
		if (!(ht->ent[index].key)) {
			ht->ent[index].key = malloc(sizeof(char) * strlen(key));
			strcpy(ht->ent[index].key, key);
			ht->ent[index].data = malloc(sizeof(char) * strlen(data));;
			strcpy(ht->ent[index].data, data);
			return index;
		} else {
			index++;
			index %= ht->size;
			i++;
		}
	}
	return -1;
}
 
int remove_data(struct hash_table *ht, char * key)
{
	int index, size, i = 0;
	size = ht->size;

	if (!ht)
		return -1;

	index = hash_function(key, size);

	while (i < ht->size) {
		if (!strcmp(key,ht->ent[index].key)) {
			free(ht->ent[index].key);
			ht->ent[index].key = NULL;
			free(ht->ent[index].data);
			ht->ent[index].data = NULL;
			return 0;
		}
		index++;
		index %= ht->size;
		i++;
	}

	return -1;
}

char *search(struct hash_table *ht, char *key)
{
	int index, size, i = 0;
	char *data = NULL;

	if (!ht)
		return NULL;

	size = ht->size;
	index = hash_function(key, size);

	while (i < ht->size) {
		if (!strcmp(key,ht->ent[index].key)) {
			data = malloc(sizeof(char) * strlen(ht->ent[index].data));
			strcpy(data, ht->ent[index].data);
			return data;
		}
		index++;
		index %= ht->size;
		i++;
	}

	return data;
}

struct hash_table *init_table(struct hash_table **ht, int size)
{
	*ht = malloc(sizeof(struct hash_table));
	if (!ht)
		exit(EXIT_FAILURE);

	(*ht)->size = size;
	(*ht)->ent = malloc(sizeof(struct entry) * size);
	if (!((*ht)->ent))
		exit(EXIT_FAILURE);
	return 0;
}

int delete_table(struct hash_table **ht)
{
	if (!ht)
		return -1;

	int i;

	//incomplete
	while (i < (*ht)->size) {
		free((*ht)->ent[i].key);
		free((*ht)->ent[i].data);
	}
	free((*ht)->ent);
	free(*ht); 
	*ht = NULL;
	return 0;
}

void print_table(struct hash_table *ht)
{
	int i = 0;

	if (!ht) {
		printf("Table does not exist\n");
		return;
	}

	while (i < ht->size) {
		if (ht->ent[i].key) {
			printf("Key:%s\t", ht->ent[i].key);
			printf("data:%s\n", ht->ent[i].data);
		} else {
			printf("Key: (empty), data: (empty)\n");
		}
		i++;
	}
}

int main()
{
	printf("\nHash Table - Linear Probing\n\n");

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
			printf("Enter the size of the table ");
			scanf("%d", &val);
			init_table(&ht, val);
			break;
		case 2:
			printf("Enter key to be inserted: ");
			scanf("%s", key);
			printf("Enter data to be inserted: ");
			scanf("%s", data);
			if (ht) {
				if ((insert_data(ht, key, data) == -1))
					printf("No space left in hash table!\n");
			}
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





