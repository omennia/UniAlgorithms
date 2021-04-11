#include <stdio.h>
#define NMAX 10

void selection(int array[]);

int main(){
    int array[NMAX];
    for(int i=0; i<NMAX; i++) scanf("%d", &array[i]);
    selection(array);
    for(int i=0; i<NMAX; i++) printf("%d ", array[i]);
    printf("\n");
    return 0;
}

void selection(int array[]){
    for(int i=0; i<NMAX; i++){
        int savepos=i;
        for(int j=i; j<NMAX; j++){
            if(array[j] < array[savepos]) savepos = j;  // Always comparing to the least element, sequentially
        }
        int temp = array[savepos];
        array[savepos] = array[i];
        array[i] = temp;
    }
}