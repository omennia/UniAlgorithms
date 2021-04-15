// Hanoi towers - Credits to channel Reductible Video on: https://www.youtube.com/watch?v=rf6uf3jNjbo
#include <stdio.h>

void hanoi(int a, int b, int c);
void print(int a, int b);

int counter = 0;

int main(){
    int number_of_towers, start, end;
    printf("Insert number of towers: \n"); scanf("%d", &number_of_towers);
    printf("Insert starting point: \n"); scanf("%d", &start);
    printf("Insert ending point: \n"); scanf("%d", &end);

    hanoi(number_of_towers, start, end);

    printf("\nIt took %d disk moves.\n", counter);    
    return 0;

}

void print(int a, int b){
    printf("%d   -->   %d\n", a, b);
    counter++;
}

void hanoi(int n, int start, int end){
    int other;
    if(n == 1) print(start, end);
    else{
        other = 6 - (start + end);
        hanoi(n-1, start, other);
        print(start, end);
        hanoi(n-1, other, end); 
    }
    
}