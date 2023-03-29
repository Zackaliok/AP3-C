//
// Created by Tristan Fumiere on 26/01/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "main3.h"
enum promotion {
    CIR1, CIR2, M1, AP3, AP4, AP5
};
struct student {
    char * name;
    char * promotion;
    float notes[10];
};

/**
 * Create a new student
 * @param name
 * @param promotion
 * @param notes
 * @return
 */
struct student * createStudent(char * name, char * promotion, float notes[10]) {
    struct student *newStudent = (struct student*) malloc(sizeof(struct  student));
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
        printf("%f\n", student->notes[i]);
        sum += student->notes[i];
    }

    return sum;
}
float avg(struct student * student) {
    float average = sum(student) / 10.0;
    return average;
}

float float_rand( )
{
    return (float)rand()/10;
}

void createClass(int n, struct student ** ptrClass) {
    for (int i = 0; i < n; i++) {
        float notes[10] = {
                float_rand(0, 10),
                float_rand(0, 10),
                float_rand(0, 10),
                float_rand(0, 10),
                float_rand(0, 10),float_rand(0, 10),
                float_rand(0, 10),float_rand(0, 10),float_rand(0, 10),
                float_rand(0, 10),



        };

        ptrClass[i] = createStudent("Student", "AP3", notes);
    }
}

float getGeneralAverage(struct student ** class) {
    float sum = 0.0;
    for (int i = 0; i < 30; i++) {

    }
}


int main3() {
    printf("Hello\n");
    float notes[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct student * myStudent = createStudent("Fredo", "AP3", notes);

    struct student ** class = (struct student **) malloc((sizeof (struct student) * 30));
    createClass(30, (struct student **) &class);
    //printf("%f", avg(class[0]));

    printf("%f", float_rand());
}