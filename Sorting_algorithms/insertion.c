#include <stdio.h>
#define NMAX 10

void insertion(int array[]);

int main(){
    int array[NMAX];
    for(int i=0; i<NMAX; i++) scanf("%d", &array[i]);
    insertion(array);
    for(int i=0; i<NMAX; i++) printf("%d ", array[i]);
    printf("\n");
    return 0;
}


void insertion(int array[]){
    for(int i=0; i<NMAX-1; i++){
        for(int j=i+1; j > 0; j--){ // Comparing element in position j with elements in positions prior until it finds a bigger num
            if(array[j] < array[j-1]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            } else break;
        }
    }
}