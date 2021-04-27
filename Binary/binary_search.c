// Reads two numbers and creates an array with all the even numbers between (and including) the two numbers read. 
#include <stdio.h>

int binary_seach(int array[], int num_elems, int to_search);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int array[b-a+1];
    for(int i=0; i<=(b-a)/2; i++) array[i] = a + 2*i;
    int elem; printf("Enter element to search: "); scanf("%d", &elem);
    int size = sizeof(array) / sizeof(array[0]);
    int found = binary_seach(array, size, elem);
    if(found == -1) printf("Not found\n");
    else printf("Element %d found at position %d\n", array[found], found);
    return 0;
}

int binary_seach(int array[], int num_elems, int to_search){
    int lo = 0, hi = num_elems-1;
    while(hi >= lo){
        int mid = lo + (hi - lo) / 2;
        if(array[mid] == to_search) return mid;
        if(array[mid] > to_search) hi = mid - 1;
        else lo = mid + 1;
    }
    return -1;
}
