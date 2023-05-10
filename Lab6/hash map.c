#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long hash_function(char *str){
	unsigned long i =0;
	for(int j=0; str[j];j++){
		i+=str[j];
		return i % CAPACITY;
	}
	typedef struct Ht_item Ht_item;

	struct Ht_item{
		char *key;
		char *value;
	};
typedef struct HashTable HashTable;

struct HashTable{
	Ht_item **items;
	int size;
	int count;
};
// create item function
Ht_item *create_item(char *key, char *value){
	Ht_item *item = (Ht_item*) malloc (sizeof(Ht_item));
	item ->key = (char*) malloc (strlen(key)+1);
	item ->value =(char *) malloc (strlen(value)+1);
	strcpy (item ->key, key);
	strcpy (item -> value, value);

	return item;
}

// create create_table function
