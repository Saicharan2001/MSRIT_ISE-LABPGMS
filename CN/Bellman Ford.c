#include <stdio.h>  //TIME COMPLEXITY IS O(N^2) AT BEST CASE AND O(N^3) IS WORST CASE
#include <stdlib.h>
int Bellman_Ford(int G[20][20] , int V, int E, int edge[20][2])
{
    int i,u,v,k,distance[20],S,flag=1;
    for(i=0;i<V;i++)
        distance[i] = 1000;
    printf("Enter source: ");
    scanf("%d",&S);
    distance[S-1]=0 ;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v];
        }
    }
    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                flag = 0 ;
        }
        if(flag)
            for(i=0;i<V;i++)
                printf("Vertex %d -> cost = %d\n",i+1,distance[i]);

        return flag;
}
int main()
{
    int V,edge[20][2],G[20][20],i,j,k=0;
    printf("BELLMAN FORD\n");
    printf("Enter no. of vertices: ");
    scanf("%d",&V);
    printf("Enter graph in matrix form:\n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]!=0)
                edge[k][0]=i,edge[k++][1]=j;
        }
     }
    if(Bellman_Ford(G,V,k,edge))
        printf("\nNo negative weight cycle\n");
    else printf("\nNegative weight cycle exists\n");
    return 0;
}

//BELLMAN FORD ALGO WORKS WELL EVEN IF THEIR ARE NEGATIVE EDGES
//DIJKSTRA ALGO MAY OR MAYNOT PRODUCE CORRECT WHEN THERE ARE NEGATIVE EDGES
// OUTPUT:

// BELLMAN FORD
// Enter no. of vertices: 5
// Enter graph in matrix form:
// 0 2 0 0 2
// 0 0 6 0 0 
// 0 0 0 8 0
// 9 0 0 0 10
// 0 0 0 0 0
// Enter source: 1
// Vertex 1 -> cost = 0
// Vertex 2 -> cost = 2
// Vertex 3 -> cost = 8
// Vertex 4 -> cost = 16
// Vertex 5 -> cost = 2

// No negative weight cycle

// #include<stdio.h>
// #include<stdlib.h>
// int Bellman_Ford(int G[20][20],int V,int E,int edge[20][2]){
//     int distance[20],flag=1,S;
//     for(int i=0;i<V;i++){
//         distance[i]=1000;
//     }
//     printf("Enter source node\n");
//     scanf("%d",&S);
//     distance[S-1]=0;
//     for(int i=0;i<(V-1);i++){
//         for(int k=0;k<E;k++){
//             int u=edge[k][0];
//             int v=edge[k][1];
//             if(distance[u]+G[u][v]<distance[v]){
//                 distance[v]=distance[u]+G[u][v];
//             }
//         }
//     }
//     for(int k=0;k<E;k++){
//             int u=edge[k][0];
//             int v=edge[k][1];
//             if(distance[u]+G[u][v]<distance[v]){
//                 flag=0;
//             }
//     }
//     if(flag){
//         printf("the distances\n");
//         for(int i=0;i<V;i++){
//             printf("The distance of %d is %d\n",i+1,distance[i]);
//         }
//     }
//     return flag;
    
// }
// int main(){
//     int G[20][20],edge[20][2],V,k=0;
//     printf("Bellman_Ford");
//     printf("Enter the number of vertices\n");
//     scanf("%d",&V);
//     printf("Enter the graph\n");
//     // for(int i=0;i<V;i++){
//     //     for(int j=0;j<V;j++){
//     //         scanf("%d",&G[i][j]);
//     //         if(G[i][j]!=0){
//     //             edge[k][0]=i;
//     //             edge[k++][1]=j;
//     //         }
//     //     }
//     // }
//     for(int i=0;i<V;i++){
//         for(int j=0;j<V;j++)
//         {
//             scanf("%d",&G[i][j]);
//             if(G[i][j]!=0)
//                 edge[k][0]=i,edge[k++][1]=j;
//         }
//      }
//     if(Bellman_Ford(G,V,k,edge)){
//         printf("No negative cyclse\n");
//     }
//     else{
//         printf("there are negative cycles\n");
//     }
//     return 0;
// }