//
//  sorting.c
//  20003proj1
//
//  Created by Har on 26/8/17.
//  Student ID: 692319
//

#include "func.h"


void swap(list_t *node1, list_t *node2) {
    list_t *temp = (list_t*) malloc(sizeof(list_t));
    memmove(temp->key, node1->key, CHAR_LIMIT);
    temp->weight = node1->weight;
    memmove(node1->key, node2->key, CHAR_LIMIT);
    node1->weight = node2->weight;
    memmove(node2->key, temp->key, CHAR_LIMIT);
    node2->weight = temp->weight;
}

list_t *sort(list_t *head) {
    list_t *outer, *inner, *max;
    outer = head;
    int comparisons = 0;
    while(outer) {
        inner = max = outer;
        
        while (inner) {
            
            if (max->weight < inner->weight) {
                max =  inner;
                
            }
            comparisons++;
            inner = inner->next;
        }
        
        if (outer->next == NULL) {
            break;
        }
        swap(outer, max);
        outer = outer->next;
    }
    printf("Selection Sort: %d weight comparisons\n", comparisons);
    return head;
}

