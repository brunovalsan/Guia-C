#include <stdio.h>
#include <stdlib.h>

int a = 1;

int funcion(){
    int a = 2;
    printf("%d \n",a);
    return 0;
}

int factorial(int num){
    int res = 1;
    while(num != 0){
        res = res * num;
        num--;
    }
    return res;
}


int main() {
    // ej 1
    // printf("Hola Orga!\n");

    // ej 3
    // char c = 100;
    // short s = -8712;
    // int i = 123456;
    // long l = 1234567890;
    
    // long long ll = 1234567890123;
    // float f = 3.14;
    // double d = 3.141592;
    // long double ld = 3.1415926535;
    // // printf("long(%ld): %ld\n", sizeof(l), l);

    // // printf("char(%lu): %d \n", sizeof(c),c);
    // // printf("short(%lu): %d \n", sizeof(s),s);
    // // printf("int(%lu): %d \n", sizeof(i),i);
    // // printf("long(%lu): %ld \n", sizeof(l),l);
    
    // // printf("long long (%lu): %lld\n", sizeof(ll), ll);
    // // printf("float (%lu): %f\n", sizeof(f), f);
    // // printf("double (%lu): %f\n", sizeof(d), d);
    // // printf("long double (%lu): %Lf\n", sizeof(ld), ld);

    // // ejercicio 5
    // float flo = 0.1;
    // double dou = 0.1;

    // // printf("0.1 como float es (%f) y como double es (%lf)", flo, dou);

    // int i1 = (int) flo;
    // int i2 = (int) dou;

    // // printf("Este es el float castea a int (%d), y este el double casteado a int (%d)", i1, i2);
    

    // // ejercicio 6

    // int mensaje_secreto[] = {116, 104, 101, 32, 103, 105, 102, 116, 32, 111,
    // 102, 32, 119, 111, 114, 100, 115, 32, 105, 115, 32, 116, 104, 101, 32,
    // 103, 105, 102, 116, 32, 111, 102, 32, 100, 101, 99, 101, 112, 116, 105,
    // 111, 110, 32, 97, 110, 100, 32, 105, 108, 108, 117, 115, 105, 111, 110};
    
    // size_t length = sizeof(mensaje_secreto) / sizeof(int);
    // char decoded[length];
    
    // for (int i = 0; i < length; i++) {
    //     decoded[i] = (char) (mensaje_secreto[i]); // casting de int a char
    // }
    
    // for (int i = 0; i < length; i++) {
    //     printf("%c", decoded[i]);
    // }

    // // ejercicio 7
    // int a = 5;
    // int b = 3;
    // int c = 2;
    // int d = 1;

    // int r1 = a + b * c / d;
    // int r2 = a % b;
    // int r3 = a == b;
    // int r4 =  a != b;
    // int r5a = a & b;
    // int r5b = a | b;
    // int r6 = ~a;
    // int r7a = a && b;
    // int r7b = a || b;
    // int r8 = a << 1;
    // int r9 = a >> 1;
    // int r10 = a += b;
    // int r11 = a -= b;
    // int r12 = a *= b;
    // int r13 = a /= b;
    // int r14 = a %= b;

    // printf("las rta en orden del ejercicio 7 son:\n %d \n %d \n %d \n %d \n %x \n %x \n %x \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d",r1,r2,r3,r4,r5a, r5b,r6,r7a, r7b,r8,r9,r10, r11, r12, r13, r14);

    // ejercicio 8
    // int i = 0; 
    // int a = ++i; // incremento i => asigno a := i => a := 1
    // i--;         // restauramos i = 0
    // int b = i++; // asigno a := i => a := 0 => incremento i
    // i--;         // restauramos i = 0

    // printf("i vale %d, \n 
    //     al hacer a = ++i primero se incrementa el i y luego se le asigna ese valor a la a, 
    //     entonces a vale %d, \n 
    //     al hacer b = i++ primero asignamos el valor de i al b y luego se incrementa i, 
    //     por eso b vale %d",i,a,b);

    // ejercicio 9
    //     Realizar un programa que compare si los 3 bits m´as altos de una palabra de 32 bits son
    // iguales a los 3 bits m´as bajos de otra palabra de 32 bits. Si son iguales, informarlo por
    // pantalla.

    // uint32_t palabra = 5;
    // uint32_t mascara_para_bits_altos = 0x00000000000000000000000000000111;
    // uint32_t mascara_para_bits_bajos = 0x11100000000000000000000000000000;

    // uint32_t m1 = mascara_para_bits_altos && palabra;
    // uint32_t m2 = mascara_para_bits_bajos && palabra;

    // // shiftear m1 a izquierdar hasta obtener los 3 bits altos en la posicion mas baja y comparar con m2 
    // uint32_t a = 5;
    // uint32_t b = 5;

    // if ( ((a >> 29) & 7) == (b & 7) ) {
    //     printf("Los bits son iguales\n");
    // } else {
    //     printf("Los bits son distintos\n");
    // }
    
    // ejercicio 11
    // Realizar un programa que rote un arreglo de n´umeros enteros a la izquierda. El arreglo
    // puede estar hardcodeado. Por ejemplo, si el arreglo es [1, 2, 3, 4], el resultado debe
    // ser [2, 3, 4, 1]. Cuando veamos punteros, podremos hacer una funci´on de rotaci´on
    // gen´erica.
    // #define N 4 
    // int arr1[N] = {1,2,3,4};
    // int arr2[N] = {0,0,0,0};

    // for(int i = 0; i < N-1; i++){
    //     arr2[i] = arr1[i+1];
    //     printf("Seteamos %d \n", arr2[i]);
    // }

    // arr2[N-1] = arr1[0];
    // printf("Seteamos %d \n", arr2[N-1]);

    // ejercicio 12
    // int cantRotaciones = 2;
    // #define N 4 
    // int arr1[N] = {1,2,3,4};
    // int arr2[N] = {0,0,0,0};

    // for(int k = 0; k < cantRotaciones; k++){
        
    //     for(int i = 0; i < N-1; i++){
    //         arr2[i] = arr1[i+1];
    //         printf("Seteamos %d \n", arr2[i]);
    //     }

    //     arr2[N-1] = arr1[0];
    //     printf("Seteamos %d \n", arr2[N-1]);

    //      // copiar arr2 en arr1 para la siguiente rotación
    //     for(int i = 0; i < N; i++){
    //         arr1[i] = arr2[i];
    //     }
    // }
    
    // ejercicio 13
    
    // int contador[6] = {0};

    // for(int i=0; i < 60000000; i++){
    //     int numero = rand() % 6;
    //     contador[numero]++;
    // }

    //  for(int i = 0; i < 6; i++){
    //     printf("El numero %d: aprecio %d veces\n", i+1, contador[i]);
    // }
    
    // ejercicio 14
    // Realizar un programa que declare una variable global y una variable local. Luego, imprimir
    // el valor de ambas variables en la funci´on main. Luego, probar darles el mismo nombre.
    // ¿Qu´e sucede? ¿Por qu´e?

    // funcion();
    // printf("%d \n",a);

    // ejercicio 15
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    int fac = factorial(n);
    printf("el factorial es %d \n", fac);


    
    return 0;
}
