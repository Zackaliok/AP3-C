//
// Created by Tristan Fumiere on 22/03/2023.
//

#include <stdlib.h>
#include "Livres.h"

struct books {
    char *title;
    int years;
    char *authors;
};

struct bookshelf {
    PtrBooks book;
    PtrBookshelf next;
};

PtrBookshelf createBookshelf(char *title, int years, char *author) {
    PtrBooks new = malloc(sizeof(struct books));
    new->title = title;
    new->authors = author;
    PtrBookshelf add = malloc(sizeof(struct bookshelf));
    add->book = new;
    add->next = NULL;
    return add;
}

void addBook(PtrBookshelf l, char *title, int years, char *author) {
    if (l == NULL) {
        l = createBookshelf(title, years, author);
        return;
    }
    while (l->next != NULL) {
        l = l->next;
    }
    l->next = createBookshelf(title, years, author);
}

void removeBook(PtrBookshelf l, PtrBooks b) {
    PtrBookshelf previous;
    while (l->next != NULL && l->book != b) {
        previous = l;
        l = l->next;
    }

    if (l->next == NULL && l->book != b) {
        return;
    }
    previous->next = l->next;
    free(l);
    return;
}