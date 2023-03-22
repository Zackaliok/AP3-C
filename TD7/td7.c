//
// Created by Tristan Fumiere on 22/03/2023.
//

#include <printf.h>
#include "td7.h"

int div(int a) {
    printf("%d", (a / 10));
    return a / 10;
}

int mult(int a) {
    printf("%d", (a * 10));
    return a * 10;
}

void exo2(int a) {
    int (*ptrMult)(int) = &mult;
    int (*ptrDiv)(int) = &div;


}