#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int warshall(int r[20][20],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                r[i][j]=max(r[i][j],r[i][k]&&r[k][j]);
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
    warshall(r,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",r[i][j]);
        }
        printf("\n");
    }
}