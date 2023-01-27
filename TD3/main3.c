//
// Created by Tristan Fumiere on 26/01/2023.
//

#include <printf.h>
#include <stdlib.h>
#include "main3.h"
enum promotion {
    CIR1, CIR2, M1, AP3, AP4, AP5
};
struct student {
    char * name;
    enum promotion * promotion;
    float notes[10];
};

/**
 * Create a new student
 * @param name
 * @param promotion
 * @param notes
 * @return
 */
struct student * createStudent(char * name, enum promotion * promotion, const float notes[10]) {
    struct student * newStudent = (struct student*) malloc(sizeof(struct  student));
    newStudent->name = name;
    newStudent->promotion = promotion;
    for (int i = 0; i < 10; i++) {
        newStudent->notes[i] = notes[i];
    }

    return newStudent;
}

float sum(struct student * student) {
    float sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += student->notes[i];
    }

    return sum;
}
float avg(struct student * student) {
    float average = sum(student) / 10.0;
    return average;
}

//TODO: Function pour créer un tableau de 30 élèves
// TODO : Appliquer la fonction de moyenne sur les 30 élèves

int main() {
    printf("Hello\n");

    float notes[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct student * myStudent = createStudent("Fredo", (enum promotion *) AP3, notes);

    for (int i = 0; i < 10; i++) {
        printf("%f\n", myStudent->notes[i]);
    }

    printf("Average: %f", avg(myStudent));
}