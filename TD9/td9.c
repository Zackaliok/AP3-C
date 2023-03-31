//
// Created by Tristan on 31/03/2023.
//

#include "td9.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/* Structure de liste chaînée */

struct liste_ {
    char *  value;
    struct liste_ * next;
    struct liste_ * previous;
};
typedef  struct  liste_ * liste;

liste createNew(char * v) {
    liste  elt = malloc(sizeof(struct  liste_ ));
    elt ->value = v;
    elt ->next = NULL;
    elt ->previous = NULL;
    return  elt;
}

void add(liste l, char * new, int sizeNew) {
    //printf("Ajout d'une ligne\n");
    // Malloc de la ligne à la bonne taille
    char * newLine = (char *) malloc(sizeof (char) * sizeNew);
    for (int i = 0; i < sizeNew; i++) {
        newLine[i] = new[i];
    }

    if(l==NULL) {
        printf("error");
        return;
    }
    while(l->next!=NULL) {
        l=l->next;
    }
    liste newElement = createNew(newLine);
    l->next=newElement;
    newElement->previous = l;
}

/* ---------------------------- */

void dispExo1(char * path) {
    FILE * fp;
    fp = fopen(path, "r");
    liste l1 = createNew("");

    char c = fgetc(fp);
    char * lineBuffer = (char *) malloc(sizeof (char) * 1000);
    int cursorBuffer = 0;

    while (c != EOF) {
        cursorBuffer = 0;
        while (c != '\n') {
            printf("%c", c);
            lineBuffer[cursorBuffer] = c;
            c = fgetc(fp);
            cursorBuffer ++;
        }
        lineBuffer[cursorBuffer] = '\n';
        c = fgetc(fp);
        add(l1, lineBuffer, cursorBuffer);
    }
    fclose(fp);
}

int main() {
    dispExo1("./exo1.txt");
}