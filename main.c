#include <stdio.h>
#include "stdlib.h"
#include <assert.h>
#include <string.h>


//#define END_OF_WORD '\0'

struct node {
    char character;
    int weight;
    int last_character;
    struct node *left, *right, *equal;
};

void output(char *key, int weight, char* outputfile) {
    FILE *f1 = fopen(outputfile, "a");
    if (f1!=NULL){
        if (weight<0) {
            printf("%s\n\n", key);
        }
        fprintf(f1, "key: %s   Weight: %d\n", key, weight);
        fclose (f1);
    }
}

/**
 * Tree traversal from a given node
 */
void traverse(struct node* pNode, char* buffer, int depth, char* outputfile, char *prefix) {
    if (pNode == NULL) return;
    /**
     * Go first to the left most branch */
    traverse (pNode->left, buffer, depth, outputfile, prefix) ;
    /**
     * If no more left branches , then save the character
     */
       buffer[depth] = pNode->character;
    if (pNode->last_character == 1 /* pNode end of string flag is true*/) {
            buffer[depth+1] = '\0' ;
            printf( "%s\n" , buffer) ;
            output(buffer, pNode->weight, outputfile);
    }
    
    /**
     * and go to the equal branch, advancing
     * to the next character of the key
     */
    traverse (pNode->equal , buffer , depth + 1, outputfile, prefix) ;
    /**
     * Finally go to the branches that contain
     * characters greater than the current one in the buffer
     */
    traverse (pNode->right, buffer, depth, outputfile, prefix) ;
}

void find_and_traverse( struct node* pNode, char* outpulfile, char* prefix ){
    /**
     * Find the node in the tree that represents the prefix
     * pNode will point there if we reached the '\0' symbol,
     * if prefix does not exist , then pNode should be NULL
     */
    char buffer[15]; int i=0, comparisons = 0;
    char *temp = prefix;
    struct node *tempPtr;
    while(*temp != '\0' && pNode != NULL){
        /**
         * Find tree position for prefix
         */
        // left branch
        if(*temp < pNode->character){
            pNode = pNode->left;
            comparisons++;
            continue ;
        }
        
        // right branch
        if(*temp > pNode->character){
            pNode = pNode->right;
            comparisons++;
            continue ;
        }
        // equal branch
        if(*temp == pNode->character){
            if (pNode->equal && *(temp+1) != '\0') {
                pNode = pNode->equal;
                buffer[i++] = *temp;
                temp++;
                continue;
            }
            buffer[i++] = *temp;
            temp++;
        }
    }
    
    
    
    /**
     * At this point, pNode should be pointing to
     * the node where the prefix is contained.
     */
    printf("Prefix: %s took %d char comparisons\n", prefix, comparisons);
    if(pNode != NULL){
        
        /**
         * Include the prefix itself as a candidate
         * if prefix is a key
         */
        
        if (pNode->last_character == 1) {
            buffer[strlen(prefix)+1] = '\0';
            printf( "%s\n", buffer);
            output(buffer, pNode->weight, outpulfile);
            
        }
        
        /**
         * print all the keys that contain the prefix
         */
        traverse (pNode->equal, buffer , strlen(prefix), outpulfile, prefix) ;
    }
    else {
        output("NOTFOUND", -1, outpulfile); //make typedef here NOTFOUND
    }
}

struct node *newnode(){
    struct node *node = (struct node*) malloc(sizeof(struct node));
    assert(node != NULL);
    return node;
}

struct node *insert(struct node* pNode, char* word, int weight) {
    if(pNode == NULL) {                   //pNode Null then insert the letter in equal pos
        pNode = newnode();
        pNode->left = pNode->right = pNode->equal = NULL;
        pNode->character = *word;
        pNode->last_character = 0;
    }
    
    if (*word < pNode->character) {    //if current letter less then go left
        pNode->left = insert(pNode->left, word, weight);
    }
    
    else if (*word == pNode->character) { //if it equals to node
        
        if (*(word+1) == '\0') {                //check if its last letter to insert
            pNode->last_character = 1;         //fill in weight and flag
            pNode->weight = weight;
        }
        
        else {                              //otherwise move on to next letter in word
            pNode->equal = insert(pNode->equal, word+1, weight);
        }
    }
    
    else {          //if letter bigger then go right
        pNode->right = insert(pNode->right, word, weight);
    }
    
    return pNode;
}


int main(int argc, char * argv[]) {
    struct node *root = NULL;
    root = insert(root, "cut", 2);
    root = insert(root, "at", 2);
    root = insert(root, "cute", 2);
    root = insert(root, "cure", 2);
    root = insert(root, "cat", 2);
    root = insert(root, "car", 2);
    root = insert(root, "pet", 2);
    root = insert(root, "pe", 2);
    
    char buffer[250]; int weight;
    FILE *f = fopen(argv[1],"r");
    assert(f != NULL);
    while (fscanf(f, "%d;%[^\n]", &weight, buffer) != EOF) {
        root = insert(root, buffer, weight);
    }
    
    //scanf("%s", argv[1]);
    find_and_traverse(root, argv[2], argv[3]);
    //fclose(f);
    
    
    
    return 0;
}
