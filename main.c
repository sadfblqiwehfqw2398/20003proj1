#include "func.h"

int main(int argc, char * argv[]) {
    struct node *root = NULL;
    root = insert(root, "cut", 11);
    root = insert(root, "at", 112);
    root = insert(root, "cute", 3);
    root = insert(root, "cure", 2);
    root = insert(root, "cat", 555);
    root = insert(root, "car", 64);
    root = insert(root, "pet", 15);
    root = insert(root, "pe", 334);
    
    char buffer[CHAR_LIMIT]; int weight;
    FILE *file = fopen(argv[1],"r");
    assert(file != NULL);
    while (fscanf(file, "%d;%[^\n]", &weight, buffer) != EOF) {
        root = insert(root, buffer, weight);
    }
    fclose(file);
    
    char prefix[CHAR_LIMIT];
    
    if (argv[3]) {
        find_and_traverse(root, argv[2], argv[3]);
    }
    else {
        while (fgets(prefix, CHAR_LIMIT, stdin) != 0) {
            FILE *file1 = fopen(argv[2],"a");
            assert(file1 != NULL);
            prefix[strcspn(prefix, "\n")] = 0;  //remove '\n' due to fgets
            fprintf(file1, "Prefix: %s\n", prefix);
            fclose(file1);
            find_and_traverse(root, argv[2], prefix);
            FILE *file2 = fopen(argv[2], "a");
            assert(file2 != NULL);
            fprintf(file2, "\n\n");
            fclose(file2);
        }
    }
    return 0;
}
