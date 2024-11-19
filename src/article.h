#ifndef ARTICLE_H
#define ARTICLE_H

typedef struct Article {
    int id;
    char nom[100];
    int quantite;
    double prix;
} Article;

#endif
