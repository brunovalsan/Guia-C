#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo_s {
    struct nodo_s* siguiente; // hay que definir struct nodo_s* aca porque el tipo nodo_t no esta declarado.
    int valor;
} nodo_t;

typedef struct lista_s {
    nodo_t* cabeza;
} lista_t;

// criterio: deja solo pares
int es_par(int x) {
    if (x % 2 == 0)
        return 1;
    else
        return 0;
}

lista_t* crear_lista_vacia(){
    lista_t *nueva_lista = malloc(sizeof(lista_t));
    nueva_lista->cabeza = NULL;
    return nueva_lista;
}

nodo_t* crear_nuevo_nodo(int valor){
    nodo_t* nuevo_nodo = malloc(sizeof(nodo_t));
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->valor = valor;
    return nuevo_nodo;
}

void insertar_al_final(lista_t* lista, int valor) {
    nodo_t* nuevo_nodo = crear_nuevo_nodo(valor);
    nodo_t* actual = lista->cabeza;
    if (actual == NULL) { 
        lista->cabeza = nuevo_nodo;
        return;
    }
    while(actual->siguiente != NULL){ actual = actual->siguiente;}
    actual->siguiente = nuevo_nodo;
}

int eliminar_cabeza(lista_t* lista){ // Retorna 0 si pudo borrar la cabeza de la lista y retorna -1 si la lista ya estaba vac´ıa:
    if (lista->cabeza == NULL){return -1;}
    nodo_t* actual = lista->cabeza;
    lista->cabeza = actual->siguiente;
    free(actual);
    return 0;
}

// función para imprimir la lista
void imprimir_lista(lista_t* lista){
    nodo_t* actual = lista->cabeza;
    while(actual != NULL){
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void eliminar_lista(lista_t* lista) {
    nodo_t* actual = lista->cabeza;
    while(actual != NULL){
        nodo_t* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

void map(lista_t* lista, int (*operacion)(int)) {
    nodo_t* actual = lista->cabeza;
    while(actual != NULL){
        actual->valor = operacion(actual->valor);
        actual = actual->siguiente;
    }
}

void filter(lista_t* lista, int (*criterio)(int)){
    nodo_t* anterior = lista->cabeza;
    nodo_t* actual = anterior->siguiente;

    while(!criterio(anterior->valor)){
        eliminar_cabeza(lista);
        anterior = actual;
        actual = actual->siguiente;
    }

    while(actual != NULL){
        if(criterio(actual->valor)){ 
            anterior = actual;
            actual = actual-> siguiente;
        } else {
            // aca eliminas el actual si no cumple el criterio
            anterior->siguiente = actual->siguiente; 
            // aca avanzamos al nodo siguiente: el nodo anterior sigue siendo su anterior y el nodo actual es el siguiente al actual
            actual = actual->siguiente;
        }
    }
}

// helper para agregar nodos al inicio (simple para testear)
void agregar(lista_t* lista, int valor){
    nodo_t* nuevo = malloc(sizeof(nodo_t));
    nuevo->valor = valor;
    nuevo->siguiente = lista->cabeza;
    lista->cabeza = nuevo;
}

int main(){
    lista_t lista;
    lista.cabeza = NULL;

    // armamos: 5 -> 4 -> 3 -> 2 -> 1
    agregar(&lista, 1);
    agregar(&lista, 2);
    agregar(&lista, 3);
    agregar(&lista, 4);
    agregar(&lista, 5);

    printf("Lista original:\n");
    imprimir_lista(&lista);

    filter(&lista, es_par);

    printf("Lista filtrada (solo pares):\n");
    imprimir_lista(&lista);

    return 0;
}



