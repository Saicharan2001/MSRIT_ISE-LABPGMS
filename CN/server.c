#include<stdio.h>
#include<unistd.h> //The <unistd.h> header defines miscellaneous symbolic constants and types, and declares miscellaneous functions. 
#include<fcntl.h> // file control options
#include<sys/types.h> // data types
#include<sys/stat.h>
#include<sys/socket.h> //types of sockets
#include<netinet/in.h> //Internet address family
#include<stdlib.h>
#include<arpa/inet.h> //definitions for internet operations
int main(){
	int cs,ns,fd,n;
	int buffsize=1024;
	char *buffer=malloc(buffsize);
	struct sockaddr_in address;
	char fname[255];
	address.sin_family=AF_INET;
	address.sin_port=htons(15000);
	address.sin_addr.s_addr=INADDR_ANY;
	// INADDR_ANY : This is an IP address that is used when we 
	//don't want to bind a socket to any specific IP. When we don't know the IP address of our machine, we can use the special IP address INADDR_ANY.It allows our server 
	//to receive packets that have been targeted by any of the interfaces.
	cs=socket(AF_INET,SOCK_STREAM,0);
	bind(cs,(struct sockaddr*)&address,sizeof(address));
	listen(cs,5);
	//The listen() call indicates a readiness to accept client connection requests. It transforms an active socket into a passive socket
	ns=accept(cs,(struct sockaddr*)NULL,NULL);
	// (ACCEPT CALL)SECOND PARAMTER : it is an output parameter, you can send it or not, but when you send it, it will be filled with the the connecting socket.
	recv(ns,fname,255,0);
	fd=open(fname,O_RDONLY);
	n=read(fd,buffer,buffsize);
	send(ns,buffer,n,0);
	return close(ns);
}
// ACCEPT AND BIND HAVE SAME PARAMETERS
// SOCKET CREATION , BINDING , LISTEN , ACCEPT , RECV , [OPEN , READ , SEND] 