#include "article.h"

#ifndef STOCKTABLEAU_H
#define STOCKTABLEAU_H

typedef struct StockTableau
{
    Article* articles;
    int nbArticles;
    int tailleMax;
   
} StockTableau;

void initStock(StockTableau* stock, int tailleMax);
void libererMemoire(StockTableau* stock);

void ajouterArticle(StockTableau* stock, Article article);
void retirerArticle(int idArticle, StockTableau* stock);

int quantiteEnStock(char* nomArticle, StockTableau* stock);

int chargerFichier(const char* nomFichier, StockTableau* stock);

void espacePerdu(StockTableau* stock);

#endif