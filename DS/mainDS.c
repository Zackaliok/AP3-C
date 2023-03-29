//
// Created by Tristan Fumiere on 08/02/2023.
//

#include <stdio.h>
#include "mainDS.h"

void exo1DS(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n-1) {
                printf("*");
            } else {
                if (j == 0 || j == n-1) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void triTrois(int* a, int* b, int* c) {
    int tmp = 0;
    if (*a >= *b && *a >= *c) {
        tmp = *c;
        *c = *a;
        *a = tmp;
    }
    else if (*b >= *a && *b >= *c) {
        tmp = *c;
        *c = *b;
        *b = tmp;
    }
    if (*a >= *b) {
        tmp = *b;
        *b = *a;
        *a = tmp;
    }
}


int main() {
    exo1DS(4);
}