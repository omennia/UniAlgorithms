#include <stdio.h> // adaptado do prof. Pedro Ribeiro

void merge(int v[], int lo, int mid, int hi);
void mergeSort(int v[], int lo, int hi);

int main() {
    int v[] = {56,324,6,32,1234,34,3,12,213,243,5,3,412,43,23,75}; // Inicializacao de array
    int len = sizeof(v) / sizeof(v[0]);
    for (int i=0; i<len; i++) printf("%d ", v[i]);
    putchar('\n');
    mergeSort(v, 0, len-1);
    for (int i=0; i<len; i++) printf("%d ", v[i]);
    putchar('\n');
}


void mergeSort(int v[], int lo, int hi) {
    if (lo == hi) return;
    int mid = lo + (hi-lo)/2;
    mergeSort(v, lo, mid);
    mergeSort(v, mid+1, hi);
    merge(v, lo, mid, hi);
}

void merge(int v[], int lo, int mid, int hi) {
    int aux[hi-lo+1];
    int p1 = lo;
    int p2 = mid+1;
    int cur = 0;
    while (p1 <= mid && p2 <= hi) {
        if (v[p1] <= v[p2]) aux[cur++] = v[p1++];
        else aux[cur++] = v[p2++];
    }
    while (p1<=mid) aux[cur++] = v[p1++]; // Only one of these 
    while (p2<=hi) aux[cur++] = v[p2++];  // two happens

    for (int i=0; i<cur; i++) v[lo+i] = aux[i];
}