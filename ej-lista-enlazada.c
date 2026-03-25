#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node {
    void* data;
    struct node* next;
} node_t;

typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
} list_t;

// type.h
typedef enum e_type {
    TypeFAT32 = 0,
    TypeEXT4 = 1,
    TypeNTFS = 2
} type_t;


list_t* listNew(type_t t){
    list_t* l = malloc(sizeof(list_t));
    l->type = t;
    l->size = 0;
    l->first = NULL;
    return l;
}

void listAddFirst(list_t* l, void* data){// copia el dato
    node_t* n = malloc(sizeof(node_t));

    switch(l->type) {
        case TypeFAT32:
        // como tratamos archivos no pasamos el puntero al archivo,
        // sino que hacemos una copia del mismo. Lo casteamos a (void *)
        // pero no es necesario (consultar)
        // analogo para los otros case
        // tabien casteamos a data
            n->data = (void*) copy_fat32((fat32_t*) data);
            break;
        case TypeEXT4:
            n->data = (void*) copy_ext4((ext4_t*) data);
            break;
        case TypeNTFS:
            n->data = n->data = (void*) copy_ntfs((ntfs_t*) data);
            break;
    }
    n->next = l->first;
    l->first = n;
    l->size++;
    
} 

void* listGet(list_t* l, uint8_t i){ // se asume: i < l->size
    node_t *n = l->first;
    for(int k = 0; k < i, k++){ n = n->next; }
    return n->data;
}      

void* listRemove(list_t* l, uint8_t i){ // se asume: i < l->size
    node_t* tmp = NULL; // declaramos antes de entrar al if para directamente definirlas luego
    void* data = NULL; // usamos data porque debemos retornar la data del nodo eliminado
    if(i == 0){ 
        data = l->first->data;
        tmp = l->first;
        l->first = l->first->next;
    } else{
        node_t* n = l->first; // asi como en listDelete al usar un tmp usamos n para el actual
        for(int k = 0; k < i-1, k++){ // analizar los indices  
            n = n->next // avanzamos
        } // aca ya estamos en el nodo anterior a eliminar

        data = n->next->data; // data del nodo a borrar
        tmp = n->next; // guardas el nodo a borrar para el free
        n->next = n->next->next; // saltea el nodo de la lista enlazada
    }
    
    free(tmp);
    l->size--;
    return data;
}

void listDelete(list_t* l){
    node_t *n = l->first; // en vez de usar anterior y actual hacemos lo siguiente
    while(n != NULL){
        node_t* temporal = n; // el primer nodo lo guardamos en "temporal" y ya trabajamos con este, asi n lo redefinimos para la proxima iteracion
        n = n->next
        switch(l->type) {
            case TypeFAT32:
                rm_fat32((fat32_t*) temporal->data);
                break;
            case TypeEXT4:
                rm_ext4((ext4_t*) temporal->data);
                break;
            case TypeNTFS:
                rm_ntfs((ntfs_t*) temporal->data);
                break;
        }   
        free(temporal);
    }
    free(l);
}

// Ejercicio 14: ---------------------------------------------------------------------------------------------------------------------------
// Implementen el ejemplo anterior, implementando funciones dummy para new , copy y rm
// .Pueden por ejemplo hacer usar typedef uint32 t fat23 t para definir el tipo de dato
// fat32 t. Luego, en las funciones new y copy reservar y asignar un valor a la variable.
// En la funci´on rm simplemente liberar la memoria.

// los demas tipos es analogo
typedef uint32_t fat32_t;

fat32_t* new_fat32(){
    fat32_t* d = malloc(sizeof(fat32_t));
    *d = 0; // inicializamos con algún valor (ej: 0) CONSULTAR SI ES NECESARIO
    return d;
}
// ext4_t* new_ext4();
// ntfs_t* new_ntfs();

fat32_t* copy_fat32(fat32_t* file){
    fat32_t* d = malloc(sizeof(fat32_t));
    // d = file --> mal: aca hago que ambos apunten al mismo lugar, no sirve
    *d = *file; // copiamos el CONTENIDO, no la dirección
    return d;
}
// ext4_t* copy_ext4(ext4_t* file);
// ntfs_t* copy_ntfs(ntfs_t* file);

void rm_fat32(fat32_t* file){free(file);}
// void rm_ext4(ext4_t* file);
// void rm_ntfs(ntfs_t* file);

