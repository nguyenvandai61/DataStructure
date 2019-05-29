#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;


struct node
{	
	char mssv[8];
	char tensv[50];
	float dtb;
	char loaitn;
	node* next;
};
typedef node* List;
List F;
int n;


void create(List &F, int &n) {
	F = NULL;
	n = 0;
}
void display(List F) {
	node* p = F;
	while (p!=NULL) {
		printf("\n %8s %30s %6.2f %3c", 
		(*p).mssv, (*p).tensv, (*p).dtb, (*p).loaitn);
		p = p->next;
	}
}
char xeploai(float dtb) {
	if (dtb >= 9) return 'X';
	else if (dtb >= 8) return 'G';
	else if (dtb >= 7) return 'K';
	else if (dtb >= 5) return 'T';
	else return 'Y';
}
void insertFirst(List &F, char *mssv, char *tensv, float dtb) {
	node *p = new node;
	
	strcpy(p->mssv, mssv);
	strcpy(p->tensv, tensv);
	p->dtb = dtb;
	p->loaitn = xeploai(dtb);
	
	p->next = F;
	F = p;
	n++;
}
void nhap(){
	char mssv[8];
	char tensv[50];
	float dtb;
	do
	{
		fflush(stdin);
		printf("Nhap MSSV: ");
		gets(mssv);
		if (strlen(mssv)==0)
			break;
		fflush(stdin);
		printf("Nhap ho va ten: ");
		gets(tensv);
		printf("Nhap TB tich luy: ");
		scanf("%f", &dtb);
		
		insertFirst(F, mssv, tensv, dtb);
	} while(true);
}
void xoayeu(List &F) {
	node* p = F;
	if (n == 1 && p->loaitn == 'Y') {
		delete p;
		F = NULL;
	}
	while(p->next!=NULL) {
		if ((p->next)->loaitn == 'Y') {
			node* pnext = p->next;
			p->next = pnext->next;
			delete pnext;
		}
		p = p->next;
	}
}

int main() {
	create(F, n);
	char mssv[8] = "1";
	char tensv[50] ="NguyenVanDai";
	float dtb=8.0;
	
	insertFirst(F, mssv, tensv, dtb);
	strcpy(mssv, "2");
	strcpy(tensv, "NguyenVan");
	dtb=2.0;
	
	insertFirst(F, mssv, tensv, dtb);
	
	strcpy(mssv, "3");
	strcpy(tensv, "Nguyen");
	dtb=8.0;
	
	insertFirst(F, mssv, tensv, dtb);
	
	display(F);
	xoayeu(F);
	printf("\nKet qua xoa yeu: ");
	display(F);
}
