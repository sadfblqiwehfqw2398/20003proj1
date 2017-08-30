//
//  main.c
//  20003proj1
//
//  Created by Har on 26/8/17.
//  Student ID: 692319
//

#include "func.h"
#include "sorting.h"

int main(int argc, char * argv[]) {
    node_t *root = NULL;
    list_t *head = NULL;
    
    char buffer[CHAR_LIMIT]; int weight;
    FILE *file = fopen(DATAFILE,"r");
    assert(file != NULL);
    while (fscanf(file, "%d;%[^\n]", &weight, buffer) != EOF) {
        root = insert_tree(root, buffer, weight);
    }
    fclose(file);
    
    char prefix[CHAR_LIMIT];
    
    while (fgets(prefix, CHAR_LIMIT, stdin) != FALSE) {
        
        prefix[strcspn(prefix, "\n")] = 0; //remove '\n' due to fgets and replace with '\0'
        
        list_t *head = NULL;
        
        find_and_traverse(root, prefix, &head);
        head = sort(head);
        
        print_list(head, OUTFILE, prefix);
        
    }
    free_tree(root);
    free_list(head);
    return 0;
}
