//
//  func.h
//  20003proj1
//
//  Created by Har on 26/8/17.
//  Copyright © 2017 Hardaya Singh. All rights reserved.
//

#ifndef func_h

#define func_h
#define STRING_END '\0'
#define TRUE 1
#define FALSE 0
#define UNAVAILABLE -1
#define CHAR_LIMIT 250

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


struct node {
    char character;
    int weight;
    int last_character;
    struct node *left, *right, *equal;
};

void traverse(struct node* pNode, char* buffer, int depth, char* outputfile);
void find_and_traverse( struct node* pNode, char* outpulfile, char *prefix);
struct node *newnode();
struct node *insert(struct node* pNode, char* word, int weight);

#endif /* func_h */

