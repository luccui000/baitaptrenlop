#include <bits/stdc++.h>
#define M 5

// struct Node 
//
struct Node {
	int numTree;
	int branch[M-1];
	// M la so bac 
};
struct Node* NodePtr;
NodePtr *root;
enum KeyValue { };
// Them phan tu vao B-Tree
NodePtr father(NodePtr node) {
}
void split(NodePtr node, int n, NodePtr newNode, NodePtr* node2, int* m) {

}
int NodeSearch(NodePtr node, int m) {
}
void insNode(NodePtr node, int n, NodePtr newNode, int p) {
}
void insert(NodePtr node, int k, int pos){
	NodePtr n1, n2 f, nNewNode;
	n1 = node;
	int p, new_key, mid_key;
	nNewNode = nullptr;
	p = pos;
	f = father(n1);
	while(f != nullptr && n1->numTree == ORDER) {
		split(n1, new_key, nNewNode, p, &n2, &mid_key);
		n1 = f;
		new_key = mid_key;
		nNewNode = n2;
		p = NodeSearch(f, mid_key);
		f = father(n1);
	}
	if(n2->numTree < ORDER) {
		insNode(n1, new_key, nNewNode, p);
		return ;
	}

}

int main() {
	return 0;
}
