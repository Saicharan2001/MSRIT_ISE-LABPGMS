#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
int main(int argc,char **argv){
	int cs,n;
	int buffsize=1024;
	char *buffer=malloc(buffsize);
	char fname[255];
	struct sockaddr_in address;  // The SOCKADDR_IN structure specifies a transport address and port for the AF_INET address family.
	address.sin_family=AF_INET;  // The address family of transport addresses
	address.sin_port=htons(15000);  //A transport protocol port number
	inet_pton(AF_INET,argv[1],&address.sin_addr); // sin_addr : An IN_ADDR structure that contains an IPv4 transport address.
	//inet_pton : inet_pton - convert IPv4 and IPv6 addresses from text to binary
      // form
	//The socket() call creates a socket in the specified domain and of the specified type
	cs=socket(AF_INET,SOCK_STREAM,0); //types--SOCK_STREAM, SOCK_DGRAM, or SOCK_RAW-
	connect(cs,(struct sockaddr *)&address,sizeof(address));
	//Connection to a remote address is created with connect() call.
	//– connect(sockfd,$(struct$sockaddr$*)$&saddr,$sizeof
//(saddr));
	//All client need to do is to connect
	//Client'need'not'bind,'listen,'and'accept
	printf("Enter filename\n");
	scanf("%s",fname);
	send(cs,fname,255,0);	
	while(recv(cs,buffer,buffsize,0)>0){
		printf("%s\n",buffer);
	}
	// printf("\nEOF\n");
	return close(cs);
}

// SOCKET CREATION , CONNECT , SEND , RECV

// #include <stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<fcntl.h>
// #include<sys/stat.h>
// #include<sys/socket.h>
// #include<sys/types.h>
// #include<netinet/in.h>
// #include<arpa/inet.h>
// int main(int argc,char**argv)
// {
//     int cs,n;
//     int buffsize=1024;
//     char *buffer=malloc(buffsize);
//     char fname[255];
//     struct sockaddr_in address;
//     address.sin_family=AF_INET;
//     address.sin_port=htons(15000);
//     inet_pton(AF_INET,argv[1],&address.sin_addr);
//     cs=socket(AF_INET,SOCK_STREAM,0);
//     connect(cs,(struct sockaddr*)&address,sizeof(address));
//     printf("Enter filename\n");
//     scanf("%s",fname);
//     send(cs,fname,255,0);
//     while(recv(cs,buffer,buffsize,0)>0){
//         printf("%s\n",buffer);
//     }
//     return close(cs);
//     // return 0;
// }
