//
// Created by Tristan Fumiere on 22/03/2023.
//

#include <stdbool.h>
#include <stdlib.h>
#include "Emprunts.h"

enum rang {
    BASIQUE, PLATINE
};

struct client {
    char *nom;
    enum rang rang;
    int age;
};

struct emprunt {
    PtrBooks book;
    PtrClient client;
    int dateRendu;
    bool isRendu;
};

struct listeEmprunts {
    PtrEmprunt emprunt;
    PtrListeEmprunts next;
};

PtrEmprunt createEmprunt(PtrBooks book, PtrClient client, int dateRendu, bool isRendu) {
    PtrEmprunt new = malloc(sizeof(struct emprunt));
    new->book = book;
    new->client = client;
    new->dateRendu = dateRendu;
    new->isRendu = isRendu;

    return new;
}

PtrClient createClient(char *nom, enum rang rang, int age) {
    PtrClient new = malloc(sizeof(struct client));
    new->nom = nom;
    new->rang = rang;
    new->age = age;

    return new;
}

PtrListeEmprunts createListeEmprunt(PtrBooks book, PtrClient client, int dateRendu, bool isRendu) {
    PtrListeEmprunts new = malloc(sizeof (struct listeEmprunts));
    new->emprunt = createEmprunt(book, client, dateRendu, isRendu);
    new->next = NULL;
    return new;
}

void addListeEmprunt(PtrListeEmprunts l, PtrBooks book, PtrClient client, int dateRendu, bool isRendu) {
    if (l == NULL) {
        l = createListeEmprunt(book, client, dateRendu, isRendu);
        return;
    }
    while (l->next != NULL) {
        l = l->next;
    }
    l->next = createListeEmprunt(book, client, dateRendu, isRendu);
}

void removeEmprunt(PtrListeEmprunts l, PtrEmprunt e) {
    PtrListeEmprunts previous;
    while (l->next != NULL && l->emprunt != e) {
        previous = l;
        l = l->next;
    }
    if (l->next == NULL && l->emprunt != e) {
        return;
    }
    previous->next = l->next;
    free(l);
    return;
}