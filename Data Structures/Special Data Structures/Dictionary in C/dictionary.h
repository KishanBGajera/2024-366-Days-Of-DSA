#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>

struct Entry{
    int key;
    int value;
    struct Entry* next; // For chaining
};

typedef struct Entry Entry;

Entry* getEntry(int key, int value){
    Entry* entry = (Entry*)malloc(sizeof(Entry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

void printEntry(Entry* entry){
    printf("Entry[%d]: %d\n", entry->key, entry->value);
}

struct Dictionary
{
    int totalEntries;
    int maxEntries;
    Entry **entries;
};

typedef struct Dictionary Dictionary;

Dictionary* getDictionary(int maxEntries){
    Dictionary* dictionary = (Dictionary*)malloc(sizeof(Dictionary));
    dictionary->maxEntries = maxEntries;
    dictionary->totalEntries = 0;
    dictionary->entries = (Entry**)malloc(sizeof(Entry*) * maxEntries);

    for (int i = 0; i < maxEntries; i++) {
        dictionary->entries[i] = NULL;
    }
    return dictionary;
}

int hash(Dictionary* dict, int key){
    return key % dict->maxEntries;
}

void addDictEntry(Dictionary* dict, int key, int value){
    int index = hash(dict, key);
    Entry *current = dict->entries[index];
    
    while (current != NULL) {
        if (current->key == key) {
            printf("Error: Duplicate key %d\n", key);
            return;
        }
        current = current->next;
    }

    Entry *newEntry = getEntry(key, value);
    newEntry->next = dict->entries[index];
    dict->entries[index] = newEntry;
    dict->totalEntries++;
}

void removeEntry(Dictionary* dict, int key) {
    int index = hash(dict, key);
    Entry *current = dict->entries[index];
    Entry *prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                dict->entries[index] = current->next;
            }
            free(current);
            dict->totalEntries--;
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Entry with key %d not found\n", key);
}


int getValue(Dictionary* dict, int key){
    int index = hash(dict, key);
    Entry *target = dict->entries[index];

    while (target != NULL) {
        if (target->key == key) {
            return target->value;
        }
        target = target->next;
    }

    return -1;
}

void printDictionary(Dictionary* dict){
    printf("Dict {\n");
    for (int i = 0; i < dict->maxEntries; i++) {
        Entry *current = dict->entries[i];
        while (current != NULL) {
            printf("\t");
            printEntry(current);
            current = current->next;
        }
    }
    printf("}\n");
}

#endif
