#include <stdio.h> // adaptado do prof. Pedro Ribeiro

void merge(int array[], int lo, int mid, int hi);
void mergesort(int array[], int lo, int hi);

int main(){
    int array[] = {1,2,6,3,1,6,43,34,23,12,32,43,23,65,354,234,76};
    int size = sizeof(array) / sizeof(array[0]);
    for(int i=0; i<size; i++) printf("%d ", array[i]);
    putchar('\n');
    mergesort(array, 0, size-1);
    for(int i=0; i<size; i++) printf("%d ", array[i]);
    putchar('\n');
}

void mergesort(int array[], int lo, int hi){
    if(lo == hi) return;
    int mid = lo + (hi-lo)/2;
    mergesort(array, lo, mid);
    mergesort(array, mid+1, hi);
    merge(array, lo, mid, hi);
}

void merge(int array[], int lo, int mid, int hi){
    int pos = 0, p1 = lo, p2 = mid+1;
    int aux[lo+hi-1];
    
    while(p1 <= mid && p2 <= hi) aux[pos++] = array[p1] < array[p2] ? array[p1++] : array[p2++];
    while(p1<=mid) aux[pos++] = array[p1++]; // Only one of
    while(p2<=hi) aux[pos++] = array[p2++]; // these two happens

    for(int i=0; i<pos; i++) array[i+lo] = aux[i];
}