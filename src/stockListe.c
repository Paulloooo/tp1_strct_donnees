#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initStock(StockListe* stock) {
}

void libererMemoire(StockListe* stock) {

}

void ajouterArticle(StockListe* stock, Article article) {
}


int chargerFichier(const char* nomFichier, StockListe* stock) {
    FILE* fichier = fopen(nomFichier, "r");
    if (!fichier) {
        return -1;
    }

    char ligne[200];

    // Ligne d'intitulé à ignorer
    if (!fgets(ligne, sizeof(ligne), fichier)) {
        fprintf(stderr, "Erreur: fichier vide ou lecture échouée\n");
        fclose(fichier);
        return -1;
    }

    while (fgets(ligne, sizeof(ligne), fichier)) {
    }

    fclose(fichier);
    return 0;
}
