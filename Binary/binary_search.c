#include <stdio.h>

int binary_seach(int array[], int num_elems, int to_search);

int main(){
    
    int array[] = {1,2,5,9,10,23,27,29,365,1241,1242,1422,1456};
    int num_elems = sizeof(array) / sizeof(array[0]);

    int to_search; scanf("%d", &to_search);
    int found = binary_seach(array, num_elems, to_search);
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
