//  Algorithms and Data Structures
//  Assignment 1, , 2017 Semester 2
//
//  main1.c
//
//  Created by Hardaya Singh on 26/8/17.
//  Student ID: 692319
//

#include "func.h"

int main(int argc, char * argv[]) {
    node_t *root = NULL;
    
    
    FILE *file = fopen(DATAFILE,"r");       //open and read from the datafile
    assert(file != NULL);
    
    char buffer[CHAR_LIMIT]; int weight;
    while (fscanf(file, "%d;%[^\n]", &weight, buffer) != EOF) {
        root = insert_tree(root, buffer, weight);
    }
    
    fclose(file);
    
    char prefix[CHAR_LIMIT];               //get prefix from stdin
    while (fgets(prefix, CHAR_LIMIT, stdin) != FALSE) {
        
        prefix[strcspn(prefix, "\n")] = 0; //remove '\n' due to
                                           //fgets and replace with '\0'
        
        list_t *head = NULL;
                                           //find, print and free each result
        find_and_traverse(root, prefix, &head);
        print_list(head, OUTFILE, prefix);
        free_list(head);
        
    }
    free_tree(root);
    return 0;
}
