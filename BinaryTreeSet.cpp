#include <stdio.h>
#include <stdlib.h>

struct Node  {
	int data; 
	struct Node *left; 
  	struct Node *right; 
};
struct Node* newNode(int data) {
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	
	node->data = data;
	
	node->left = NULL;
	node->right = NULL;
	
	return node;
}
// function that inserts a node with data into root node in order
Node* insertNode(Node* node, int data) {
	if (node == NULL) {
		return newNode(data);
	}
	else
	{
		if (data <= node->data) 
            node->left = insertNode(node->left, data); 
        else
            node->right = insertNode(node->right, data); 
  		
		return node;
	}
}
// function that counts the number of items in a binary tree.
int size(Node* node) {
	if (node == NULL)
		return 0;
	else {
		return size(node->left) + size(node->right) + 1;
	}
}
// function that returns the sum of all the keys in a binary tree.
int sum(Node* node) {
	if (node == NULL)
		return 0;
	else
		return node->data + sum(node->left) + sum(node->right);
}
// function that returns the maximum value of all the keys in a binary tree
int max(Node* node) {
	if (node == NULL) return -1;
	Node* current = node;
	while(current->right != NULL) {
		current = current->right;
	}
	return current->data;
}
// function that prints all the keys less than a given value v
void printKeysLess(Node* node, int v) {
	if (node == NULL)
		return;
	
	printKeysLess(node->left, v);
	if (node->data < v)
		printf("%d ", node->data);
	printKeysLess(node->right, v);
}
// Function that returns height of Binary Tree
int height(Node* node) {
	if (node == NULL)
		return 0;
	
	int lh = height(node->left);
	int rh = height(node->right);
	
	return 1 + ((lh>rh)? lh : rh);
}
// Function that print all nodes in ascending order
void printAllNodes(Node* node) {
	if (node == NULL)
		return;
	
	printAllNodes(node->left);
	printf("%d ", node->data);
	printAllNodes(node->right);
}
void printAllNodesPreOrder(Node* node) {
	if (node == NULL)
		return;
		
	printf("%d ", node->data);
	printAllNodes(node->left);
	printAllNodes(node->right);
}

// Function that return whether node1 and node2 is equal or not
bool equal(Node* node1, Node* node2) {
	if (node1 == NULL && node2 == NULL)
		return true;
	return (node1 && node2) && (node1->data == node2->data)
		&& equal(node1->left, node2->left)
		&& equal(node1->right, node2->right);
}

// Function that deletes a tree
void deleteTree(Node* &node) {
	if (node == NULL)
		return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
	
	node == NULL;
}
void printNode(Node* node) {
	if (node == NULL)
		return;
	
	printf("%d ", node->data);
}
//
void printLevel(Node* node, int level) {
}

int soNutNhanh(Node* node) {
	if (node == NULL) return 0;
	else if (node->left == NULL && node->right == NULL)
		return 0;
	else return soNutNhanh(node->left)
			+ soNutNhanh(node->right) + 1;
}

int main() {
	struct Node *root = NULL;
	//			  	 8
	//		    6/         \11
	//		  2/  \7	 9/
	//	       \4
	root = insertNode(root, 8);
	
	insertNode(root, 2);
	insertNode(root, 6);
	insertNode(root, 7);
	insertNode(root, 4);
	insertNode(root, 11);
	insertNode(root, 9);
	
	printf("\nSo phan tu cua cay nhi phan la %d", size(root));
	printf("\nTong gia tri cac phan tu cua cay nhi phan la %d", sum(root));
	printf("\nGia tri lon nhat cua cay nhi phan la %d", max(root));
	
	printf("\nCac gia tri be hon 7: ");
	printKeysLess(root, 7);
	
	printf("\nChieu cao cay nhi phan la %d", height(root));
	printf("\nCac gia tri phan tu cay nhi phan IN-ORDER: ");
	printAllNodes(root);
	printf("\nCac gia tri phan tu cay nhi phan PRE-ORDER: ");
	printAllNodesPreOrder(root);
	printf("\nSo nut nhanh: %d", soNutNhanh(root));
	deleteTree(root);
	printf("\nDa xoa cay nhi phan!!");
	
}



