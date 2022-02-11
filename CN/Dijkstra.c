#include<stdio.h>
#define infinite 999
void dij(int n,int v,int cost[10][10],int dist[10]){
	int i,u,count,w,flag[10],min;
	for(int i=1;i<=n;i++){
		flag[i]=0;
		dist[i]=cost[v][i]; //DISTANCE FROM SOURCE VERTEX TO THE RESPECTIVE VERTICES
	}  
	count=2;
	while(count<=n){
		min=99;
		for(w=1;w<=n;w++){  //SELECTING THE VERTEX WITH MINIMUM DISTANCE FROM THE SOURCE NODE
			if(dist[w]<min && !flag[w]){
				min=dist[w];
				u=w;
			}
		}
		flag[u]=1;
		count++;
		for(w=1;w<=n;w++){
			if((dist[u]+cost[u][w]<dist[w]) && !flag[w]){
				dist[w]=dist[u]+cost[u][w];
			}
		}
	}
}
void main(){
	int n,v,i,j,cost[10][10],dist[10];
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");  //Cost is 0 if there is no direct path between the vertices
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){
				cost[i][j]=infinite;
			}
		}
	}
	printf("Enter the source node\n");
	scanf("%d",&v);
	dij(n,v,cost,dist);
	printf("Shortest path:\n");
	for(int i=1;i<=n;i++){
		if(i!=v){
			printf("%d--->%d,cost=%d\n",v,i,dist[i]);
		}
	}

}

// OUTPUT:

// Enter the number of nodes
// 5
// Enter the cost matrix
// 0 2 5 0 0
// 0 0 2 0 0
// 0 0 0 9 0
// 0 0 0 0 0
// 0 0 0 0 0
// Enter the source node
// 1
// Shortest path:
// 1--->2,cost=2
// 1--->3,cost=4
// 1--->4,cost=13
// 1--->5,cost=999