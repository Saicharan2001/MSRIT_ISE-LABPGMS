#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 128
int t[MAX];
void shifttable(char p[]){
	int i,j,m;
	m=strlen(p);
	for(i=0;i<MAX;i++){
		t[i]=m;
	}
	for(j=0;j<m-1;j++){
		t[p[j]]=m-j-1;
	}

}
int horspool(char src[],char p[]){
	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	i=(m-1);
	while(i<n){
		k=0;
		while((k<m) && (p[m-1-k]==src[i-k]))
		{
			k++;
		}
			if (k==m){
				return (i-m+1);
			}
			else{
				i=i+t[src[i]];
			}
	}
	return -1;
}
void main(){
	char src[150],p[150];
	printf("Enter the source\n");
	gets(src);
	printf("Enter the pattern\n");
	gets(p);
	shifttable(p);
	int pos=horspool(src,p);
	if(pos<0){
		printf("The given pattern is not in the text\n");
	}
	else{
		printf("The given pattern is at %d\n",pos+1);
	}
}