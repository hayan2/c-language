#define _CRT_SECURE_NO_WARNINGS
#define MAX_LOAD_FACTOR 0.5
#define INITIAL_CAPACITY 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum State {
	EMPTY,
	USED,
	DELETED
}State;

typedef struct Item {
	char* key;
	int value;
}Item;

Item* generateItem(char* key, int value) {
	Item* newItem = (Item*)malloc(sizeof(Item));
	newItem->key = _strdup(key);
	newItem->value = value;

	return newItem;
}

typedef struct Node {
	Item* data;
	unsigned int hashValue;
	State state;
}Node;

typedef struct Hash {
	Node* bucket;
	int size;
	int capacity;
}Hash;

void initialize(Hash* hash) {
	hash->bucket = NULL;
	hash->size = 0;
	hash->capacity = 0;	
}

static unsigned int hashing(unsigned char* str) {
	unsigned int hash = 5381;

	while (*str != '\0') {
		hash = hash * 33 + *str;
		++str;
	}

	return hash;
}

static void reAllocate(Hash* hash, int size) {
	int previousCapacity = hash->capacity;

	if (size == 0) {
		hash->capacity = INITIAL_CAPACITY;
	}
	else {
		hash->capacity = getNextPrime(size);
	}

	Node* newBucket = (Node*)malloc(hash->capacity * sizeof(Node));
	for (int i = 0; i < hash->capacity; i++) {
		newBucket[i].state = EMPTY;
	}

	for (int i = 0; i < previousCapacity; i++) {
		if (hash->bucket[i].state != USED) {
			continue;
		}
		unsigned int idx = hash->bucket[i].hashValue;

		while (newBucket[idx % hash->capacity].state == USED) {
			if (strcmp(newBucket[idx % hash->capacity].data->key, hash->bucket[i].data->key) == 0) {
				return;
			}
			idx++;
		}

		newBucket[idx % hash->capacity] = (Node){ hash->bucket[i].data, hash->bucket[i].hashValue, USED };
	}
	free(hash->bucket);
	hash->bucket = newBucket;
}

void insert(Hash* hash, Item* data) {	
	if (hash->capacity == 0 || (double)hash->size / hash->capacity > MAX_LOAD_FACTOR) {		
		reAllocate(hash, hash->capacity * 2);
	}	

	unsigned int hashValue = hashing((unsigned char*)data->key);
	unsigned int idx = hashValue;

	while (hash->bucket[idx % hash->capacity].state == USED) {
		if (strcmp(hash->bucket[idx % hash->capacity].data->key, data->key) == 0) {
			return;
		}
		++idx;
	}

	hash->bucket[idx % hash->capacity] = (Node){ data, hashValue, USED };
	++hash->size;
}

static int findIndex(Hash* hash, char* key) {
	unsigned int hashValue = hashing((unsigned char*)key);
	unsigned int idx = hashValue;

	for (int i = 0; i < hash->capacity; i++, idx++) {
		if (hash->bucket[idx % hash->capacity].state == EMPTY) {
			break;
		}
		if (hash->bucket[idx % hash->capacity].state == DELETED) {
			continue;
		}
		if (strcmp(hash->bucket[idx % hash->capacity].data->key, key) == 0) {
			return idx % hash->capacity;
		}
	}
	return -1;
}

void deleteHash(Hash* hash, char* key) {
	int idx = findIndex(hash, key);
	if (idx == -1) {
		return;
	}

	free(hash->bucket[idx].data->key);
	free(hash->bucket[idx].data);
	hash->bucket[idx].state = DELETED;
	hash->size--;
}

Item* find(Hash* hash, char* key) {
	int idx = findIndex(hash, key);
	if (idx == -1) {
		return NULL;
	}

	return hash->bucket[idx].data;
}

static int getNextPrime(int n) {
	while (1) {
		bool isPrime = true;
		for (long long i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			return (n);
		}
		n++;
	}
}

void clear(Hash* hash) {
	for (int i = 0; i < hash->capacity; i++) {
		if (hash->bucket[i].state == USED) {
			free(hash->bucket[i].data->key);
			free(hash->bucket[i].data);
		}
	}
	free(hash->bucket);
	initialize(hash);
}

