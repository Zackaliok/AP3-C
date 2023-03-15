//
// Created by tristan on 15/03/23.
//

#include "livres.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure Livre
typedef struct Livre {
    char titre[100];
    int annee;
    char auteur[100];
} Livre;

// Définition de la structure Bibliothèque
typedef struct Bibliotheque {
    Livre* livres;
    int nbLivres;
    int capacite;
} Bibliotheque;

// Fonction pour ajouter un livre à la bibliothèque
void ajouterLivre(Bibliotheque* biblio, Livre livre) {
    // Vérification que la bibliothèque a assez de place
    if (biblio->nbLivres >= biblio->capacite) {
        printf("La bibliothèque est pleine, impossible d'ajouter le livre.\n");
        return;
    }
    // Ajout du livre à la bibliothèque
    biblio->livres[biblio->nbLivres++] = livre;
}

// Fonction pour supprimer un livre de la bibliothèque
void supprimerLivre(Bibliotheque* biblio, char* titre) {
    int i;
    for (i = 0; i < biblio->nbLivres; i++) {
        if (strcmp(biblio->livres[i].titre, titre) == 0) {
            // Suppression du livre
            biblio->livres[i] = biblio->livres[--biblio->nbLivres];
            printf("Le livre \"%s\" a été supprimé de la bibliothèque.\n", titre);
            return;
        }
    }
    printf("Le livre \"%s\" n'a pas été trouvé dans la bibliothèque.\n", titre);
}

// Fonction pour afficher les informations d'un livre à partir de son titre
void afficherLivreParTitre(Bibliotheque* biblio, char* titre) {
    int i;
    for (i = 0; i < biblio->nbLivres; i++) {
        if (strcmp(biblio->livres[i].titre, titre) == 0) {
            printf("Titre : %s\n", biblio->livres[i].titre);
            printf("Année de publication : %d\n", biblio->livres[i].annee);
            printf("Auteur : %s\n", biblio->livres[i].auteur);
            return;
        }
    }
    printf("Le livre \"%s\" n'a pas été trouvé dans la bibliothèque.\n", titre);
}

// Fonction pour afficher tous les livres d'un auteur
void afficherLivresParAuteur(Bibliotheque* biblio, char* auteur) {
    int i, nbLivres = 0;
    for (i = 0; i < biblio->nbLivres; i++) {
        if (strcmp(biblio->livres[i].auteur, auteur) == 0) {
            nbLivres++;
            printf("%d. \"%s\"\n", nbLivres, biblio->livres[i].titre);
        }
    }
    if (nbLivres == 0) {
        printf("Aucun livre de l'auteur \"%s\" n'a été trouvé dans la bibliothèque.\n", auteur);
    }
}

int main() {

}