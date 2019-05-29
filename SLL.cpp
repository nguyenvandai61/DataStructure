#include <bits/stdc++.h> 
#include <stdlib.h>
#define TRUE 1
using namespace std; 

typedef struct Node {
	string name;
	int marks;
	struct Node *next;
}List;

void InsertFirst(List *& head, string vname, int vmarks){
	Node* temp = new Node();
	temp->name = vname;
	temp->marks = vmarks;
	temp->next = head;
	
	head = temp;
}
void DeleteFirst(List *& head) {
	Node* prev = head;
	head = head->next;
	delete prev;
}

int CountEle(List *head) {
	Node* p = head;
	int res = 0;
	if (p == NULL) return res;
	while (p != NULL) {
		res++;
		p = p->next;
	}
	return res;  
}

int Count(List * head, int vmarks) {
	Node* p = head;
	int res = 0;
	if (p == NULL) return res;
	while (p != NULL) {
		if (p->marks == vmarks)
			res++;
		p = p->next;
	}
	return res;  
}

int getWords(char *base, char target[10][20])
{
	int n=0,i,j=0;
	
	for(i=0;TRUE;i++)
	{
		if(base[i]!=' '){
			target[n][j++]=base[i];
		}
		else{
			target[n][j++]='\0';//insert NULL
			n++;
			j=0;
		}
		if(base[i]=='\0')
		    break;
	}
	return n;
	
}

int main() {
	Node* head = NULL;
	
	char s[]="ins hoa 50";
	char arr[10][20];
	int n=getWords(s,arr);
	
	for(int i=0;i<=n;i++)
		printf("%s\n",arr[i]);
	while (TRUE) 
	{
		if (arr[0] == "fin") break;
		if (arr[0] == "ins") {
			char name[50];
			int mark;
			cout << arr[1] << arr[2];
			InsertFirst(head, arr[1], atoi(arr[2]));
			
			break;
		}
		cout << CountEle(head);
		break;
	}
	
}
