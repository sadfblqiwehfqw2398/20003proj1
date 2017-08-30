//
//  func.h
//  20003proj1
//
//  Created by Har on 26/8/17.
//  Student ID: 692319
//

#ifndef func_h

#define func_h

//constants
#define STRING_END '\0'
#define TRUE 1
#define FALSE 0
#define UNAVAILABLE -1
#define CHAR_LIMIT 250
#define DATAFILE argv[1]
#define OUTFILE argv[2]

//libraries
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//structures
typedef struct node_t {
    char character;
    int weight;
    int last_character;
    struct node_t *left, *right, *equal;
}node_t;

typedef struct list_t {
    char key[CHAR_LIMIT];
    int weight;
    struct list_t *next;
}list_t;


//function prototypes
node_t *tree_node();
node_t *insert_tree(node_t *pNode, char *word, int weight);
void find_and_traverse( node_t *pNode, char *prefix, list_t **head);
void traverse(node_t *pNode, char *buffer, int depth, list_t **head);
list_t *insertList(char *key, int weight, list_t **head);
list_t *sort(list_t *head);
void print_list(list_t *head, char *outputfile, char *pefix);
void free_tree(node_t *root);
void free_list(list_t *head);

#endif /* func_h */

