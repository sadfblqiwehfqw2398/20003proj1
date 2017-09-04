//  Algorithms and Data Structures
//  Assignment 1, 2017 Semester 2
//
//  sorting.c
//
//  Created by Hardaya Singh on 26/8/17.
//  Student ID: 692319
//

#include "func.h"

/* This file handles the sorting after the prefix results are 
 stored in a linked list. It uses selection sort to arrange in
 decending order with results of higher weight on the top.
*/


//the following function swaps the data
//of node1 and node2 without changing their pionters.
void swap(list_t *node1, list_t *node2) {
    list_t *temp = (list_t*) malloc(sizeof(list_t));
    
    //the function memmove copies #of bytes from src to dest
    memmove(temp->key, node1->key, CHAR_LIMIT*sizeof(char));
    temp->weight = node1->weight;
    memmove(node1->key, node2->key, CHAR_LIMIT*sizeof(char));
    node1->weight = node2->weight;
    memmove(node2->key, temp->key, CHAR_LIMIT*sizeof(char));
    node2->weight = temp->weight;
    free(temp);
}

list_t *sort(list_t *head) {
    
    list_t *outer, *inner, *max;
    outer = head;
    int comparisons = 0;
    
    while(outer) {            //outer keeps track of outer index
        inner = max = outer;
        
        while (inner) {       //inner keeps track of sublist
            
            if (max->weight < inner->weight) {
                max =  inner; //update max everytime new max found
            }
            
            comparisons++;
            inner = inner->next;
        }
        
        if (outer->next == NULL) {
            break;           //exit if end of list
        }
        
        swap(outer, max);
        outer = outer->next;
    }
    
    printf("Selection Sort: %d weight comparisons\n", comparisons);
    return head;             //return sorted head
}

