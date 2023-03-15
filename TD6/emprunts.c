//
// Created by tristan on 15/03/23.
//

#include "emprunts.h"

enum rang {
    BASIQUE, PLATINE
};

typedef struct client {
    char * nom;
    enum rang rang;
    int age;
} client;