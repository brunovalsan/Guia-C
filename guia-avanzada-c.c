#define LEN_ARR_MONSTRUOS 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// typedef struct {
//     char* nombre;
//     int vida;
//     double ataque;
//     double defensa;
// } monstruo_t;

// monstruo_t array_de_monstruos[] = {
//     {"mick wasaski", 10, 0, 2},
//     {"solly", 10, 1000, 5},
//     {"minotauro",11, 100, 100}
// };

// monstruo_t evolution(monstruo_t monstruo){
//     monstruo_t monstruo_nuevo = monstruo;
//     monstruo_nuevo.ataque += 10;
//     monstruo_nuevo.defensa += 10;
//     return monstruo_nuevo;
// }
// typedef struct{
//         char* nombre;
//         int edad;
//     } persona_t;

// persona_t* crearPersona(char* nombre, int edad){
//         // void* malloc(size_t size);
//         // este malloc reserva memoria para el puntero al nombre y para la edad
//         // este malloc NO reserva memoria para el nombre, sino que reserva memoria para el PUNTERO AL NOMBRE
//         persona_t* persona = malloc(sixeof(persona_t)); // malloc(sizeof(nombre)+ sizeof(int));
        
//         // persona->nombre = nombre // cuando es un puntero se usa ->, no persona.nombre = nombre;
//         //  Esto es equivalente a (*puntero).atributo
//         // reservamos espacio dependiendo la longitud del nombre!!!
//         persona->nombre = malloc(strlen(nombre) + 1); // +1 por '\0'

//         // para hacer una copia del string usamos lo visto de strings
//         strcpy(persona->nombre, nombre);
//         persona->edad = edad // cuando es un puntero se usa ->, no persona.edad = edad; Esto es equivalente a (*puntero).atributo
        
//         return persona;
//     }

// persona_t* persona_creada = crearPersona("bruno", 21);
//     // void free(void* ptr);

// void eliminarPersona(persona_t* persona){
//         free(persona_creada);
//         free(persona);
//     }

// Ejercicio 18
    // void allocateArray(int *arr, int size, int value) { 
    //     // Recibimos un puntero a un array, el lenght y un valor
    //     arr = (int*)malloc(size * sizeof(int)); 
    //     // El puntero al array recibido le asignamos otra direccion, reservando lugar para todo el array 
    //     if(arr != NULL) { // Manejo error
    //         for(int i=0; i<size; i++) { arr[i] = value; } // pongo el valor recibido en cada pos del array
    //     }
    // }

int main() {
    // Ejercicio 1
    
    // for(int i=0; i < LEN_ARR_MONSTRUOS; i++){
    //     printf("Monstruo numero %d : \n Se llama %s \n Su vida es de %d \n Su ataque es de %lf \n Su defensa es de %lf \n \n \n", i+1, array_de_monstruos[i].nombre, array_de_monstruos[i].vida, array_de_monstruos[i].ataque, array_de_monstruos[i].defensa);
    // }

    // Ejercicio 2
    // printf("Antes de evolucionar a %s , su ataque es de %lf y su defensa es de %lf \n \n", array_de_monstruos[0].nombre, array_de_monstruos[0].ataque, array_de_monstruos[0].defensa);
    // monstruo_t monstruo_evolucionado = evolution(array_de_monstruos[0]);
    // printf("Luego de su evolucion, %s mejoro su ataque a %lf y su defensa a %lf \n \n", monstruo_evolucionado.nombre, monstruo_evolucionado.ataque, monstruo_evolucionado.defensa);

    // Ejercicio 3
    // int x = 42;
    // int *p = &x;
    // printf("Direccion de x: %p Valor: %d\n", (void*) &x, x);
    // printf("Direccion de p: %p Valor: %p\n", (void*) &p, (void*) p);
    // printf("Valor de lo que apunta p: %d\n", *p);
    
    // Ejercicio 9 
    // char word[100]; // mal --> char[100] word;
    // int diferencia = 'A' - 'a';
    // printf("Ingrese una palabra: \n");
    // scanf("%s", word);
    // int i = 0;
    // while(word[i] != '\0'){
    //     if (word[i] >= 'a' && word[i] <= 'z'){
    //         word[i] = word[i] + diferencia;
    //     }
    // i++;
    // }
    // printf("Tu palabra en mayusculas es: %s \n", word);
    // return 0;
 
    

    // Uso de ej 18
    // int *vector = NULL;
    // allocateArray(vector,5,45); 
    // for(int i = 0; i < 5; i++)
    //     printf("%d\n", vector[i]);
    // free(vector);
    
    // return 0;

    // Ejercicio 19
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    // p apunta al int en la fila 0, columna 0
    int *p = &matrix[0][0];

    // Reinterpretamos a la matriz como bloques de 2, sin perder informacion --> reshape = {{1,2},{3,4}, ..., {11,12}};
    int (*reshape)[2] = (int (*)[2]) p;

    printf("%d\n", p[3]); // Qu´e imprime esta l´ınea?
    printf("%d\n", reshape[1][1]); // Qu´e imprime esta l´ınea? 
    return 0;



}