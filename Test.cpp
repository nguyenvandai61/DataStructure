#include<stdio.h>
#include <bits/stdc++.h>
#include<conio.h>
#include<string.h>
using namespace std;
typedef char infor1[30];
typedef float infor2;
typedef int infor3;
struct SV
{
	infor1 hoten;
	infor2 chieucao;
	infor3 cntc;
	SV *next;
};
typedef SV *List;
List F;
List p;
void Create(List &F)
{
	F=NULL;
}

void InsertFirst(List &F, SV sv) {
	strcpy(p->hoten, sv.hoten);
	p->chieucao = sv.chieucao;
	p->cntc = sv.cntc;
	
	p->next = F;
	F = p;
}
void Output(List F);
List Input(int &n)
{
	
	int i;
	printf("Nhap so sinh vien:  "); scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		p=new SV; // cai nay chi duoc dat o day
	
		printf("\nNhap ho ten:"); fflush(stdin); gets((*p).hoten);
		printf("\nNhap chieu cao:"); scanf("%f",&(*p).chieucao);
		(*p).cntc=(*p).chieucao*100-105;
		printf("\nCan nang tieu chuan: %d",(*p).cntc);
		
		InsertFirst(F, (*p));
	} 	
}
void Output(List F)
{
	p = F;
	
	while (p!=NULL) {
		printf("\nBan %s cao %2fm nang %2dkg",(*p).hoten,(*p).chieucao,(*p).cntc);
		p = p->next;
	}	
}
int main()
{
	
	int n;
	Input(n);
	Output(F);
	return 0;
}
