/* This is the skeleton of a BST (binary search tree) */
/* still lacks some implementation */

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *left;
	Node *right;	
};
class tree{
	public:
	Node *root;
	int n_nodes;

	tree(){
		root = NULL;
		n_nodes = 0;
	}

	void pre_print_tree(Node *node){
		if(node == NULL) return;
		cout << node->val << ' ';
		pre_print_tree(node->left);
		pre_print_tree(node->right);
	}
	void in_print_tree(Node *node){ // in-order printing
		if(node == NULL) return;
		in_print_tree(node->left);
		cout << node->val << ' ';
		in_print_tree(node->right);
	}
	void in_print_tree(){
		in_print_tree(root);
		cout << '\n';
	}
	void pre_print_tree(){
		pre_print_tree(root);
		cout << '\n';
	}
	int find_level(Node *node, int val, int level){
		if(node == NULL) return -1;
		else if(node->val == val) return level;
		else if(node->val > val){
			return find_level(node->left, val, level+1);
		} 
		else if(node->val < val){
			return find_level(node->right, val, level+1);
		}
		return -1;
	}
	int find_level(int val){
		return find_level(root, val, 0);
	}
	Node *createNode(int val){
		Node *new_node = new Node();
		new_node->val = val;
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;
	}
	Node *insert(Node *node, int val){
		if(root == NULL) {
			root = createNode(val);
		}
		
		if(node == NULL) {
			return createNode(val);
		}
		else if(val > node->val){
			node->right = insert(node->right, val);
		} else if(val < node->val){
			node->left = insert(node->left, val);
		} 
		return node; // the val is already in the tree (not needed for this exercice
		// 													under the given constains)
	} 
	void insert(int val){
		insert(root, val);
	}

};
void print(vector<int> &arr){
	for(auto elem : arr) cout << elem << ' ';
	cout << '\n';
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		vector<int> arr(n);
		int maximum = 0;
		for(int i=0; i<n; ++i){
			cin >> arr[i];
			maximum = max(maximum, arr[i]);
		}

		tree arv;
		arv.insert(maximum); // inserting the max
		
		for(int i=0; i<n; ++i){ // inserting the rest
			arv.insert(arr[i]);
		}

		// cout << arv.n_nodes << '\n';

		// print(arr);
		for(int i=0; i<n; ++i){
			cout << arv.find_level(arr[i]) << ' ';
		} cout << '\n';

		// arv.pre_print_tree();
	}

}