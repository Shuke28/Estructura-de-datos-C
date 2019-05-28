#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int dato;
	struct nodo *izdo, *dcho;
};

typedef struct nodo Nodo;

Nodo* crearNodo(int dato);
void insertar(Nodo** raiz, int dato);
void eliminar(Nodo** raiz, int dato);
void reemplazar(Nodo** intermedio);
void buscar(Nodo** raiz, int dato);
/*Tipos de recorrido*/
void preorden(Nodo* raiz);
void posorden(Nodo* raiz);
void enorden(Nodo* raiz);

main(){
	int nd, nd2;
	int opcion=0;
	Nodo* raiz = NULL;
	do{
		printf("Ingrese un dato al arbol: ");
		scanf("%d",&nd);
		insertar(&raiz,nd);
		opcion++;
	}while(opcion != 10);
	preorden(raiz);
	printf("\nQue numero deseas eliminar? ");
	scanf("%d", &nd2);
	eliminar(&raiz,nd2);
	preorden(raiz);
	printf("\nQue numero deseas buscar? ");
	scanf("%d", &nd2);
	buscar(&raiz,nd2);
    printf("\nLa profundidad es de: %d", profundidad(raiz));

}

Nodo* crearNodo(int dato){
	Nodo* h;
	h = (Nodo*)malloc(sizeof(Nodo));
	h->dato = dato;
	h->izdo= NULL;
	h->dcho = NULL;
	return h;
}

void insertar(Nodo** raiz, int dato){
	if(!(*raiz))
		*raiz = crearNodo(dato);
	else if(dato < (*raiz)->dato)
		insertar(&(*raiz)->izdo,dato);
	else
		insertar(&(*raiz)->dcho,dato);
}

void eliminar(Nodo** raiz, int dato){
	if(!(*raiz)){
		printf("El nodo no se encuentra");
	}
	else if(dato < (*raiz)->dato){
		eliminar(&(*raiz)->izdo,dato);
	}
	else if(dato > (*raiz)->dato){
		eliminar(&(*raiz)->dcho,dato);
	}
	else{
		Nodo* h;
		h  = (*raiz);
		if(h->izdo == NULL){
			(*raiz) = h->dcho;
		}
		else if(h->dcho == NULL){
			(*raiz) = h->dcho;
		}
		else{
			reemplazar(&h);
		}
		free(h);
	}
}

void reemplazar(Nodo** intermedio){
	Nodo *a, *p;
	p = *intermedio;
	a = (*intermedio)->izdo;
	while(a->dcho){
		p=a;
		a=a->dcho;
	}
	(*intermedio)-> dato = a ->dato;
	if(p == (*intermedio)){
		p->izdo = a-> izdo;
	}
	else{
		p->dcho = a->dcho;
	}
	(*intermedio) = a;
}

void buscar(Nodo** raiz, int dato){
	if(!(*raiz)){
		printf("El nodo NO se encuentra");
	}
	else if(dato < (*raiz)->dato){
		buscar(&(*raiz)->izdo,dato);
	}
	else if(dato > (*raiz)->dato){
		buscar(&(*raiz)->dcho,dato);
	}
	else{
        printf("El nodo SI se encontro");
	}
}

int profundidad(Nodo* raiz){
    if(!raiz)
        return 0;
    else{
        int profundidadI=profundidad(raiz->izdo);
        int profundidadD=profundidad(raiz->dcho);
        if(profundidadI>profundidadD)
            return profundidadI+1;
        else
            return profundidadD+1;
    }
}

void preorden(Nodo* raiz){
	if(raiz){
		printf("%d ",raiz->dato);
		preorden(raiz->izdo);
		preorden(raiz->dcho);
	}
}

void posorden(Nodo* raiz){
	if(raiz){
		posorden(raiz->izdo);
		posorden(raiz->dcho);
		printf("%d ",raiz->dato);
	}
}

void enorden(Nodo* raiz){
	if(raiz){
		posorden(raiz->izdo);
		printf("%d ",raiz->dato);
		posorden(raiz->dcho);
	}
}
