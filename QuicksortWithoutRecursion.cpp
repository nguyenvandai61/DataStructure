#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int l, int h) {
	int x = arr[h];
	int i = l - 1;
	
	for (int j = l; j <= h - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[h]);
	return i+1;
}
void quickSortWithoutRecursion(int *a, int l, int h) {
	int stack[h-l+1];
	int top = -1;
	
	stack[++top] = l;
	stack[++top] = h;
	
	while(top >= 0) {
		h = stack[top--];
		l = stack[top--];
		
		int p = partition(a, l, h);
		
		if ( p-1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		
		if (p+1 < h) {
			stack[++top] = p+1;
			stack[++top] = h;
		}
	}
}


void printArray(int *a, int &n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int arr2[6] = {5, 3, 2, 8, 11, 6};
	int n = 6;
	quickSortWithoutRecursion(arr2, 0, n-1);
	printArray(arr2, n); 
}
