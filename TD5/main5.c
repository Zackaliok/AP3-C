//
// Created by Tristan Fumiere on 08/02/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main5.h"


/**
* Exercice 1
*/

struct tree_ {
    struct tree *left;
    struct tree *right;

    int label;
};

typedef struct tree_ * tree;

tree createNewTreeNode(int label) {
    tree elt = malloc(sizeof (struct tree_));
    elt->label = label;
    elt -> left = NULL;
    elt -> right = NULL;
}

void addTreeNode(tree t, int new) {
    if(t==NULL) {
        printf("error");
        return;
    }
    /**
     * while next != NULL
     *  if >
     *      next = right
     *          else
     *              next = left
     */
    while (t != NULL) {
        printf("On est à %d\n", t->label);
        if (t->label < new) {
            t = t->left;
        } else {
            t = t->right;
        }
        printf("On est à %d\n", t->label);
    }
    tree newElement = createNewTreeNode(new);
    if (t->label < new) {
        t->left = newElement;
    } else {
        t->right = newElement;
    }
}


int main5() {
    printf("Hello\n");

    tree test = createNewTreeNode(5);
    addTreeNode(test, 2);
    addTreeNode(test, 1);
    addTreeNode(test, 4);
    addTreeNode(test, 3);
    addTreeNode(test, 8);
    addTreeNode(test, 7);
    addTreeNode(test, 9);


}