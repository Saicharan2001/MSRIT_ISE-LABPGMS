// Implement Blocking send and receive functions.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mpi.h>

void main(int argc,char*argv[]){
    char outmsg[100]="Hi hello";
    char inmsg[100];

    MPI_Status stat;
    int myrank,size,dest,source,tag,rc;l
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if(myrank==0){
        dest=1;
        tag=2;
        MPI_Send(&outmsg,strlen(outmsg),MPI_CHAR,dest,tag,MPI_COMM_WORLD);
    }
    else if(myrank==1){
        source=0;
        tag=2;
        MPI_Recv(&inmsg,strlen(outmsg),MPI_CHAR,source,tag,MPI_COMM_WORLD,&stat);
    }
    rc=MPI_Get_Count(&stat,MPI_CHAR,&count);
    printf("Task %d and received %s from %d with tag %d",myrank,inmsg,stat.MPI_SOURCE,stat.MPI_TAG);
    MPI_Finalize();
}