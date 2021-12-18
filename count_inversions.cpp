#include <bits/stdc++.h>

using namespace std;
void print(int arr[], int sz){
    for(int i=0; i<sz; ++i) cout << arr[i] << ' ';
    cout << '\n';
}

int cnt_inversions = 0;

void merge(int arr[], int lo, int mid, int hi){
    int aux[hi-lo + 1];
    int p1 = lo, p2 = mid + 1, idx = 0;
    while(p1 <= mid && p2 <= hi){
        if(arr[p1] < arr[p2]){
            aux[idx++] = arr[p1++];
        }
        else{
            cnt_inversions += mid - p1 + 1;  // Count the inversions: To any element we choose from the "right" side, we have 
            aux[idx++] = arr[p2++];          //                       to inversions for that number equal to the counting from p1 to mid. // see slides de AMD aula 11 to clarify 
        }
    }
    while(p1 <= mid) aux[idx++] = arr[p1++];
    while(p2 <= mid) aux[idx++] = arr[p2++];
    for(int i=0; i<idx; ++i) arr[lo+i] = aux[i];
}

void mergesort(int arr[], int lo, int hi){
    if(lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    mergesort(arr, lo, mid);
    mergesort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int arr[] = {3, 5, 4, 1, 2}; // Change to whatever array
    int sz = sizeof(arr)/sizeof(arr[0]);
    cout << "size: " << sz << '\n';
    print(arr, sz);
    mergesort(arr, 0, sz);
    print(arr, sz);
    cout << "inversions: " << cnt_inversions << '\n';
}
