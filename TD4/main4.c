//
// Created by Tristan Fumiere on 02/02/2023.
//

#include "main4.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct liste_ {
    int  value;
    struct  liste_ * next;
    struct liste_ * previous;
};
typedef  struct  liste_ * liste;

liste createNew(int v) {
    liste  elt = malloc(sizeof(struct  liste_ ));
    elt ->value = v;
    elt ->next = NULL;
    elt ->previous = NULL;
    return  elt;
}

void add(liste l, int  new) {
    if(l==NULL) {
        printf("error");
        return;
    }
    while(l->next!=NULL) {
        l=l->next;
    }
    liste newElement = createNew(new);
    l->next=newElement;
    newElement->previous = l;
}

/**
 * Exercice 1
 */
int CountElements(liste l, bool display) {
    int sum = 1;
    if (display) {
        printf("All elements of the list : \n%d\n", l->value);
    }
    while (l->next != NULL) {
        sum += 1;
        l = l->next;
        if (display) {
            printf("%d \n", l->value);
        }
    }
    return sum;
}

/**
 * Exercice 2
 */
void mergeLists(liste l1, liste l2) {
    while (l1->next != NULL) {
        l1 = l1->next;
    }
    l1->next = l2;
    l2->previous = l1;
}

/**
 * Exercice 3
 */
void insertElement(liste l, int index, int new) {
    int nbElem = CountElements(l, false);
    if (index >= nbElem) {
        add(l, new);
    } else {
        int cpt = 0;
        while (cpt < index) {
            cpt ++;
            l = l->next;
        }
        liste newElem = createNew(new);

        newElem->previous = l;
        newElem->next = l->next;
        l->next->previous = newElem;
        l->next = newElem;
    }
}

/**
 * Exercice 4
 */
void deleteElement(liste l, int index){
    int cpt=0;
    while(l->next!=NULL){
        if(cpt==index-1){
            liste skipped=l->next->next;
            liste aDelete=l->next;
            l->next=skipped;
            free(aDelete);
        }
        cpt++;
        l=l->next;
    }
}

int main() {
    printf("Hello\n");

    liste l1 = createNew (0);
    add(l1,42);
    add(l1,35);
    add(l1,28);

    //printf("Total count : %d\n", CountElements(l1, true));

    liste l2 = createNew(69);
    add(l2, 96);
    add(l2, 12);
    add(l2, 234);

    //printf("Exercice 2\n");
    //mergeLists(l1, l2);
    //printf("Total count : %d\n", CountElements(l1, false));

    //printf("Exercice 3\n");
    insertElement(l1, 1, 999);
    printf("Total count : %d\n", CountElements(l1, true));

    //printf("Exercice 3\n");
    deleteElement(l1, 2);
    printf("Total count : %d\n", CountElements(l1, true));


}