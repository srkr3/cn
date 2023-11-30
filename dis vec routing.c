#include<stdio.h>
struct node
{ 
	int dist[20];
 	int from[20];
}rt[10];
int main()
{
 	int costmat[20][20];
 	int nodes,i,j,k,count=0;
 	printf("\nEnter the number of nodes : ");
 	scanf("%d",&nodes);
 	printf("\nEnter the cost matrix :\n");
 	for(i=0;i<nodes;i++)
 	{ 
	 	for(j=0;j<nodes;j++)
 		{ 	
			scanf("%d",&costmat[i][j]);
 			costmat[i][i]=0;
 			rt[i].dist[j]=costmat[i][j];
 			rt[i].from[j]=j;
 		} 
	}
 	for(i=0;i<nodes;i++)
 		for(j=0;j<nodes;j++)
 			for(k=0;k<nodes;k++)
 				if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
 				{
				 	rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
 					rt[i].from[j]=k; 
				}
 	for(i=0;i<nodes;i++)
 	{ 
	 	printf("\n\n For router %c\n",64+i+1);
 		for(j=0;j<nodes;j++)
 		{
 			printf("\t\nnode %c via %c Distance %d ",64+j+1,64+rt[i].from[j]+1,rt[i].dist[j]);
 		} 
	}
 	printf("\n\n"); 
}

