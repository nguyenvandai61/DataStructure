#include <stdio.h>
#include <string.h>


struct node
{	
	char truong[50];
	int socb;
	int sosv;
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
		printf("\n %-15s %3d %3d", 
		p->truong, p->socb, p->sosv);
		p = p->next;
	}
}

void sinhviennhieunhat() {
	int maxSV = 0;
	node* p = F;
	while(p!= NULL) {
		if (p->sosv > maxSV) {
			maxSV = p->sosv;
		}
		p = p->next;
	}
	
	p = F;
	while(p!= NULL) {
		if (p->sosv == maxSV) {
			printf("\n %-15s %3d %3d", 
			p->truong, p->socb, p->sosv);
		}
		p = p->next;
	}
	
	
}

void insertFirst(List &F, char *truong, int socb, int sosv) {
	node *p = new node;
	
	strcpy(p->truong, truong);
	p->socb = socb;
	p->sosv = sosv;
	
	p->next = F;
	F = p;
	n++;
}
void nhap(){
	node* p;
	do
	{
		p = new node;
	
		fflush(stdin);
		printf("Nhap ten truong: ");
		gets((*p).truong);
		if (strlen((*p).truong)==0) {
			delete p;
			break;
		}
		printf("Nhap so can bo: ");
		scanf("%d", &(*p).socb);
		printf("Nhap so sinh vien: ");
		scanf("%d", &(*p).sosv);
		
		p->next = F;
		F = p;
		n++;
	} while(true);
}


int main() {
	create(F, n);
	nhap();
	
	char truong[50] = "BACH KHOA";
	int sv = 502;
	int cb = 18;
	insertFirst(F, truong, cb, sv);
	display(F);
	printf("\nTruong co so sinh vien nhieu nhat: \n");
	sinhviennhieunhat();
	
}
