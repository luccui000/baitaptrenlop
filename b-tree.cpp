#include <bits/stdc++.h>
#define M 5

// struct Node 
//
struct Node {
	int numTree;
	int branch[M-1];
	// M la so bac 
	struct Node*[M];
};
struct Node* NodePtr;
NodePtr *root;
enum KeyStatus { Duplicate, SearchFailure, Success, Insert, LessKey };
// Them phan tu vao B-Tree
NodePtr father(NodePtr node) {
}
void copy(NodePtr node, int first, int last, NodePtr node2) {
	for(int i = first; i < last; i++) 
		node2->branch[i-first] = node->branch[i];
	for(int i = first; i < last; i++) {
		node2->con[i-first] = node-branch[i];
	node2->numTree = last-first + 2;
}
void insNode(NodePtr node, int n, NodePtr newNode, int p) {

}
void split(NodePtr node, int n, NodePtr newNode, int pos, NodePtr* node2, int* m) {
	NodePtr p = getNode();
	if(pos > N / 2) {
		copy(node, N / 2 + 1, ORDER - 2, p);
		insNode(p, n, pos - N/2-1)
		node->numTree = N / 2 + 1;
		*m = node->branch[N/2];
		*node2 = p;
		return;
	} 
	if(pos == N / 2){
		copy(node, N / 2, ORDER - 2, p);
		node->numTree = N / 2+ 1;
		p->branch[0] = newNode;
		*m = node->branch[N/2];
		*node2 = p;
		return;
	}
	if(pos < N / 2) {
		copy(node, N/2, ORDER-2, p);
		node->numTree = N/2 + 1;
		*m = node->branch[N/2-1];
		insNode(node, n, newNode, pos);
		return;
	}
}
int NodeSearch(NodePtr node, int m) {
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
	split(n1, new_key, nNewNode, p, &n2, &mid_key);
	root->branch[0] = n1;
	root->branch[1] = n2;
	printf("Noi dung cua khoa moi:");
	scanf("%d", &k);
	if(root == nullptr)
		root->makeRoot(k);
	else {
		s = search(k, &p, &tim);
		if(tim) 
			printf("Bi trung khoa, khong them\n");
		else 
			insert(s, k, p);
	}
}

int main() {
	return 0;
}






















