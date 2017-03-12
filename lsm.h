#include <stdio.h> 
#include <stdlib.h>

#define BLOCKSIZE 1000
#define MAX_LEVELS 2
#define MULTIPIER 2

typedef struct node {
	int key; 
	int val;
	int index; 
} node;

typedef struct block {
	node *nodes;
	int capacity;
	int curr_size;
	int is_sorted:1;
} block;

typedef struct lsm_tree {
	int num_written; // number of nodes written
	struct block *blocks;     //array of blocks
	int num_curr_blocks;
} lsm_tree; 

lsm_tree *lsm_init(void);

int put(int key, int value, lsm_tree *tree);

int push_to_disk(lsm_tree *tree);

int comparison(const void *a, const void *b);

void merge_data(node *buf, node *buf1, node *buf2, int sz1, int sz2);

int get(int key, lsm_tree *tree);

void lsm_destroy(lsm_tree *tree);

void range(int key1, int key2, lsm_tree *tree);

int delete(int key, lsm_tree *tree);