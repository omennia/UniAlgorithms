#include <stdio.h>

int binary_seach(int array[], int num);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int array[b-a+1];
    for(int i=0; i<b-a; i++) array[i] = a + 2*i;

    int found = binary_seach(array, 224);
    if(found == -1) printf("Not found\n");
    else printf("Element %d found at position %d\n", array[found], found);
    return 0;

}

int binary_seach(int array[], int num){

    while(b > a){
        
    }

}