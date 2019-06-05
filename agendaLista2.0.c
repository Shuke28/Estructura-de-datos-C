#include <stdio.h>
#include <stdlib.h>

struct agenda
{
    char nombre[30];
    char telefono[12];
    char correo[30];
    struct agenda *siguiente;
};

struct agenda *primero, *ultimo;

void mostrar_menu();
void anadir_elemento();
void mostrar_lista();
void eliminar2(char dato[30]);
void eliminar(char entrada[30]);

int main()
{
    char opcion, dato[30];

    primero = (struct agenda *) NULL;
    ultimo = (struct agenda *) NULL;
    do
    {
        mostrar_menu();
        opcion = getch();
            switch ( opcion )
            {
                case '1':
                        system("cls");
                        anadir_elemento();
                        break;
                case '2':
                        system("cls");
                        printf("Que nombre quiere eliminar? ");
                        gets(dato);
                        eliminar2(dato);
                        break;
                case '3':
                        system("cls");
                        mostrar_lista(primero);
                        break;
                case '4':
                        exit( 1 );
                        default: printf( "Opci%cn no v%clida\n", 162, 160);
                        system("cls");
                        break;
             }
     }while (opcion!='4');
}

void mostrar_menu()
{
    printf("+-----------Men%c-----------+\n", 163);
    printf("|      1.- Ingresar        |\n");
    printf("|      2.- Eliminar        |\n");
    printf("|      3.- Mostrar         |\n");
    printf("|      4.- Salir           |\n");
    printf("+--------------------------+\n");
    printf("| Escoge una opci%cn: ",  162);
    fflush(stdout);
}

void mostrar_lista()
{
    struct agenda *auxiliar;
    int i;

    i=0;
    auxiliar = primero;
    printf("\n---- Mostrando la lista completa ----\n");
    while (auxiliar!=NULL)
    {
        printf( "Nombre: %s, Tel%cfono: %s, Correo: %s\n",
        auxiliar->nombre, 130,auxiliar->telefono,auxiliar->correo);
        auxiliar = auxiliar->siguiente;
        i++;
    }
    if (i==0) printf( "\nLa lista est%c vac%ca!!\n", 160, 161);
}

void anadir_elemento()
{
    struct agenda *nuevo;

    nuevo = (struct agenda *) malloc (sizeof(struct agenda));
    if (nuevo==NULL) printf( "No hay memoria disponible!\n");

    printf("\n---- Nuevo elemento ----\n");
    printf("Nombre: "); fflush(stdout);
    gets(nuevo->nombre);
    printf("Tel%cfono: ", 130); fflush(stdout);
    gets(nuevo->telefono);
    printf("Correo: "); fflush(stdout);
    gets(nuevo->correo);

    nuevo->siguiente = NULL;

    if (primero==NULL)
    {
        printf( "Primer elemento\n");
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}
/*
void eliminar(Nodo** cabeza, int entrada)
{
    Nodo* actual, *anterior;
    int encontrado=0;

    actual = *cabeza; anterior = NULL;
    while((actual != NULL) && (encontrado==0))
    {
        if(actual->dato.id == entrada)
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
}*/
void eliminar2(char dato[30])
{
    struct agenda* auxiliar, *cabeza, *anterior, *cadena;
    int i;

    i=0;
    anterior=NULL; cadena=dato;
    printf("\n---- Eliminando dato ----\n");
    while ( (auxiliar!=NULL) && (i==0) )
    {
        if(auxiliar->nombre == cadena)
        {
            printf("Hola");
            i=1;
        }
        else
        {
            anterior = auxiliar;
            anterior = auxiliar->siguiente;
        }
        printf("%s\t", auxiliar->nombre);
        printf("%s\n", anterior->nombre);
    }
    if(auxiliar != NULL)
    {
        if(auxiliar == cabeza)
        {
            cabeza = auxiliar->siguiente;
        }
        else
        {
            anterior->siguiente = auxiliar->siguiente;
        }
    }
    free(auxiliar);
    if (i==0) printf( "\nLa lista est%c vac%ca!!\n", 160, 161);
}
