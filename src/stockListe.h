#include "article.h"

#ifndef STOCKLISTE_H
#define STOCKLISTE_H

typedef struct NoeudArticle
{
    struct NoeudArticle* next;
    Article article;
} NoeudArticle;

typedef struct StockListe
{
    NoeudArticle* first;
} StockListe;

void initStockL(StockListe* stock);
void libererMemoireStockL(StockListe* stock);

void ajouterArticleStockL(StockListe* stock, Article article);

int chargerFichierStockL(const char* fichier, StockListe* stock);

void afficherStockL(StockListe* stock);
#endif