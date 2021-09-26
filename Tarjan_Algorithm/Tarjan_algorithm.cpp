/* Tarjan Algorithm (to find Strongly Connected Components) */
/* Com a *receita* do professor Pedro Ribeiro */

#include <bits/stdc++.h>
using namespace std;
#define NMAX 25
#define undefined -1

int n, pos = 0, scc_count = 0;
vector<vector<bool>> adj(NMAX, vector<bool> (NMAX, false));  // Matriz de adjacencias
vector<int> num(NMAX, undefined);                            // Ordem visitada
vector<int> low(NMAX, undefined);                            // Low link   
vector<bool> on_stack(NMAX, false);                          // Ver se está no stack em O(1)
stack<int> stk;                                              // Invariante do algoritmo de Tarjan

void dfs(int v){
    num[v] = low[v] = ++pos;
    stk.push(v);
    on_stack[v] = true;

    for(int i=1; i<=n; ++i){
        if(adj[v][i]){
            if(num[i] == undefined){
                dfs(i);
                low[v] = min(low[v], low[i]);
            } else if(on_stack[i]){
                low[v] = min(low[v], low[i]);
            }
        }
    }

    if(num[v] == low[v]){
        list<int> to_print;
        int root = v;
        int next = stk.top();
        while(next != root){
            to_print.push_back(next);
            on_stack[next] = false;
            stk.pop();
            next = stk.top();
        }
        on_stack[next] = false;
        to_print.push_back(next);
        stk.pop();
        ++scc_count;
        cout << "Component nº" << scc_count << ": ";
        for(auto elem : to_print) cout << elem << ' ';
        cout << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int e; cin >> n >> e;

    for(int i=0; i<e; ++i){
        int a, b; cin >> a >> b;
        adj[a][b] = true;
    }

    for(int i=1; i<=n; ++i){
        if(num[i] == undefined) dfs(i);
    }

    cout << "scc_count: " << scc_count << '\n';
}