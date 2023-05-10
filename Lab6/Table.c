#include <stdio.h>
#include <stdlib.h>
#include <strings.h> 


typedef struct { 
//Define key and value as char datatype
    char* key; 
    char* value; 
} Element;

// Define HashTable Structure
typedef struct {
    //Array of pointer
    Element** entries; 
    //variable for size of table 
    int size; 
    // count number of elements 
    int count; 
}Ht; 


//create key value pairs 
Element* Create_Entry(char *key, char *value) { 
    // allocate memory for hashtable
    Element* pair = (Element*) malloc(sizeof(Element)); 
    /* Allocate memory for components */ 
    pair->key = (char*) malloc(strlen(key) + 1);
    pair->value = (char*) malloc(strlen(value) + 1);
    //copy key and value in place
    strcpy(pair->key, key);
    strcpy(pair->value, value); 
    return pair; 
}



// Function to create HashTable
Ht* Create_Hash_Table(int size) {
    // Impliment struc with the pointer  
    Ht* theTable = (Ht*) malloc (sizeof(Ht));
    //set size of the table to size passed 
    theTable->size = size;
    // set the count of the table to 0 when there are no elements 
    theTable->count = 0;
    
    theTable->entries = (Element**) calloc(theTable->size, sizeof(Element*));  
    // set pointer to Null
    for(int i = 0; i < theTable->size; i++) {
        theTable->entries[i] = NULL; 
    }
    //return table
    return theTable; 
}



//Create function to free up memory
void freeMemoryItem(Element* item) { 
    // Free both  key and value  
    free(item->key);
    free(item->value);
    // Free the object 
    free(item);
}



//Create function to free up memory of HashTable 
void freeMemoryTable(Ht* table) { /* 1 Allocation per item, 1 per itemArray, 1 per hash table */ 
    for(int i = 0; i < table->size; i++) {

       // get items from array
        Element* freeItem = table->entries[i];
        //free item
        freeMemoryItem(freeItem);
    }
    //free deleted entries
    free(table->entries);
    free(table); 
}



//Define HashFunction to get the index
int KeyFunction(char* key, int size) {
    unsigned long i = 0;
    for (int j=0; key[j]; j++)
        i += key[j];
    return i % size;
}



//Define an Insert function 
void InsertIndex(Ht *table, Element *itemToInsert) {
    // get index
    int map = KeyFunction(itemToInsert->key, table->size);
    printf("key = %s \t key location = %d \t Value Inserted: %s \n", itemToInsert->key, map, itemToInsert->value); 
   // get current entry at a certain index
    Element* currentItem = table->entries[map];
    // if the current entry points to nothing print it is full 
    if(currentItem == NULL) {
        if(table->count == table->size) { //checks if occupied 
            printf("Hash Table is Full \n");
            freeMemoryItem(itemToInsert);
            return; 
        }
        //acess interal array that was stores in map into itemToInsert 
    table->entries[map] = itemToInsert;
    table->count++; //increase counter by one 
    }
    else {
        //If keys are the same replace the values insert it into index 
        if(strcmp(currentItem->key, itemToInsert->key) == 0) { 
            strcpy(table->entries[map]->value, itemToInsert->value); 
        }
        else {// If it is occupied collision 
            printf("Collision Occurred \n");
            return; 
        } 
    } 


}
// Function that display Search Results  
void HashLookUp(char* keyValue) {
    //If key in the HashTable is not empty print else print key DNE
    if(keyValue != NULL) { 
        printf("The key exists and it's value is: %s \n", keyValue);
    }
    else {
        printf("The key does not exist. \n");
    } 

} 


//Define a search function 
char* Hash_Table_Lookup(Ht *table, char* key) {
    // Get what key is and acess hashtable and acess size 
    int map = KeyFunction(key, table->size);
    // Obtain the pointer this would point to if it was present 
    // stores it at the location map
    Element* itemToIdentify = table->entries[map];
    // If HashTable is not empty -> Print the value and display the result 
    if(itemToIdentify != NULL) {
        HashLookUp(itemToIdentify->value); 
        return itemToIdentify->value;
    }
    // If HashTable is empty, then no value is stored at this key location 
    HashLookUp(NULL); 
    return NULL; 
} 


//Define a delete function
void hash_table_delete(Ht *table, Element *itemToRemove) {
    int map = KeyFunction(itemToRemove->key, table->size);
    // acess internal array using table -> entries 
    Element* currentItem = table->entries[map];
    // Want location to be Null indicating that location is empty 
    if(currentItem != NULL) {
       table -> entries[map] =NULL;
        table->count--;
        printf("Item removed from table. \n"); 
    }
    else {
        printf("Not found, no items removed. \n");
    } 
} 




//Define a function to display a HashTable
void displayHashTable(Ht *table) {    
    for(int i = 0; i < table->size; i++) {
        if(table->entries[i] != 0) {
        printf("Key: %s  \t Index: %d \t Value: %s \n", table->entries[i]->value, i, table->entries[i]->key);
        }
    }
} 


int main() {
    Element *item1 = Create_Entry("LISA", "1");
    Element *item2 = Create_Entry("CHRIS", "2");
    Element *item3 = Create_Entry("MAGGIE", "3");
    Element *item4 = Create_Entry("MARGE", "4"); 
    Ht* table = Create_Hash_Table(69);
    InsertIndex(table, item1); 
    InsertIndex(table, item2);
    InsertIndex(table, item3);
    InsertIndex(table, item4);
    hash_table_delete(table, item3);
    hash_table_delete(table, item3);
    Hash_Table_Lookup(table, "Homer"); 
    displayHashTable(table); 

    return 0; 
}  



