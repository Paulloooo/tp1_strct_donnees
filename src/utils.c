#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "article.h"
#include "stockTableau.h"

int chargerArticles(const char* nomFichier, Article* article1, Article* article2) {
    FILE* fichier = fopen(nomFichier, "r");
    if (!fichier) {
        return -1;
    }

    char ligne[200];
    // Ligne d'intitulé à ignorer
    if (!fgets(ligne, sizeof(ligne), fichier)) {
        fclose(fichier);
        return -1;
    }

    // première ligne de données
    if (!fgets(ligne, sizeof(ligne), fichier)) {
        fclose(fichier);
        return -1;
    }
    printf(ligne);
    sscanf(ligne, "%d,%99[^,],%d,%lf", &article1->id, article1->nom, &article1->quantite, &article1->prix);

    // deuxième ligne
    if (!fgets(ligne, sizeof(ligne), fichier)) {
        fclose(fichier);
        return -1;
    }
    sscanf(ligne, "%d,%99[^,],%d,%lf", &article2->id, article2->nom, &article2->quantite, &article2->prix);

    fclose(fichier);
    return 0;
}

void afficherStockTableau(StockTableau* stock) {
    for (int i = 0; i < stock->nbArticles; i++) {
        printf("Article %s : \nIdentifiant : %d, \nPrix : %lf \nQuantit\202 : %d\n", stock->articles[i].nom, stock->articles[i].id, stock->articles[i].prix, stock->articles[i].quantite);
        printf("----------------------------------------------------\n");
    }
}