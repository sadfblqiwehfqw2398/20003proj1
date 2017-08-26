#include "func.h"

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
    
    char buffer[CHAR_LIMIT]; int weight;
    FILE *f = fopen(argv[1],"r");
    assert(f != NULL);
    while (fscanf(f, "%d;%[^\n]", &weight, buffer) != EOF) {
        root = insert(root, buffer, weight);
    }
    fclose(f);
    //scanf("%s", argv[1]);
    find_and_traverse(root, argv[2], argv[3]);
    
    
    return 0;
}
