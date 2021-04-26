#include <stdio.h>
#include <math.h>

void factoring_numbers(int num);

int main(){
    int num; scanf("%d", &num);
    factoring_numbers(num);
    putchar('\n');
    return 0;
}

void factoring_numbers(int num){
    int nunu = (int) sqrt(num) + 1;
    int array[nunu+1];

    for(int i=0; i<nunu; i++) array[i] = i; // Initialize
    for(int i=0; i<nunu; i++){ // Does the sieve
        for(int j=2; j*j <= num; j++){
            if(array[i]%j == 0 && array[i] != j){
                array[i] = 0; 
                break;
            }
        }
    }
    int start = 0;
    if(num == 1) { printf("1"); return; }
    while(num > 1){
        if(array[start] == num){
            printf("%d", num); return;
        }
        if(array[start] != 1 && array[start] != 0 && num % array[start] == 0){
            printf("%d", array[start]);
            num /= start;
            if(num != 1) printf(" * ");

        } else start++;
    }
    putchar('\n');
}