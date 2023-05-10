#include <stdio.h>
#include <stdlib.h>
#include <strings.h> 

typedef struct { /* Structure of key value pairs */ 
    char* key; 
    char* value; 
} item; /* Every key value pair is an item */ 

typedef struct {
    item** itemArray; /* Array of pointers */ 
    int size; /* Size of table */ 
    int count; /* Number of elements */ 
} hashTable; 

item* createItem(char *key, char *value) { /* Create an item (key-value pair) */
    /* Allocate memory for pair */
    item* pair = (item*) malloc(sizeof(item)); 
    /* Allocate memory for components */ 
    pair->key = (char*) malloc(strlen(key) + 1);
    pair->value = (char*) malloc(strlen(value) + 1);
    /* Assign components */
    strcpy(pair->key, key);
    strcpy(pair->value, value); 
    return pair; /* Return pair */
}

hashTable* createTable(int size) {
    /* Implement the struct with the size of pointer*hashTable */ 
    hashTable* theTable = (hashTable*) malloc (sizeof(hashTable));
    /* Set size of talbe = size passed */ 
    theTable->size = size;
    /* Set count of table = 0 -> No elements */ 
    theTable->count = 0;
    /* Allocate itemArray (Array of pointers to each pair) */
    /* Calloc() */
        /* calloc([size] #Blocks each, with [sizeof(item*)] Bytes) */
    theTable->itemArray = (item**) calloc(theTable->size, sizeof(item*));  
    /* Set each pointer to NULL */ 
    for(int i = 0; i < theTable->size; i++) {
        theTable->itemArray[i] = NULL; 
    }
    /* Return the table */ 
    return theTable; 
}

/* Free memory of an item */ 
void freeMemoryItem(item* item) { /* 3 Allocations were made */ 
    /* Free both components */
    free(item->key);
    free(item->value);
    /* Free the object */ 
    free(item);
}

/* Free memory of a hash table: */ 
void freeMemoryTable(hashTable* table) { /* 1 Allocation per item, 1 per itemArray, 1 per hash table */ 
    for(int i = 0; i < table->size; i++) {

        /* Obtain item from itemArray */ 
        item* freeItem = table->itemArray[i];
        /* Free item */ 
        freeMemoryItem(freeItem);
    }
    free(table->itemArray);
    free(table); 
}

/* Hash Function */ /* Am I allowed to pass the size? */ 
int obtainIndexGivenKeyFunction(char* key, int size) {
    unsigned long i = 0;
    for (int j=0; key[j]; j++)
        i += key[j];
    return i % size;
}


void insertItem(hashTable *table, item *itemToInsert) {
    /* Obtain the index */ 
    int map = obtainIndexGivenKeyFunction(itemToInsert->key, table->size);
    printf("key = %s \t location of key = %d \t value to insert: %s \n", itemToInsert->key, map, itemToInsert->value); 
    /* Obtain the current item at this index */ 
    item* currentItem = table->itemArray[map];
    /* If this currentItem points to nothing */ 
    if(currentItem == NULL) {
        if(table->count == table->size) {
            printf("Hash Table is Full \n");
            freeMemoryItem(itemToInsert);
            return; 
        }
    table->itemArray[map] = itemToInsert;
    table->count++; 
    }
    else {
        if(strcmp(currentItem->key, itemToInsert->key) == 0) { /* The keys are the same */ 
            strcpy(table->itemArray[map]->value, itemToInsert->value); /* Replace value */ 
        }
        else {
            printf("Collision Occurred \n");
            return; 
        } 
    } 


} 

void deleteItem(hashTable *table, item *itemToRemove) {
    int map = obtainIndexGivenKeyFunction(itemToRemove->key, table->size);
    item* currentItem = table->itemArray[map];
    if(currentItem != NULL) {
        currentItem = NULL;
        table->count--;
        printf("Item successfully removed from table. \n"); 
    }
    else {
        printf("Item not found, no item removed. \n");
    } 
} 


/* Prints out the search result */ 
void displaySearchResult(char* keyValue) {
    if(keyValue != NULL) { 
        printf("The key exists and it's value is: %s \n", keyValue);
    }
    else {
        printf("The key does not exist. \n");
    } 

} 

/* Searches table to see if key is present */
char* search(hashTable *table, char* key) {
    /* Obtain what this key would map to if it was present */ 
    int map = obtainIndexGivenKeyFunction(key, table->size);
    /* Obtain the pointer this would point to if it was present */ 
    item* itemToIdentify = table->itemArray[map];
    /* If not NULL -> Print resutn the value and display the result */ 
    if(itemToIdentify != NULL) {
        displaySearchResult(itemToIdentify->value); 
        return itemToIdentify->value;
    }
    /* If NULL, then no value is stored at this key location */ 
    displaySearchResult(NULL); 
    return NULL; 
} 


void displayHashTable(hashTable *table) {    
    for(int i = 0; i < table->size; i++) {
        if(table->itemArray[i] != 0) {
        printf("____________________________________________________\n"); 
        printf("Key: %s  \t Mapped Index: %d \t Value: %s \n", table->itemArray[i]->value, i, table->itemArray[i]->key);
        }

    }
        printf("____________________________________________________\n"); 

} 






int main() {
    item *item1 = createItem("a", "4");
    item *item2 = createItem("b", "8");
    item *item3 = createItem("c", "16");
    item *item4 = createItem("d", "32"); 
    hashTable* table = createTable(200);
    insertItem(table, item1); 
    insertItem(table, item2);
    insertItem(table, item3);
    insertItem(table, item4);
	


    search(table, "Hello World"); 

    displayHashTable(table); 

     

    return 0; 
}  



