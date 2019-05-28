#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    int dato;
    struct Elemento* siguiente;
}Nodo;

void insertarPrimero(Nodo** cabeza, int entrada);
void insertarUltimo(Nodo** cabeza, int x);
void insertar(Nodo** cabeza, int testigo, int entrada);
void eliminar(Nodo** cabeza, int entrada);
void localizar(Nodo** cabeza, int testigo);
Nodo* crearNodo(int x);

int main()
{
    int d=1;
    Nodo *cabeza, *par, *impar, *ptr;

    cabeza = par = impar = NULL;
    while(d != 0)
    {
        printf("Dame un valor diferente de 0: ");
        scanf("%d", &d);
        if(d>0)
        {
            insertar(&cabeza,100,d);
        }
    }
    for(ptr = cabeza; ptr;)
    {
        printf(" '%d' ", ptr->dato);
        ptr = ptr->siguiente;
    }
    for(ptr=cabeza;ptr;)
    {
        if(ptr->dato%2==0)
        {
            insertar(&par,100,ptr->dato);
        }
        else
        {
            insertar(&impar,100,ptr->dato);
        }
        ptr = ptr->siguiente;
    }
    printf("\nP A R E S\n");
    for(ptr = par; ptr;)
    {
        printf(" '%d' ", ptr->dato);
        ptr = ptr->siguiente;
    }printf("\nI M P A R E S\n");
    for(ptr = impar; ptr;)
    {
        printf(" '%d' ", ptr->dato);
        ptr = ptr->siguiente;
    }

    return 0;
}

void insertarPrimero(Nodo** cabeza, int entrada)
{
    Nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void insertarUltimo(Nodo** cabeza, int x)
{
    Nodo *ultimo;
    ultimo = *cabeza;
    if(ultimo == NULL)
    {
        *cabeza = crearNodo(x);
    }
    else
    {
        while(ultimo->siguiente)
        {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = crearNodo(x);
    }

}

void insertar(Nodo** cabeza, int testigo, int entrada)
{
    Nodo *nuevo, *despues, *p;

    nuevo = crearNodo(entrada);

    if(*cabeza == NULL)
    {
        *cabeza = nuevo;
    }
    else if(entrada < (*cabeza)->dato)
    {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
    }
    else
    {
        int encontrado = 0;
        despues = p = *cabeza;
        while((despues != NULL) && encontrado == 0)
        {
            if(despues->dato > testigo)
            {
                despues = despues->siguiente;
            }
            else
            {
                encontrado = 1;
            }
        }
        if(encontrado == 1)
        {
            nuevo->siguiente = despues->siguiente;
            despues->siguiente = nuevo;
        }
        else ///Si no existe lo inserta al inicio de la lista
        {
            insertarPrimero(nuevo,entrada);
        }
    }

}

void eliminar(Nodo** cabeza, int entrada)
{
    Nodo* actual, *anterior;
    int encontrado=0;

    actual = *cabeza; anterior = NULL;
    while((actual != NULL) && (encontrado==0))
    {
        if(actual->dato == entrada)
        {
            encontrado = 1;
        }
        if(!encontrado)
        {
            anterior = actual;
            actual = actual->siguiente;
        }
        //printf("%d\t", actual->dato);
        //printf("%d\n", anterior->dato);
    }
    if(actual != NULL)
    {
        if(actual == *cabeza)
        {
            *cabeza = actual->siguiente;
        }
        else
        {
            anterior->siguiente = actual->siguiente;
        }
    }
    free(actual);
}

void localizar(Nodo** cabeza, int testigo)
{
    Nodo *nuevo, *despues;

    int encontrado = 0;
    despues = *cabeza;
    while((despues != NULL) && encontrado == 0)
    {
        if(despues->dato != testigo)
        {
            printf("El numero SI se localizo.\n");
            break;
        }
        else
        {
            printf("El numero NO se localizo.\n");
            break;
        }
        despues = despues->siguiente;
    }
}

Nodo* crearNodo(int x)
{
    Nodo *p;
    p=(Nodo*)malloc(sizeof(Nodo));
    p->dato=x;
    p->siguiente=NULL;
    return p;
}
