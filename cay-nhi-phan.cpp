#include"stdio.h"
#include"conio.h"
#include"string.h"
#include <stdlib.h>

#define MAX 50

typedef struct sv
{
	char hoten[MAX];
	int tuoi;
}sv;
typedef struct node
{
	sv data;
	node *left;
	node *right;
}node;
#define node Node
typedef struct node *TREE;
TREE root;

void CreateTree(TREE &root)
{	
	sv s;
	printf("Nhap ho ten: ");
	fflush(stdin);
	gets(s.hoten);
	if(strcmp(s.hoten, "n") != 0) {
		printf("Nhap tuoi: ");
		scanf("%d",&s.tuoi);
		root=(node*)malloc(sizeof(node));
		root->data = s;
		printf("\nCon trai cua %s (ENTER NULL)\n", s.hoten);
		CreateTree(root->left);
		printf("\nCon phai cua %s (ENTER NULL)\n", s.hoten);
		CreateTree(root->right);
	} else 
		root=NULL;
}

void NLR(TREE root)
{
	if (root != NULL)
	{
		printf("Ten: %s\t Tuoi: %d\n", root->data.hoten, root->data.tuoi);
		NLR(root->left);
		NLR(root->right);
	}
}
void	LNR(TREE root)
{
	if (root != NULL)
	{
			LNR(root->left);
			printf("Ten: %s\t Tuoi: %d\n", root->data.hoten,root->data.tuoi);
			LNR(root->right);
	}
}
void	LRN(TREE root)
{
	if (root != NULL)
	{
		LRN(root->left);
		LRN(root->right);
		printf("Ten: %s\t Tuoi: %d\n", root->data.hoten, root->data.tuoi);
	}
}
node* searchNode(TREE t, int tuoi) {
	if(t) {
		if(t->data.tuoi == tuoi) 
			return t;
		if(t->data.tuoi > tuoi)
			return searchNode(t->left, tuoi);
		else 
			return searchNode(t->right, tuoi);
	} else
		return NULL;
}
int insertNode(TREE &t, sv s) {
	if(t) {
		if(strcmp(t->data.hoten, s.hoten) == 0) 
			return 0;
		if(t->data.tuoi > s.tuoi)
			return insertNode(t->left, s);
		else 
			return insertNode(t->right, s);
	}
	t = new node();
	if(t == NULL)
		return -1;
	t->data = s;
	t->left = t->right = NULL;
	return 1;
}
void timNodeTheMang(TREE& p, TREE &q) {
	if(q->left)
		timNodeTheMang(p, q->left);
	else {
		p->data = q->data;
		p = q;
		q = q->right;
	}
}
int delNode(TREE& t, sv s) {
	if(t == NULL)
		return 0;
	if(t->data.tuoi > s.tuoi)
		return delNode(t->left, s);
	if(t->data.tuoi < s.tuoi) 
		return delNode(t->right, s);
	else {
		TREE p = t;
		if(t->left == NULL)
			t = t->right;
		else {
			if(t->right == NULL)
				t = t->left;
			else {
				TREE q = t->right;
				timNodeTheMang(p, q);
			}
		}
		delete p;
	}
}
void removeTree(TREE &t) {
	if(t) {
		removeTree(t->left);
		removeTree(t->right);
		delete t;
	}
}
void menu() {
	int choose;
	TREE t;
	do {
		scanf("%d",&choose);
		printf("\n1. Nhap TREE");
		printf("\n2. Duyet TREE");
		printf("\n3. Tim Node");
		printf("\n4. Chen Node");
		printf("\n5. Xoa Tat Ca Cay");
		printf("\n0. Thoat");
	} while(choose != 0);
	switch(choose) {
		case 0:
			break;
		case 1:
			CreateTree(t);
			break;
		case 2:
			printf("\n+++++ DUYET CAY +++++\n");
			printf("Duyet Cay NLR:\n");
				NLR(t);
			printf("\n Duyet Cay LRN:\n");
				LRN(t);
			printf("\n Duyet Cay LNR:\n");
				LNR(t);
			break;
		case 3:
			int x;
			printf("Nhap so tuoi can tim: ");
			scanf("%d",&x);
			Node *node = new Node();
			n = searchNode(t, x);
			if(n == NULL)
				printf("Khong tim thay node nao co so tuoi nhu vay\n");
			else {
				printf("Tim thay Node: [Ten: %s\tTuoi: %d]\n", n->data.hoten, n->data.tuoi);
			}
			break;
		case 4:
			sv s;
			printf("\nNhap Sinh Vien can chen: \n");
			printf("Nhap ho ten: ");
			gets(s.hoten);
			printf("Nhap tuoi: ");
			scanf("%d",&s.tuoi);
			if(insertNode(t, s) == 0)
				printf("Node vua nhap da co\n");
			else {
				insertNode(t, s);
			}
			break;
		case 5:
			removeTree(t);
			break;
	}
}
int main()
{
	menu();
	getch();
}
