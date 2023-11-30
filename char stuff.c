#include<stdio.h>
#include<string.h>
int main()
{ 
	char a[30],c[30]="",b[50]="",t[3],t1[3],start,end,x[3],s[3],d[3],y[3];
	int i,j;
 	printf("Enter characters to be stuffed : ");
 	scanf("%s",&a);
 	printf("\nEnter starting delimiter : ");
 	scanf(" %c",&start);
 	printf("\nEnter ending delimiter : ");
 	scanf(" %c",&end);
 	x[0]=s[0]=s[1]=start;
 	x[1]=s[2]='\0';
 	y[0]=d[0]=d[1]=end;
 	y[1]=d[2]='\0';
 	strcat(b,x);
 	for(i=0;i<strlen(a);i++)
	{
		t[0]=a[i];
		t[1]='\0';
		
 		if(t[0]==start)
 			strcat(b,s);
 		else if(t[0]==end)
 			strcat(b,d);
 		else
			strcat(b,t); 
	}
 	strcat(b,y);
 	printf("\nAfter stuffing : %s\n\n",b);
 	
 	
 	for (i = 0; i < strlen(b); i++) {
        t[0] = b[i];
        t[1] = b[i+1];
        t[2]='\0';
        
        if (strcmp(t, s) == 0) {
            i++;
        } else if (strcmp(t, d) == 0) {
            i++;
        } else {
        //	t1[0] = t[0];
        //	t1[1] = '\0';
            strcat(c, t);
        }
    }

    printf("\nAfter destuffing: %s\n\n", c);
}

