#include <stdio.h>

int horner(char array[], int base);

int main(){
    char r[] = "236549865";
    char binary[] = "10011";
    char base14[] = "10AB1";
    char base16[] = "1FAD42";

    int res1 = horner(r, 10); 
    int res2 = horner(binary, 2);
    int res3 = horner(base14, 14);
    int res4 = horner(base16, 16);
    printf("Base 10: %d\n", res1);
    printf("Base 2: %d\n", res2); 
    printf("Base 14: %d\n", res3); 
    printf("Base 16: %d\n", res4); 
    return 0;
}


int horner(char array[], int base){
    int size; 
    for(size=0; array[size] != '\0'; size++); // Ver o numero de digitos

    int res = 0; 
    for(int i=0; i<size; i++){
      if (base >= 10){
          if(array[i] == 'A') res = base * res + 10;
          else if(array[i] == 'B') res = base * res + 11;
          else if(array[i] == 'C') res = base * res + 12;
          else if(array[i] == 'D') res = base * res + 13;
          else if(array[i] == 'E') res = base * res + 14;
          else if(array[i] == 'F') res = base * res + 15;
          else res = base * res + (int) (array[i] - '0');
      }
      else res = base * res + (int) (array[i] - '0');
    } 
    return res;
}