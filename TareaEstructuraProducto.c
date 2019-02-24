#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

struct fecha
{
    unsigned int dia, mes, anio;
};

struct tiempo
{
     unsigned int horas, minutos, segundos;
};

struct inventario
{
    char nombre[15];
    char compania[15];
    int anio;
    int existencia;
    struct fecha f;
    struct tiempo t;
    float precio;
};
struct inventario carros[10];
int total = 0, opcion;

void menu()
{
    printf("\n+-------------------------------------------+");
    printf("\n|----- C A T %c L O G O  D E  A U T O S -----|", 143);
    printf("\n+-------------------------------------------+");
    printf("\n|          %cQue desea hacer?                |", 168);
    printf("\n|-------------------------------------------|");
    printf("\n|             1 - Registro.                 |");
    printf("\n|             2 - Visualizar cat%clogo.      |", 160);
    printf("\n|             3 - Salir.                    |");
    printf("\n+-------------------------------------------+\n");
    scanf("%d",&opcion);
    fflush(stdin);
}

void registro()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("\n+-------------------------------------------+");
    printf("\n|------------- R E G I S T R O -------------|");
    printf("\n+-------------------------------------------+");
    printf("\n|%cCu%cl es el nombre del carro?: ", 168, 160);
    gets(carros[total].nombre);
    printf("\n|%cCu%cl es la compa%cia?: ", 168, 160, 164);
    gets(carros[total].compania);
    printf("\n|%cCu%cl es el a%co?: ", 168, 160, 164);
    scanf("%d",&carros[total].anio);
    fflush(stdin);
    printf("\n|%cCantidad en stock?: ", 168);
    scanf("%d",&carros[total].existencia);
    fflush(stdin);
    printf("\n|%cCu%cl es el precio?: ", 168, 160);
    scanf("%f",&carros[total].precio);
    fflush(stdin);
    carros[total].f.anio = tm.tm_year+1900;
    carros[total].f.mes = tm.tm_mon + 1;
    carros[total].f.dia = tm.tm_mday;
    carros[total].t.horas = tm.tm_hour;
    carros[total].t.minutos = tm.tm_min;
    carros[total].t.segundos = tm.tm_sec;
    total++;
}

void visualizar()
{   int i;
    for(i=0;i<total;i++)
    {
        printf("\n+-------------------------------------------+");
        printf("\n|---------------- A U T O %d ----------------|", i+1);
        printf("\n+-------------------------------------------+");
        printf("\n|   Nombre: %s", carros[i].nombre);
        printf("\n|   Compa%cia: %s", 164, carros[i].compania);
        printf("\n|   A%co: %d", 164, carros[i].anio);
        printf("\n|   En stock: %d", carros[i].existencia);
        printf("\n|   Precio: %.2f", carros[i].precio);
        printf("\n|   Fecha de registro: %d-%d-%d",carros[i].f.dia, carros[i].f.mes, carros[i].f.anio);
        printf("\n|   Tiempo de registro: %d:%d:%d",carros[i].t.horas, carros[i].t.minutos, carros[i].t.segundos);
        printf("\n+-------------------------------------------+\n");
    }
}

int main()
{
    char respuesta;

    do
    {
        menu();
        switch(opcion)
        {
            case 1 : registro();
                break;
            case 2 : visualizar();
                break;
            case 3 : respuesta='N';
                break;
        }

        if(opcion == 1 || opcion == 2)
        {
            printf("\n+-------------------------------------------+");
            printf("\n|     %cQuiere hacer algo mas? (S/N):       |", 168);
            printf("\n+-------------------------------------------+");
            scanf("%c",&respuesta);
            fflush(stdin);
            respuesta = toupper(respuesta);
        }

    }while(respuesta == 'S');

    return 0;
}
