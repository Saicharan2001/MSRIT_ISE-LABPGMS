//  Factorial of a number using Broadcast and Reduce operation.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

void main(int argc , char *argv[]){
    int root=0,rank,size;
    int n=7;
    int global=1;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    MPI_Bcast(&n,1,MPI_INT,root,MPI_COMM_WORLD);
    int localprod=1;
    int len=(n/size)+1;
    for(int i=1;i<=len;i++){
        int val=(rank*len)+i;
        printf("rank %d val %d\n",rank,val);
        if(val<=n){
            localprod=localprod*val;
        }
        else{
            break;
        }
    }
    printf("LOCALPROD %d\n",localprod);
    MPI_Reduce(&localprod,&global,1,MPI_INT,MPI_PROD,root,MPI_COMM_WORLD);
    if(rank==root){
        printf("Factorial of %d is %d\n",n,global);
    }
    MPI_Finalize();
}