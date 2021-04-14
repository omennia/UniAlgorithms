#include <stdio.h>

void sieve(int start, int end);

int main(){
    int start, end;
    scanf("%d %d", &start, &end);
    sieve(start, end);
    return 0;
}

void sieve(int start, int end){
    int array[end-start+1];
    for(int i=0; i<end-start; i++) array[i] = start+i; // Initialize array
    for(int i=0; i<end-start; i++){
        for(int j=2; j*j <= array[i]; j++){
            if(array[i] % j == 0) {
                array[i] = 0;
                break;
            }
        }
    } if(array[0] == 1) array[0] = 0; // If the first element is one, take him out because one is not a prime :-)

    for(int i=0; i<end-start; i++) if(array[i] != 0) printf("%d ", array[i]);
    putchar('\n');    
}