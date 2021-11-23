/*BFS is more suitable for searching vertices which are closer to the given source. ...
The Time complexity of BFS is O(V + E) when Adjacency List is used and O(V^2) when Adjacency Matrix is used,
where V stands for vertices and E stands for edges*/

#include<stdio.h>
#include<stdlib.h>
void BFS(int[20][20],int,int[20],int);
void main(){
    int a[20][20],visited[20],source,n;
    printf("Enter the no of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency Matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        visited[i]=0;
    }
    printf("enter the source\n");
    scanf("%d",&source);
    visited[source]=1;
    BFS(a,source,visited,n);
    for(int i=1;i<=n;i++){
        if(visited[i]!=0){
            printf("Node %d is reachable\n",i);
        }
        else{
            printf("Node %d is not reachable\n",i);
        }
    }
}
void BFS(int a[20][20],int source,int visited[20],int n){
    int queue[20],f,r,u,v;
    f=0;
    r=-1;
    queue[++r]=source;
    while(f<=r){
        u=queue[f++];
        for(v=1;v<=n;v++){
            if(a[u][v]==1 && visited[v]==0){
                visited[v]=1;
                queue[++r]=v;
            }
        }
    }
}