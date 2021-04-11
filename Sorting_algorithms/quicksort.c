#include <stdio.h>
#define NMAX 10

void quicksort(int array[], int inicio, int fim);
int divide(int array[], int inicio, int fim);

int main(){
    int array[NMAX];
    for(int i=0; i<NMAX; i++) scanf("%d", &array[i]); // Reading the array with NMAX positions
    quicksort(array, 0, NMAX-1);
    for(int i=0; i<NMAX; i++) printf("%d ", array[i]); // Printing the sorted array
    printf("\n");
    return 0;
}


int divide(int array[], int inicio, int fim){
    int pivot = array[fim]; // Chosing the last element as the pivot
    int i=inicio-1;
    for(int j=inicio; j<fim; j++){
        if(array[j] < pivot){
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    array[fim] = array[i+1];
    array[i+1] = pivot;
    return i+1;
}

void quicksort(int array[], int inicio, int fim){
    if(inicio >= fim) return; // Base case 

    int limite = divide(array, inicio, fim);
    quicksort(array, inicio, limite-1);
    quicksort(array, limite+1, fim);
}
