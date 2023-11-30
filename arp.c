#include <sys/types.h>
#include <sys/socket.h>
#include <net/if_arp.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <complex.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include <stdlib.h>
int main(int argc ,char* argv[])
{
	struct sockaddr_in saddr;
	struct arpreq myarp={{0}};
	unsigned char *ptr;
	
	saddr.sin_family=AF_INET;
	if(inet_aton(argv[1],&saddr.sin_addr)==0)
	{
		printf("IP address Entered '%s' is not valid \n",argv[1]);
		exit(0);
	}
	memcpy(&myarp.arp_pa,&saddr,sizeof(myarp.arp_pa));
	strcpy(myarp.arp_dev,"echo");
	
	ptr=&myarp.arp_pa.sa_data[0];
	printf("MAC Address for '%s' : ",argv[1]);
	printf("%x:%x:%x:%x:%x:%x\n",*ptr,*(ptr+1),*(ptr+2),*(ptr+3),*(ptr+4),*(ptr+5));
	return 0;
}
