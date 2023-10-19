#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j=0;
	char a[100],b[100],c[200];
	printf("Enter production: ");
	gets(a);
	if(isupper(a[3])){
	
	gets(b);
	gets(c);}
	if(isupper(a[3])){
		printf("%c",a[4]);}
	else
	{
		printf("%c",a[3]);
	}
	if(isupper(b[3])){
		printf("%c",b[4]);}
	else if(b[3] =='$')
	{
		printf("$");
	}
	else
	{
		printf("%c",b[3]);
	}
	if(isupper(c[3])){
		printf("%c",c[4]);}
		else if(b[3] =='$')
	{
		printf("$");
	}
	else
	{
		printf("%c",c[3]);
	}
	
}
