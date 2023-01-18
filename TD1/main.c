//
// Created by Tristan Fumiere on 18/01/2023.
//

#include <stdio.h>
#include "main.h"

/**
 * Exercise 1
 * Effectuer un ”hello world”
 * (Ecrire un programme qui renvoie ’hello world’ dans la console).
 */
void sayHello() {
    printf("Hello world !\n");
}

/**
 * Exercise 2
 * Proposer un programme qui prends deux nombres entiers saisis par l’utilisateur et affiche leur produit.
 * (On pourra s’aider de la fonction scanf dont l’utilisation est d ́ecrite sur le net).
 */
int multiply(int a, int b) {
    return a * b;
}

int askForMultiplication() {
    int a, b;
    printf("Please enter a integer : \n");
    scanf("%d", &a);
    printf("Please enter a second integer : \n");
    scanf("%d", &b);
    return multiply(a, b);
}

/**
 * Exercise 3 TODO: Finish
 * Ecrire un programme qui prends en entrée une date sous le format JJ/MM/AAAA,
 * puis un nombre de jours et renvoie la nouvelle date après que le
 * nombre de jours indiqué soit passé. (attention aux années bissextiles !)
 */
char addDays(int days, int months, int years, int daysToAdd) {
    /*
        1 Si l’année est divisible par 4, passez à l’étape 2. Sinon, passez à l’étape 5.
        2 Si l’année est divisible par 100, passez à l’étape 3. Sinon, passez à l’étape 4.
        3 Si l’année est divisible par 400, passez à l’étape 4. Sinon, passez à l’étape 5.
        4 L’année est une année bissextile (elle compte 366 jours).
        5 L’année n’est pas une année bissextile (elle compte 365 jours).
     */
    int yearsToAdd = daysToAdd / 365;
    printf("%d", yearsToAdd);
    return ' ';
}


char askDate() {
    int days, months, years, daysToAdd;
    printf("Enter a date like JJ/MM/AAAA : \n");
    scanf("%d/%d/%d", &days, &months, &years);
    printf("Enter the number of days to add : \n");
    scanf("%d", &daysToAdd);
    //printf("We'll add %d days to %d/%d/%d", daysToAdd, days, months, years);
    return addDays(days, months, years, daysToAdd);
}

/**
 * Exercise 4 TODO: Start
 * ROT13 est un système de message codé qui effectue une symétrie de l’alphabet autour de m.
 * Ainsi, a donne z et z donne a, b donne y et y donne b, et ainsi de suite.
 * Développer un programme qui donne le ROT13 d’une chaîne de caractères saisie par l’utilisateur.
 */






int main(int argc , char * argv [])
{
    // Exercise 1
    //sayHello();

    // Exercise 2
    //int result = askForMultiplication();
    //printf("%d \n", result);

    // Exercise 3
    askDate();
}