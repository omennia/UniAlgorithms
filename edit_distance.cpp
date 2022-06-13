#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &arr){
    for(auto elem : arr){
        for(auto x : elem){
            cout << x << ' ';
        } cout << '\n';
    }
}

int edit_dist(string &s1, string &s2){
    int sz1 = (int)s1.length();
    int sz2 = (int)s2.length();

    vector<vector<int>> arr(sz1+1, vector<int> (sz2+1));
    for(int i=0; i<=sz1; ++i){ arr[i][0] = i; }
    for(int j=0; j<=sz2; ++j){ arr[0][j] = j; }

    // print(arr); // ver a matriz resultante

    /* Preencher a matriz de DP */
    for(int i=1; i<=sz1; ++i){
        for(int j=1; j<=sz2; ++j){
            int up = 1 + arr[i-1][j];                           // Verificar a posição no topo
            int left = 1 + arr[i][j-1];                         // Verificar a posição à esquerda
            int diag = (s1[i-1] != s2[j-1]) + arr[i-1][j-1];    // Verificar a diagonal. Neste caso se a letra for igual, contamos como zero.
            arr[i][j] = min({up, left, diag});
        }
    }
    // print(arr); // ver a matriz resultante
    return arr[sz1][sz2];
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2; cin >> s1 >> s2;
    cout << s1 << ' '  << s2 << '\n';
    
    int ans = edit_dist(s1, s2);
    cout << "Edit distance: " << ans << '\n';
}