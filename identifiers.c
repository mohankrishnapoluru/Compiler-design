#include<stdio.h>
#include<conio.h>
int main()
{
	int i,idpointer=0,oppointer=0,chpointer=0;
	char a[100],id[100],op[100],ch[100];
	printf("Enter the string : ");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(isdigit(a[i]))
		{
			ch[chpointer]=a[i];
			chpointer++;
		}
		else if(isalpha(a[i]))
		{
			id[idpointer]=a[i];
			idpointer++;
		}
		else{
			op[oppointer]=a[i];
			oppointer++;
		}
	}
	printf("Identifers: ");
	for(i=0;i<idpointer;i++){
		printf("%c",id[i]);}
		printf("\nOperators: ");
	for(i=0;i<oppointer;i++){
		printf("%c",op[i]);}
	}
