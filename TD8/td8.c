//
// Created by Tristan on 29/03/2023.
//

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <malloc.h>
#include "td8.h"

/* Exo 1 */
void dispInt(int n1, int n2) {
    int res = n1 / n2;
    printf("%d\n", res);
}

void dispFloat(int n1, int n2) {
    double res = n1 / (float) n2;
    printf("%lf\n", res);
}

void divInt(int n1, int n2) {
    void (*pf)();

    if (isdigit(n1 / n2)) {
        pf = &dispInt;
    } else {
        pf = (void (*)()) &dispFloat;
    }
    pf(n1, n2);
}

/* Exo 2 */

void dispFloatSum(int nb, ...) {
    va_list ap;
    va_start(ap, nb);
    float sum = 0;

    while (nb > 0) {
        sum += va_arg(ap, double);
        nb --;
    }
    va_end(ap);
    printf("Sum : %lf\n", sum);
}

/* Exo 3 */

void dispSquare(int nb, ...) {
    va_list ap;
    va_start(ap, nb);

    char *tab = (char *) malloc(sizeof (char) * nb);
    for (int i = 0; i < nb; ++i) {
        char character = (char) va_arg(ap, int);
        tab[i] = character;
    }

    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < ((nb-i)*2)-1; j++) {
            for (int k = 0; k < i-j; ++k) {
                printf("%c", tab[k]);
            }
            printf("%c", tab[i]);

        }
        printf("\n");
    }
    for (int i = nb-2; i >= 0; i--) {
        for (int j = 0; j < ((nb-i)*2)-1; j++) {
            if (j<i) {
                printf("%c", tab[j]);
            }
            printf("%c", tab[i]);
        }
        printf("\n");
    }

    va_end(ap);
}

/* Main */

int main() {
    printf("Hello world !\n");
    divInt(35, 6);

    dispFloatSum(12,5.34,234.87,129.34,5.34,234.87,129.34,5.34,234.87,129.34,5.34,234.87,129.34);

    dispSquare(3, 'a', 'b', 'c');
}