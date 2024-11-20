#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stockListe.h"

void initStockL(StockListe* stock) {
    NoeudArticle* first = NULL;
    stock->first = first;
}


void libererMemoireStockL(StockListe* stock) {
    NoeudArticle* current = stock->first;
    while (current) {
        NoeudArticle* next = current->next;
        free(current);
        current = next;
    }
    stock->first = NULL;

}

void ajouterArticleStockL(StockListe* stock, Article article) {
    NoeudArticle* new = (NoeudArticle*)malloc(sizeof(NoeudArticle));
    new->article = article;
    new->next = NULL;

    if(stock->first == NULL) {
        stock->first = new;
        return;
    }

    NoeudArticle* current = stock->first;
    while (current->next != NULL) {
        NoeudArticle* next = current->next;
        current = next;
    }
    current->next = new;

}


int chargerFichierStockL(const char* nomFichier, StockListe* stock) {
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
        Article article;
        sscanf(ligne, "%d,%99[^,],%d,%lf", &article.id, article.nom, &article.quantite, &article.prix);
        ajouterArticleStockL(stock, article);
    }

    fclose(fichier);
    return 0;
}

void afficherStockL(StockListe* stock) {
    NoeudArticle* current = stock->first;
    while (current->next != NULL) {
        printf("Article %d: %s, quantit\202: %d, prix: %.2f\n", current->article.id, current->article.nom, current->article.quantite, current->article.prix);
        current = current->next;
    }
}

