typedef struct nodo_s {
    struct nodo_s* siguiente; // hay que definir struct nodo_s* ac´a porque el tipo nodo_t no est´a declarado.
    int valor;
} nodo_t;

typedef struct lista_s {
    nodo_t* cabeza;
} lista_t;

lista_t* crear_lista_vacia(){
    
}



// nodo_t* crear_nuevo_nodo(int valor){}
// void insertar_al_final(lista_t* lista, int valor) {}
// int eliminar_cabeza(lista_t* lista){}
// void eliminar_lista(lista_t* lista) {}
// void map(lista_t* lista, int (*operacion)(int)) {}
// void filter(lista_t* lista, int (*criterio)(int));
