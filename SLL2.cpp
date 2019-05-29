#include <stdio.h>
#define TRUE 1

//this function will get the string array
//and split into the words, seprated by spaces

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
int main()
{
	int n; //number of words
	int i; //loop counter 
	char str[]="This is Mike";
	char arr[10][20];
	
	n=getWords(str,arr);
	
	for(i=0;i<=n;i++)
		printf("%s\n",arr[i]);
	
	return 0;
}
