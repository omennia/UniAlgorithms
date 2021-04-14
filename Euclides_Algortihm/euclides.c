// Algoritmo de Euclides - Para encontrar o máximo divisor entre dois números
#include <stdio.h>

int euclides(int a, int b);

int main(){

    int a, b;
    scanf("%d %d", &a, &b); // Valores para encontrar o max div comum
    int result = euclides(a, b);
    printf("O máximo divisor comum é: %d\n", result);
    return 0;
}

int euclides(int a, int b){
    if(b == 0) return a;
    if(b>a) return euclides(b, a);
    return euclides(b, a%b);
}