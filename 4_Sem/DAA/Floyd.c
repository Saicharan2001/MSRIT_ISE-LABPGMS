#include<stdio.h>
#include<stdlib.h>
int min(int a,int b){
    if(a>b){
        return b;
    }
    return a;
}
int floyd(int r[20][20],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                r[i][j]=min(r[i][j],r[i][k]+r[k][j]);
            }
        }
    }
}
void main(){
    int r[20][20],n;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&r[i][j]);
        }
    }
    floyd(r,n);
    printf("The floyd matrix is\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",r[i][j]);
        }
        printf("\n");
    }
}