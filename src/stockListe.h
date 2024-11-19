#ifndef STOCKLISTE_H
#define STOCKLISTE_H

void initStock(StockListe* stock);
void libererMemoire(StockListe* stock);

void ajouterArticle(StockListe* stock, Article article);

int chargerFichier(const char* fichier, StockListe* stock);

#endif