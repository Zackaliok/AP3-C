//
// Created by Tristan Fumiere on 25/01/2023.
//

#include <stdio.h>
#include "main2.h"

void exo1() {
    int a = 5;
    int b = 10;
    int * ptrX = &a;
    int * ptrY = &b;
    b++;
    a++;

    *ptrX = a+b;
    *ptrY = b+*ptrX;

    /*(*ptrY)++;
    (*ptrX)++;*/
    ptrX = ptrY;
    (*ptrX)++;

    printf("%d\n", *ptrX);
    printf("%d\n", *ptrY);
}

/**
 * Affiche à l'écran l'adresse de n'importe quelle variable
 * @param variable
 */
void getAdress(void * variable) {
    printf("%p", variable);
}

void exo2(void * v1, void * v2, void * v3) {
    int * ptrMin = v1;
    if (ptrMin > v2) {
        ptrMin = v2;
    }
    if (ptrMin > v3) {
        ptrMin = v3;
    }

    printf("%x\n", v1);
    printf("%x\n", v2);
    printf("%x\n", v3);

    printf("%x\n", ptrMin);

}

/**
 * For exercice 3
 */
void getMeanSum(int * ptrMoyenne, int * ptrSomme, int i[]) {
    for (int j = 0; j <= sizeof *i; ++j) {
        //printf("%d", i[j]);
        *ptrSomme += i[j];
    }
    *ptrMoyenne = (*ptrSomme / 5);
}

void exo5() {
    int tabInt[4] = {1, 2, 3, 4};
    char tabChar[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    float tabFloat[6] = {5.4, 2.3, 5.5, 6.8, 2.1, 9.7};

    void* tabPtr[3] = {&tabInt, &tabChar, &tabFloat};
}

int main2() {
    // Exercice 1
    exo1();
    // V1 : Print 18 et 29
    // V2 : Print 29 et 29
    // on a mis la valeur de ptrY dans ptrX donc on a créé des "jumeaux"

    // Exercice 2
    int a = 5;
    //getAdress( &a);

    int b = 2;
    int c = 4;
    int d = 6;
    //exo2(&b, &c, &d);

    int i[5] = {0,2,4,6,8};
    int moyenne;
    int somme;
    //getMeanSum(&moyenne, &somme, i);
    //printf("La moyenne est %d et la somme est %d", moyenne, somme);

}