#include <stdio.h>
#include <string.h>
void charstuff(char *data, char *sd, char *ed)
{
    char newdata[100] ="", curr[2];
    int i;
    strcat(newdata, sd);
    for ( i = 0; i < strlen(data); i++)
    {
        curr[0] = data[i];
        curr[1] = '\0';
        strcat(newdata, curr);
        if (data[i] == sd[0])
        {
            strcat(newdata, sd);
        }
        else if (data[i] == ed[0])
        {
            strcat(newdata, ed);
        }
    }
    strcat(newdata, ed);
    printf("After stuffing: %s", newdata);
}
void chardestuff(char *data, char *sd, char *ed)
{
    char temp[100] ="", curr[2];
    int i;
    for ( i = 1; i < strlen(data) - 1; i++)
    {
        curr[0] = data[i];
        curr[1] = '\0';
        strcat(temp, curr);
        if (data[i] == sd[0])
        {
            i++;
        }
        else if (data[i] == ed[0])
        {
            i++;
        }
    }
    printf("After destuffing: %s\n", temp);
}
void main()
{
    char data[100];
    char sd[2], ed[2];
    printf("enter data to be stuffed: ");
    scanf("%s", data);
    printf("enter starting delimiter: ");
    scanf("%s", sd);
    printf("enter ending delimiter: ");
    scanf("%s", ed);
    charstuff(data, sd, ed);
    printf("\nenter data to be destuffed: ");
    scanf("%s", data);
    chardestuff(data, sd, ed);
}
