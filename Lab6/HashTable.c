#include<stdlib.h> 
#include<stdio.h> 
#include<string.h> 
#include<stdint.h>
#include<stdbool.h>

#define MAX_VALUE 256
#define TABLE_SIZE 10
#define DELETED_NODE (key*)(0XFFFFFFFFFFFFFFFFUL)

typedef struct {
	char value[MAX_VALUE];
	int type; 
	//.......other stuff if you want 
} key; 

key * hash_table[TABLE_SIZE];

unsigned int hash(char *value) {
	int length = strnlen(value, MAX_VALUE);
	unsigned int hash_value = 0; 
	for (int i=0; i < length; i++) {
		hash_value += value [i];
		hash_value = (hash_value * value[i]) % TABLE_SIZE; 

}
	return hash_value;
}

void init_hash_table(){
	for (int i = 0; i < TABLE_SIZE; i++) {
		hash_table[i] = NULL; 
	}
}

void print_table() {
	printf("Start\n");
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hash_table[i] == NULL) {
			printf("\t%i\tnull\n",i);
		} else if (hash_table[i] == DELETED_NODE) {
			printf("\t%i\t<deleted>\n",i);
		} else {

			printf("\t%i\t%s\n", i, hash_table[i]->value);
		}
	}
	printf("End\n");
}


bool hash_table_insert(key *p) {
	if (p == NULL) return false; 
	int index = hash(p->value); 
	for (int i=0; i < TABLE_SIZE; i++){
		int try = (i + index) % TABLE_SIZE; 
		if (hash_table[try] == NULL ||
			hash_table[try] == DELETED_NODE){
			hash_table[try] = p;
			return true; 
		}

	}
	return false; 
}

//find a person in the table by their name 
key *hash_table_lookup (char *value) {
	int index = hash(value); 
	for (int i=0; i < TABLE_SIZE; i++){
	int try = (index + i) % TABLE_SIZE;
	if (hash_table[try] == NULL) {
		return false; //not here 
	}
	if (hash_table[try] == DELETED_NODE) continue; 
	
	if (strncmp(hash_table[try]->value, value, TABLE_SIZE)== 0) { 
			return hash_table[try];
		}
	}
	return NULL; 
}




//MAKE A DELETE FUNCTION

key *hash_table_delete(char *value) {
	int index = hash(value); 
	for (int i=0; i < TABLE_SIZE; i++){
		int try = (index + i) % TABLE_SIZE; 
		if (hash_table[try] == NULL) return NULL; 
		if (hash_table[try] == DELETED_NODE) continue; 
		if (strncmp(hash_table[try]->value, value, TABLE_SIZE)== 0) {  
				

				key* tmp = hash_table[try];  
				hash_table[try] = DELETED_NODE;  
				return tmp;
		}
	}
	return NULL; 
}

void *free_item(char *value) {
    free(value->key);
    free(item->value);
    free(item);
}

void *free_table(char *value) {
    for (int i=0; i<table->size; i++) {
        *value item = table->items[i];
        if (item != NULL)
            free_item(item);
    }

    free_overflow(table);
    free(table->items);
    free(table);
}


int main() {

	init_hash_table();
	print_table();
	

	//making some people for bool
	key one = {.value="null", .type=256};
	key two = {.value="null", .type=27};
	key three = {.value="null", .type=14};	
	key four = {.value="null", .type=54};
	key five = {.value="null", .type=15};
	key six = {.value="null", .type=25};
	key seven = {.value="null", .type=34};
	key eight = {.value="null", .type=1};
	key nine = {.value="null", .type=75};


	//add them to the hash table 
	hash_table_insert(&one);
	hash_table_insert(&two);
	hash_table_insert(&three);
	hash_table_insert(&four);
	hash_table_insert(&five);
	hash_table_insert(&six);
	hash_table_insert(&seven);
	hash_table_insert(&eight);
	hash_table_insert(&nine);
	
	

	//print our status of the table
	print_table();

	key *tmp = hash_table_lookup("nine"); 
	if (tmp == NULL) {
		printf("Not Found!\n");
	}else {
		printf("Found %s.\n", tmp->value); 
	}
//Name thats not in there to see if it works
	tmp = hash_table_lookup("eightyeight"); 
	if (tmp == NULL) {
		printf("Not Found!\n");
	} else { 
		printf("Found %s.\n", tmp->value); 
	}

//to make sure it works we are going to delete one-> not found
	hash_table_delete("one"); 
	tmp = hash_table_lookup("one"); 
	if (tmp == NULL) {
		printf("Not Found!\n");
	}else {
		printf("Found %s.\n", tmp->value); 
	}

	print_table(); 
	
	
	free_item("three");
    tmp = hash_table_lookup("three");
    if (tmp == NULL) {
        printf("Item freed\n");
    }else {
        printf("Item does not exist\n");
    }
    
    free_table("three");
    tmp = hash_table_lookup("three");
    if (tmp == NULL) {
        printf("Item freed\n");
    }else {
        printf("Item does not exist\n");
    }
    return 0;
}
	