#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Palabra;

typedef struct nodo
{
    Palabra palabra;
    struct nodo* siguiente;
}Nodo;

typedef struct pila
{
    Nodo* cima;
    int longitud;
}Pila;

Nodo* crearNodo(Palabra palabra);
Pila* crearPila();
void destruirPila(Pila* pila);
void destruirNodo(Nodo* nodo);
void apilar(Pila* pila,Palabra palabra);
void desapilar(Pila* pila);
void muestra(Pila* pila);
Palabra cima(Pila* pila);
int longitud(Pila* pila);
int estaVacia(Pila* pila);
void verificarCapicua(Pila* pila, Palabra palabra[20]);


int main()
{
    Pila mipila;
    char *p1="amor a roma";
    int l=strlen(p1), i, y=0;
    char longi[l];

    crearPila(&mipila);

    ///**********************************************
    for(i=0;i<l;i++)
    {
        apilar(&mipila,p1[i]);
    }

    while(!estaVacia(&mipila)&&y!=l)
    {
        longi[y] = mipila.cima;
        desapilar(&mipila);
        y++;
    }

    if(strcmp(p1,longi)==0)
        printf("\nSI ES capicua\n");
    else
        printf("\nNO ES capicua\n");
    ///**********************************************
    return 0;
}

Nodo* crearNodo(Palabra palabra)
{
    Nodo* nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->palabra = palabra;
    nodo->siguiente = NULL;
    return nodo;
}

void verificarCapicua(Pila* pila, Palabra palabra[20])
{
    Nodo* aux;
    int i, tam;
    tam=strlen(palabra);

    for(i=0;i<tam;i++)
    {
        apilar(&pila,palabra[i]);
    }

    for(i=0;i<tam;i++)
    {
        aux = pila;
        if(palabra[i]==aux->palabra)
        {
            desapilar(pila);
        }
        else
        {
            printf("\nAqui\n");
            break;
        }
    }
    if(pila==NULL)
        printf("\nLa palabra es CAPICUA\n");
    else
        printf("\nLa palabra NO ES capicua\n");

}

Pila* crearPila()
{
    Pila* pila = (Pila *)malloc(sizeof(Pila));
    pila->cima = NULL;
    pila->longitud = 0;
    printf("\nSe creo una pila\n");
    return pila;
}

void destruirPila(Pila* pila)
{
    while(pila->cima != NULL){
        desapilar(pila);
    }
    free(pila);
}

void destruirNodo(Nodo* nodo)
{
    nodo->siguiente = NULL;
    free(nodo);
}

void apilar(Pila* pila, char* palabra)
{
    Nodo* nodo = crearNodo(palabra);
    nodo->siguiente = pila->cima;
    pila->cima = nodo;
    pila->longitud++;
    printf("\nSe apilo: %s\n", pila->cima);
}

void desapilar(Pila* pila)
{
    printf("\nSe desapilo: %s\n", pila->cima);
    if(pila->cima != NULL){
        Nodo* eliminar = pila->cima;
        pila->cima = pila->cima->siguiente;
        destruirNodo(eliminar);
        pila->longitud--;
    }
}

void muestra(Pila* pila)
{
    Nodo *actual;
    int i;
    actual = pila->cima;

    for(i=0;i<pila->longitud;++i)
    {
        printf("\t\t%s\n", actual->palabra);
        actual = actual->siguiente;
    }
}

Palabra cima(Pila* pila)
{
    if(pila->cima == NULL){
        return NULL;
    }
    else{
        return pila->cima->palabra;
    }
}

int longitud(Pila* pila)
{
    return pila->longitud;
}

int estaVacia(Pila* pila)
{
    return pila->longitud == 0;
}