// Ejercicio 15: -------------------------------------------------------------------------------------------------------------------
// Agregar una funci´on a la lista que permita intercambiar el orden de dos nodos. Para esto,
// se debe tener en cuenta que la lista puede estar vac´ıa o tener un solo nodo. En caso de
// que la lista tenga un solo nodo o est´e vac´ıa, no se debe hacer nada.

list_t* intercambiarOrdenNodos(list_t* l, uint8_t i, uint8_t j){

    if (!l || i == j || l->first == NULL || l->first->next == NULL){return l;}

    // Aseguramos i < j para simplificar casos
    if (i > j) {
        uint8_t tmp = i;
        i = j;
        j = tmp;
    }
    
    node_t *prev_i = NULL;
    node_t *nodo_i = NULL;
    node_t *prev_j = NULL;
    node_t *nodo_j = NULL;

    node_t *actual = l->first;
    node_t *temporal = NULL;

    uint8_t maximo = (i > j) ? i : j;
    
    if (cantNodos(l) > 1){
        // Preservar el nodo i, el nodo j, y sus respectivos nodos anteriores (prev_i y prev_j),
        // uso while luego comparo si usar for es mas optimo
        
        uint8_t contador = 0;

        // aca solo voy a buscar nodo i, el nodo j, y sus respectivos nodos anteriores (prev_i y prev_j)
        while(contador <= maximo && actual != NULL){

            if(contador == i){ // aca actual es el nodo i y temp es el nodo prev_i
                prev_i = temporal;
                nodo_i = actual;
            }
            
            if(contador == j){
                prev_j = temporal;
                nodo_j = actual;
             } // analogo de lo que hago para i
            
            temporal = actual;
            actual = actual->next;
            contador++;
        }
    }
    
    if (!nodo_i || !nodo_j){return l;}// ⚠️ Validación por si índices inválidos

    // 🧠 CASO: nodos consecutivos (i antes que j)
    if (nodo_i->next == nodo_j) {

        if (prev_i){ prev_i->next = nodo_j; }
        else{ l->first = nodo_j; }

        nodo_i->next = nodo_j->next;
        nodo_j->next = nodo_i;

        return l;
    }

    // 🧠 CASO GENERAL

    // guardar nexts ANTES de pisarlos
    node_t *next_i = nodo_i->next;
    node_t *next_j = nodo_j->next;

    // reconectar previos
    if (prev_i){ prev_i->next = nodo_j; }
    else{ l->first = nodo_j; }

    if (prev_j){prev_j->next = nodo_i;}

    // intercambiar nexts
    nodo_j->next = next_i;
    nodo_i->next = next_j;

    return l;
}

// Ejercicio 21 ------------------------------------------------------------------------------------------------------------------

typedef void* (*funcCopy_t)(void*);
typedef void (*funcRm_t)(void*);

funcCopy_t getCopyFunction(type_t t){
     switch(t) {
         case TypeFAT32:
            return copy_fat32();
         case TypeEXT4:
            return copy_ext4();
         case TypeNTFS:
            return copy_ntfs();
     }
}

void listDeleteConPunterosAFuncion(list_t* l){
    // funcRm_t funcRm = getRmFunction(l->type);
    node_t* n = l->first;
    while(n){
        node_t* temporal = n; 
        n = n->next;
        // funcRm(n->data); 
        getRmFunction(l->type)(tmp->data);
        free(temporal);
    }
    free(l);
}

funcRm_t getRmFunction(type_t t){
    switch(t) {
         case TypeFAT32:
            return rm_fat32();
         case TypeEXT4:
            return rm_ext4();
         case TypeNTFS:
            return rm_ntfs();
    }
}

void listAddFirstConPunterosAFuncion(list_t* l, void* data){ // mejoramos listAddFirst usando punteros a funcion
    node_t* n = malloc(sizeof(node_t));
    // funcCopy_t funcCopy = getCopyFunction(l->type);
    // n->data = funcCopy(data);
    n->data = getCopyFunction(l->type)(data);
    n->next = l->first;
    l->first = n;
    l->size++;  
}

// typedef void* (*funcNew_t)();
// typedef void (*funcRm_t)(void*);
// getNewFunction(){}

int main(){
    // list_t* l = listNew(TypeFAT32);
    // fat32_t* f1 = new_fat32();
    // fat32_t* f2 = new_fat32();
    // listAddFirst(l, f1);
    // listAddFirst(l, f2);
    // listDelete(l);
    // rm_fat32(f1);
    // rm_fat32(f2);
    return 0;
}



