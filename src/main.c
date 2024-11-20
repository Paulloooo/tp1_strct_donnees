#include <stdio.h>
#include "article.h"
#include <string.h>
#include "utils.h"
#include "stockTableau.h"
#include "stockListe.h"
#include <stdlib.h>
#include <time.h>


int main() {
    //création de l'article dans la pile
/*     Article article1;

    //création de l'article dans le tas
    Article* article2 = (Article*)malloc(sizeof(Article));

    chargerArticles("2articles.csv", &article1, article2);

    printf("Article 1 : %s, %d, %f, %d\n", article1.nom, article1.id, article1.prix, article1.quantite);
    printf("Article 2 : %s, %d, %f, %d\n", article2->nom, article2->id, article2->prix, article2->quantite);

    free(article2);
    return 0; */

    //partie des stockTableau
/*     StockTableau stock;
    int tailleMax = 10;

    initStock(&stock, tailleMax);
    chargerFichier("100000articles.csv", &stock);
    espacePerdu(&stock); */
/*     clock_t begin = clock();
    clock_t end = clock();
    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis ); */  

    //afficherStockTableau(&stock);

    //retirerArticle(156, &stock);
    //retirerArticle(-1300, &stock);
    //retirerArticle(2, &stock);
    //afficherStockTableau(&stock);

    //int quantite = quantiteEnStock("Premium Huile d\'olive", &stock);
    //printf("Quantit\202 en stock de l'article Premium Huile d\'olive : %d", quantite);

    StockListe stock;
    initStockL(&stock);
    chargerFichierStockL("10articles.csv", &stock);
    afficherStockL(&stock);
    libererMemoireStockL(&stock);
    
    return 0;
}
