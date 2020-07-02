#include <stdio.h>

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void printArr(int a[], int n){
	for(int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
// selection sort
void selectionsort(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j])
				swap(a[i],a[j]);
		}
	}
}
// insertion sort
void insertionsort(int a[], int n){
	int pos, x;
	for(int i = 1; i < n; i++){
		x = a[i];
		pos = i - 1;
		while(pos >= 0 && a[pos] > x){
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos+ 1] = x;
	}
}
void interchangesort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[i])
				swap(a[i], a[j]);
		}
	}
}
void bublesort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = n - 1; j > i; j--){
			if(a[j] < a[j-1])
				swap(a[j], a[j- 1]);
		}
	}
}
// Heap Sort
void Shift(int a[], int l, int r){
	int i = l;
	int j = 2 * i;
	int x = a[i];
	while(j <= r){
		if(j < r)
			++j;
		if(a[j] < x)
			break;
		else {
			a[i] = a[j];
			i = j;
			j = 2 * i;
			a[i] = x;
		}
	}
}
void createHeap(int a[], int n ) {
	int l = n/2;
	while(l >= 0){
		Shift(a, l, n - 1);
		l--;
	}
}
void heapsort(int a[], int n) {
	createHeap(a, n);
	int r = n;
	while(r >= 0){
		swap(a[0], a[r]);
		r--;
		Shift(a, 0, r);
	}
}
int main() {
	int a[] = { 2, 54, 23, 66, 33, 85, 4, 56, 23, 6, 44, 99, 10, 9, 48, 38 };
	int n = sizeof(a)/ sizeof(a[0]);
	printf("Day so da nhap: "); printArr(a, n);
	// selectionsort(a, n);
	// insertionsort(a, n);
	// interchangesort(a, n);
	// bublesort(a, n);
	heapsort(a, n - 1);
	printf("Day so sau khi sap xep: "); printArr(a, n);
	return 0;
}