void displayHash(Hash* hash) {
	printf("Size: %d, Capacity: %d\n", hash->size, hash->capacity);
	for (int i = 0; i < hash->capacity; i++) {
		switch (hash->bucket[i].state) {
		case 0:
			printf("[%d] EMPTY   , - : - [-]\n", i);
			break;
		case 1:
			printf("[%d] USED    , %s : %d [%u]\n", i, hash->bucket[i].data->key, hash->bucket[i].data->value, hash->bucket[i].hashValue % hash->capacity);
			break;
		case 2:
			printf("[%d] DELETED , - : - [-]\n", i);
			break;
		}
		printf("\n");
	}
}

void displayHashFind(Item* result) {
	if (result == NULL) {
		printf("key not found\n");
	}
	else {
		printf("%d\n", result->value);
	}
}

int main(void) {
	Hash hash;

	printf("----- initialize -----\n");
	initialize(&hash);
	displayHash(&hash);

	printf("----- insert -----\n");
	insert(&hash, generateItem("hello", 1));
	displayHash(&hash);

	insert(&hash, generateItem("world", 2));
	displayHash(&hash);

	insert(&hash, generateItem("my name", 3));
	displayHash(&hash);

	insert(&hash, generateItem("is sikpang", 4));
	displayHash(&hash);

	insert(&hash, generateItem("nice", 5));
	displayHash(&hash);

	insert(&hash, generateItem("to meet you", 6));
	displayHash(&hash);

	insert(&hash, generateItem("this is", 7));
	displayHash(&hash);

	insert(&hash, generateItem("hash_table", 8));
	displayHash(&hash);

	insert(&hash, generateItem("thank you", 9));
	displayHash(&hash);

	printf("\n----- find -----\n");
	displayHashFind(find(&hash, "hash_table"));
	displayHashFind(find(&hash, "thank you!"));
	displayHashFind(find(&hash, "thank you"));
	displayHashFind(find(&hash, "hash_tablee"));


	printf("\n----- erase -----\n");
	deleteHash(&hash, "mmm");
	displayHash(&hash);

	deleteHash(&hash, "this is");
	displayHash(&hash);

	deleteHash(&hash, "is sikpang");
	displayHash(&hash);

	deleteHash(&hash, "world");
	displayHash(&hash);

	deleteHash(&hash, "hello");
	displayHash(&hash);


	printf("\n----- edge_case -----\n");
	displayHashFind(find(&hash, "hello"));	// find the erased key
	displayHashFind(find(&hash, "world"));
	displayHashFind(find(&hash, "nice"));	// pass DELETED node when find

	insert(&hash, generateItem("world", 10));	// insert to DELETED node
	displayHash(&hash);

	insert(&hash, generateItem("hello", 11));
	displayHash(&hash);

	insert(&hash, generateItem("abc", 12));
	displayHash(&hash);

	insert(&hash, generateItem("abcd", 13));
	displayHash(&hash);

	displayHashFind(find(&hash, "abcd"));	// pass DELETED node when find
	printf("\n");

	insert(&hash, generateItem("abcde", 14));	// re_allocate
	displayHash(&hash);

	displayHashFind(find(&hash, "abcd"));	// find again!
	displayHashFind(find(&hash, "world"));
	displayHashFind(find(&hash, "my name"));
	displayHashFind(find(&hash, "is sikpang"));
	displayHashFind(find(&hash, "abcdef"));
	printf("\n");

	printf("\n----- clear -----\n");
	clear(&hash);
	displayHash(&hash);

	clear(&hash);			// double clear
	displayHash(&hash);

	insert(&hash, generateItem("abc", 1));	// use after clear
	displayHash(&hash);

	insert(&hash, generateItem("abcd", 2));
	displayHash(&hash);

	insert(&hash, generateItem("abcde", 3));
	displayHash(&hash);

	displayHashFind(find(&hash, "abc"));	// find again again!
	displayHashFind(find(&hash, "abcd"));
	displayHashFind(find(&hash, "world"));

	return 0;
}