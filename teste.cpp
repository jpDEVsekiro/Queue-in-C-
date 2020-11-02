#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
void insert(int nr, struct no *pqueue);
void exibir(struct no *pqueue);
void remove(struct no *pqueue);
struct no
{
    int info;
    struct no *prox;
};
struct no *queue = NULL;
struct no *ultimo;

main()
{
    system("cls");
    string res = "a";
    while (res != "s")
    {
        printf("digite i-inserir r-remover e-exibir s-sair:");
        cin >> res;
        if (res == "i" || res == "I")
        {
            printf("\ndigite valor:");
            int i;
            cin >> i;
            insert(i, queue);
            printf("\n");
        }
        else if (res == "r" || res == "R")
        {
            remove(queue);
            printf("\n");
        }
        else if (res == "e" || res == "E")
        {
            exibir(queue);
        }
    }
}

void insert(int nr, struct no *pqueue)
{
    struct no *novo;
    novo = (struct no *)malloc(sizeof(struct no));
    novo->info = nr;
    novo->prox = NULL;
    if (pqueue == NULL)
    {
        queue = novo;
    }
    else
    {
        ultimo->prox = novo;
    }
    ultimo = novo;
}
void exibir(struct no *pqueue)
{
    struct no *aux;
    aux = pqueue;
    if (aux != NULL)
    {
        system("cls");
        printf("\n");
        printf("ponteiro || valor \n");
        printf("----------------- \n");

        while (aux != NULL)
        {

            printf("[%x] || %d\n", aux, aux->info);
            aux = aux->prox;
        }
    }
    else
    {
        printf("A lista esta vazia\n");
    }
    printf("\n");
}
void remove(struct no *pqueue)
{
    struct no *aux;
    struct no *ant;
    if (pqueue != NULL)
    {
        aux = pqueue;
        queue = aux->prox;
        free(aux);
    }
    else
    {
        printf("Lista vazia\n");
    }
}
