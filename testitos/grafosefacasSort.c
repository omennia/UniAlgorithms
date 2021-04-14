#include <stdio.h>
#include <string.h>
#define NMAX 10

typedef struct {
    int idade; 
    char *nome; // Porque é que não funciona com nome[NMAX]
    char *cor_dos_olhos; // Porque é que não funciona com cor_dos_olhos[NMAX]
} PESSOA; 

PESSOA array_de_grafos[4];

int divide(int array[], int start, int end);
void quicksort(int array[], int start, int end);
int compare(PESSOA pessoa1, PESSOA pessoa2);

int main(){
    // array_de_grafos[0] = { "Hugo", 25, "castanha"};  // Porque não posso fazer assim
    // array_de_grafos[1] = { "Dardo", 18, "castanha"};
    // array_de_grafos[2] = { "Lara", 18, "castanha"};
    array_de_grafos[0].idade = 25; array_de_grafos[0].nome = "Hugo"; array_de_grafos[0].cor_dos_olhos = "castanha";
    array_de_grafos[1].idade = 18; array_de_grafos[1].nome = "Duarte"; array_de_grafos[1].cor_dos_olhos = "castanha";
    array_de_grafos[2].idade = 17; array_de_grafos[2].nome = "Lara"; array_de_grafos[2].cor_dos_olhos = "castanha";

    int ordem[] = {2,1,0};

    putchar('\n'); printf("Nome antes de ordenar: \n");
    for(int i=0; i<3; i++){
        printf("%s", array_de_grafos[ordem[i]].nome);
        if(i<2) printf(" -> ");
    } printf("\n\n");
    
    quicksort(ordem, 0, 2);


    putchar('\n'); printf("Nome depois de ordenar: \n");
    for(int i=0; i<3; i++){
        printf("%s", array_de_grafos[ordem[i]].nome);
        if(i<2) printf(" -> ");
    } printf("\n\n");

    return 0;
}

int compare(PESSOA pessoa1, PESSOA pessoa2){
    // Comparar primeiro a cor dos olhos cause why not
    int maxlen = strlen(pessoa1.cor_dos_olhos) < strlen(pessoa2.cor_dos_olhos) ? strlen(pessoa1.cor_dos_olhos) : strlen(pessoa2.cor_dos_olhos);
    for(int i=0; i<maxlen; i++){ // Por ordem crescente
        if(pessoa1.cor_dos_olhos[i] < pessoa2.cor_dos_olhos[i]) return 0;
        if(pessoa1.cor_dos_olhos[i] > pessoa2.cor_dos_olhos[i]) return 1;
    }
    // Comparar depois a idade ( mais velhos vêm primeiro )
    if(pessoa1.idade > pessoa2.idade) return 0;
    if(pessoa1.idade < pessoa2.idade) return 1;
    //==
    // Comparar depois o nome
    maxlen = strlen(pessoa1.nome) < strlen(pessoa2.nome) ? strlen(pessoa1.cor_dos_olhos) : strlen(pessoa2.cor_dos_olhos);
    for(int i=0; i<maxlen; i++){
        if(pessoa1.nome[i] < pessoa2.nome[i]) return 1;
        if(pessoa1.nome[i] > pessoa2.nome[i]) return 0;
    }
    return 0;  // CASO FINAL NÃO MUDA NADA
}


int divide(int array[], int start, int end){
    int pivot = array[end];
    int j=start, i = j-1; 
    for(int j=start; j<end; j++){
        if(compare(array_de_grafos[j], array_de_grafos[end])){
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    array[end] = array[i+1];
    array[i+1] = pivot;
    return i+1;
}


void quicksort(int array[], int inicio, int fim){
    if(inicio >= fim) return;
    int limite = divide(array, inicio, fim);
    quicksort(array, inicio, limite-1);
    quicksort(array, limite+1, fim);
}