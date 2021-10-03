/* Implementação de BSTtree (Binary search tree) */
#include <bits/stdc++.h>
using namespace std;
    
int number_nodes = 0;
    
struct Node{
    bool key;
    Node *left;
    Node *right;
};
Node *createNode(){
    Node *node = new Node();
    node->key = true;
    node->left = NULL;
    node->right = NULL;
    return node;
}
class Tree{
    public:
    Node *root;
    Tree(){
        root = createNode();
    }
    
    Node *get_root(){
        return root;
    }
};
void fill(Node *node, int p){
    if(p <= 0) return;
    node->left = createNode();
    node->right = createNode();
    fill(node->left, p-1);
    fill(node->right, p-1);
    ++number_nodes;
}
void fill(Tree t, int p){
    fill(t.get_root(), p);
}
void remove(Node *node){
    if(node->left != NULL) remove(node->left);
    if(node->right != NULL) remove(node->right);
    delete(node);
}
void remove(Tree t){
    remove(t.get_root());
    number_nodes = 0;
}
    
int bfs_count(Node *node, int p){
    int cnt = 0;
    queue<Node*> bfs;
    bfs.push(node);
    while(!bfs.empty()){
        int itr = 0;
        int level_size = (int)bfs.size();
        // int level_nodes = (1<<)
        while(!bfs.empty() && level_size-- && itr < p){
            Node *next = bfs.front();
            if(next->left != NULL) bfs.push(next->left);
            if(next->right != NULL) bfs.push(next->right);
            bfs.pop();
            ++itr;
        }
        ++cnt;
    }
    return cnt;
}
    
int bfs_count(Tree t, int p){
    return bfs_count(t.get_root(), p);
}
    
    
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int h, p; cin >> h >> p;
        Tree t;
        fill(t, h-1);
        cout << bfs_count(t, p) << '\n';
        // cout << number_nodes << '\n';
        remove(t);
    }
}