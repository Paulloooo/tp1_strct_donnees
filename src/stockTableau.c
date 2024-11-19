#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stockTableau.h"

void initStock(StockTableau* stock, int tailleMax) {
    stock->articles = (Article*)malloc(tailleMax * sizeof(Article));
    stock->nbArticles = 0;
    stock->tailleMax = tailleMax;
}

void libererMemoire(StockTableau* stock) {
    free(stock->articles);
    stock->articles = NULL;
    stock->nbArticles = 0;
    stock->tailleMax = 0;
}

void ajouterArticle(StockTableau* stock, Article article) {
    if (stock->nbArticles >= stock->tailleMax) {
        //incrémenter de 1
        //stock->tailleMax = stock->tailleMax + 1;

        //multiplier par 1.3 
        //stock->tailleMax = stock->tailleMax * 1.3;

        //multiplier par 2
        stock->tailleMax = stock->tailleMax * 2;
        stock->articles = (Article*)realloc(stock->articles, stock->tailleMax * sizeof(Article));
    }
    stock->articles[stock->nbArticles] = article;
    stock->nbArticles++;
}


int chargerFichier(const char* nomFichier, StockTableau* stock) {
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
        ajouterArticle(stock, article);
    }

    fclose(fichier);
    return 0;
}

void retirerArticle(int idArticle, StockTableau* stock) {

    if(idArticle > stock->tailleMax || idArticle < stock->tailleMax) {
        printf("L'identifiant entr\202 n'est pas dans le tableau\n");
        return;
    }

    for (int indiceArticle = 0; indiceArticle < stock->nbArticles; indiceArticle++){
        if(stock->articles[indiceArticle].id == idArticle){    
            for (int j = indiceArticle; j < stock->nbArticles - 1; j++) {
                stock->articles[j] = stock->articles[j + 1];
            }

            stock->nbArticles--;
            break;  
        }
    }
}

int quantiteEnStock(char* nomArticle, StockTableau* stock) {
    int quantiteEnStock = 0;
    for (int indiceArticle = 0; indiceArticle < stock->nbArticles; indiceArticle++){
        Article article = stock->articles[indiceArticle];
        if(!strcmp(article.nom, nomArticle)){
            quantiteEnStock = quantiteEnStock + article.quantite;
        }
    }
    return quantiteEnStock;
}

 void espacePerdu(StockTableau* stock){
    int quantiteStock = stock->tailleMax;
    int nbArticles = stock->nbArticles;

    int nbArticlesPerdus = quantiteStock - nbArticles;

    int tailleArticle = sizeof(Article);

    int taillePerdue = nbArticlesPerdus * tailleArticle;

    //convertir en Mo
    int taillePerdueMb = taillePerdue / 1000000;
    
    printf("Espace perdu : %d Mb\n", taillePerdue);

}

/* void fusionnerDoublons(StockTableau* stock){
    for (int indiceArticle = 0; indiceArticle < stock->nbArticles; indiceArticle++){
        int countOccurences = 0;
        retirerArticle(stock->articles[indiceArticle].id, &stock);
        char nomArticle =  stock->articles[indiceArticle].nom;
        for (int indiceArticle2 = 0; indiceArticle2 < stock->nbArticles; indiceArticle2++){
            if(stock->articles[indiceArticle2].nom == nomArticle){
                countOccurences = countOccurences + 1;
            }
        }
    }
} */