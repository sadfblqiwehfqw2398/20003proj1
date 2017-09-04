//  Algorithms and Data Structures
//  Assignment 1, 2017 Semester 2
//
//  func.c
//
//  Created by Hardaya Singh on 26/8/17.
//  Student ID: 692319
//

#include "func.h"

node_t *tree_node(){
    node_t *node = (node_t*) malloc(sizeof(node_t));
    assert(node != NULL);
    return node;
}

node_t *insert_tree(node_t *pNode, char *word, int weight) {
    if(pNode == NULL) {                   //pNode Null then insert
                                          //the letter in equal pos
        pNode = tree_node();
        pNode->left = pNode->right = pNode->equal = NULL;
        pNode->character = *word;
        pNode->last_character = FALSE;
    }
    
    if (*word < pNode->character) {       //if current letter less then go left
        pNode->left = insert_tree(pNode->left, word, weight);
    }
    
    else if (*word == pNode->character) { //if it equals to node
        
        if (*(word+1) == STRING_END) {    //check if its last letter to insert
            pNode->last_character = TRUE; //fill in weight and flag
            pNode->weight = weight;
        }
        
        else {                            //else move to next letter in word
            pNode->equal = insert_tree(pNode->equal, word+1, weight);
        }
    }
    
    else {                                //if letter bigger then go right
        pNode->right = insert_tree(pNode->right, word, weight);
    }
    
    return pNode;
}

void find_and_traverse( node_t *pNode, char *prefix, list_t **head){
    /**
     * Find the node in the tree that represents the prefix
     * pNode will point there if we reached the '\0' symbol,
     * if prefix does not exist , then pNode should be NULL
     */
    char buffer[CHAR_LIMIT]; int index = 0, comparisons = 0;
    char *temp = prefix;
    while(*temp != STRING_END && pNode != NULL){
        /**
         * Find tree position for prefix
         */
        if(*temp < pNode->character){    //left branch
            pNode = pNode->left;
            comparisons++;
            continue ;
        }
    
        if(*temp > pNode->character){    //right branch
            pNode = pNode->right;
            comparisons++;
            continue ;
        }
    
        if(*temp == pNode->character){   //equal branch
            
            if (pNode->equal && *(temp+1) != STRING_END) {
                pNode = pNode->equal;    //if temp is not last char of prefix
                buffer[index++] = *temp; //then keep looking in equal branch
                temp++;
                comparisons++;
                continue;
            }
            
            buffer[index++] = *temp;     //otherwise just increment temp
            temp++;                      //so loop ends in next run
            comparisons++;
        }
    }
    
    //report total comparisons as program has either reached end of tree or
    //have found the prefix
    printf("Prefix: %s took %d char comparisons\n", prefix, comparisons);

    /**
     * At this point, pNode should be pointing to
     * the node where the prefix is contained.
     */
    if(pNode != NULL) {
        /**
         * Include the prefix itself as a candidate
         * if prefix is a key
         */
        if (pNode->last_character == TRUE) {
            buffer[strlen(prefix)] = STRING_END;
            *head = insertList(buffer, pNode->weight, head);
            
        }
        
        /**
         * print all the keys that contain the prefix
         */
        traverse (pNode->equal, buffer , (int)strlen(prefix), head) ;
    }
    else {
        *head = insertList("NOTFOUND", UNAVAILABLE, head);
    }
}


/**
 * Tree traversal from a given node
 */
void traverse(node_t* pNode, char* buffer, int depth, list_t **head) {
    if (pNode == NULL) return;
    /**
     * Go first to the left most branch */
    traverse (pNode->left, buffer, depth, head) ;
    /**
     * If no more left branches , then save the character
     */
    buffer[depth] = pNode->character;
    if (pNode->last_character == TRUE) {
        buffer[depth+1] = STRING_END ;
        *head = insertList(buffer, pNode->weight, head);
    }
    
    /**
     * and go to the equal branch, advancing
     * to the next character of the key
     */
    traverse (pNode->equal , buffer , depth + 1, head) ;
    /**
     * Finally go to the branches that contain
     * characters greater than the current one in the buffer
     */
    traverse (pNode->right, buffer, depth, head) ;
}

//this func creates a new node for list and returns the pointer to it
list_t *list_node() {
    list_t *node = (list_t*) malloc(sizeof(list_t));
    assert(node != NULL);
    node->next = NULL;
    return node;
}

//this is used to create linked list of buffers found
list_t *insertList(char *key, int weight, list_t **head) {
    list_t *temp = list_node();
    strncpy(temp->key, key, strlen(key) + 1);   //strlen(key) + 1 for '\0'
    temp->weight = weight;
    temp->next = *head;
    *head = temp;
    return *head;
}

//the following fprints list to a file given a head
void print_list(list_t *head, char *outputfile, char *prefix) {
    FILE *file = fopen(outputfile, "a");
    assert(file != NULL);
    fprintf(file, "Prefix: %s\n", prefix);
    while (head) {
        
        if (head->weight == UNAVAILABLE) {
                fprintf(file, "%s\n", head->key);
        }
        else {
        fprintf(file, "key: %s --> weight: %d\n", head->key, head->weight);
        }
        head = head->next;
    }
    fprintf(file, "\n\n");
    fclose (file);
}

//free tree using in order traversal
void free_tree(node_t *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->equal);
    free(root);
    free_tree(root->right);
    
}

void free_list(list_t *head) {
    list_t *temporary = NULL;
    while (head) {
        temporary = head;
        head = head->next;           
        free(temporary);
    }
}
