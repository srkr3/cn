#include <stdio.h>
#include <string.h>
char data[50], newdata[100], temp[50];
void bitstuffing()
{
    int i, count = 0, j = 0;
    for (i = 0; i < strlen(data); i++)
    {
        if (data[i] == '1')
        {
            count++;
            newdata[j++] = data[i];
        }
        else
        {
            count = 0;
            newdata[j++] = data[i];
        }
        if (count == 5)
        {
            count = 0;
            newdata[j++] = '0';
        }
    }
    newdata[j] = '\0';
    printf("stuffed data is: %s", newdata);
}
void bitdestuffing()
{
    int i, count = 0, j = 0;
    for (i = 0; i < strlen(newdata); i++)
    {
        if (newdata[i] == '1')
        {
            count++;
            temp[j++] = newdata[i];
        }
        else
        {
            count = 0;
            temp[j++] = newdata[i];
        }
        if (count == 5)
        {
            count = 0;
            i++;
        }
    }
    temp[j] = '\0';
    printf("\nthe destuffed data is: %s", temp);
}
void main()
{
    printf("enter data to be stuffed: ");
    scanf("%s", data);
    bitstuffing();
    bitdestuffing();
}
