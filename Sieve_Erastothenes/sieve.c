#include <stdio.h>

void sieve(long inicio, long fim, long array[]);

int main(){
    long inicio, fim;
    printf("Inicio: "); scanf("%ld", &inicio);
    printf("Fim: "); scanf("%ld", &fim);       
    long array[fim-inicio+1];
    sieve(inicio, fim, array);
}


void sieve(long inicio, long fim, long array[]){
    long limite = fim-inicio+1;
    for(long i=0; i<limite; i++){
        array[i] = inicio+i;
    }

    for(long i=0; i<limite; i++){
        for(long j=2; j*j <= limite; j++){  // Tem de ser <= !!!
            if(array[i] % j == 0 && array[i] != j){
                array[i] = 0;
                break;
            }
        }
    }

    if(array[0] == 1) array[0] = 0; // Verificar se começamos no 1 (e retirar este elemento)

    for(long i=0; i<limite; i++) {
        if(array[i]) printf("%ld\t", array[i]);
    }
    printf("\n");

}