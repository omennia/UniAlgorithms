#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
#define not_defined 0
#define is_defined 1

vector<int> num;
vector<int> lo;
stack<int> stk;
vector<bool> in_stack;
int idx = 0;
int scc_num = 0;

void tarjan(int v){
    num[v] = lo[v] = ++idx;
    stk.push(v);
    in_stack[v] = true;

    for(auto elem : arr[v]){
        if(num[elem] == not_defined){
            tarjan(elem);
            lo[v] = min(lo[v], lo[elem]);
        }
        else if(in_stack[elem]){
            lo[v] = min(lo[v], num[elem]);
        }
    }

    if(num[v] == lo[v]){
        ++scc_num;
        cout << "SSC nº"  << scc_num << " found: ";
        while(stk.top() != v){
            in_stack[stk.top()] = false; // Retirar da stack
            cout << stk.top() << ' ';
            stk.pop();
        } 

        cout << stk.top() << '\n';
        in_stack[stk.top()] = false; // Retirar da stack
        stk.pop();
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, e; cin >> n >> e;
    arr.clear(); arr.resize(n+2); 
    num.clear(); num.resize(n+2);
    lo.clear(); lo.resize(n+2);
    in_stack.clear(); in_stack.resize(n+2);
    for(int i=0; i<e; ++i){
        int a, b; cin >> a >> b;
        arr[a].emplace_back(b);
    }

    for(int i=1; i<=n; ++i){
        if(num[i] == not_defined){
            tarjan(i);
        }
    }
}