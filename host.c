#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>
int main(int argc,char*argv[1])
{
	struct hostent*hen;
	if(argc!=2)
 	{ 
 		fprintf(stderr,"enter host name\n");
 	}
 	hen=gethostbyname(argv[1]);
 	if(hen==NULL)
 	{ 
 		fprintf(stderr,"host not found");
 	}
 	printf("Host name: %s \n",hen->h_name);
 	printf("IP address: %s \n",inet_ntoa(*((struct in_addr *)hen->h_addr)));
}
