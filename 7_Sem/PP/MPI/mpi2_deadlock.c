// Demonstrate deadlock and implement a solution to avoid deadlock

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

void main(int argc,char *argv[]){
    MPI_Status stat;
    MPI_Request req;
    int tag1=1,tag2=2,dest,source,size,rank,count=1;;
    int outmsg=77;
    int inmsg;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0){
        dest=1;
        MPI_Send(&outmsg,count,MPI_INT,dest,tag1,MPI_COMM_WORLD);
        source=1;
        MPI_Recv(&inmsg,count,MPI_INT,source,tag2,MPI_COMM_WORLD,&stat);
    }
    else if(rank==1){
        source=0;
        MPI_Recv(&inmsg,count,MPI_INT,source,tag1,MPI_COMM_WORLD,&stat);
        dest=0;
        MPI_Send(&outmsg,count,MPI_INT,dest,tag2,MPI_COMM_WORLD);
    }
    printf("Task %d received %d from source %d\n",rank,inmsg,stat.MPI_SOURCE);
    MPI_Finalize();
}