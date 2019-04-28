#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void insertSort(int *a, int &n){
	for (int i = 1; i < n; i++) {
		int t = a[i];
		int j;
		for (j = i - 1; j >= 0 && t < a[j]; j--) {
			a[j + 1] = a[j];
		}
		a[j+1] = t;
	}
}



void printArray(int *a, int &n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int arr[6] = {5, 3, 2, 8, 11, 6};
	int n = 6;
	insertSort(arr, n);
	printArray(arr, n); 
}
