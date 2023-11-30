#include<stdio.h>
int main()
{
	int w,f,i,frame[50];
	printf("enter the window size : ");
	scanf("%d",&w);
	printf("enter no.of frames to transfer : ");
	scanf("%d",&f);
	printf("enter frames : ");
	for(i=1;i<=f;i++)
	{
		scanf("%d",&frame[i]);
	}
	for(i=1;i<=f;i++)
	{
		if(i%w==0)
		{
			printf("%d : ",frame[i]);
 			printf("Acknowledgement of above frames sent is received by sender\n");
		}
		else
 			printf("%d ",frame[i]);
	}
	if(f%w!=0)
		printf("Acknowledgement of above frames sent is received by sender\n");
}
