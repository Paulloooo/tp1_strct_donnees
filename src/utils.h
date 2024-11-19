#ifndef UTILS_H
#define UTILS_H

#include "article.h"
#include "stockTableau.h"

int chargerArticles(const char * fichier, Article * article1, Article * article2);
void afficherStockTableau(StockTableau * stock);
#endif