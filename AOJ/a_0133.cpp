#include <cstdio>
char a[10][10],b[10][10];
int main()
{
    for (int i=1;i<=8;i++)
        scanf("%s",a[i]+1);
    for (int i=1;i<=3;i++)
    {
        for (int j=1;j<=8;j++)
            for (int k=1;k<=8;k++)
                b[k][9-j]=a[j][k];
        printf("%d\n",90*i);
        for (int j=1;j<=8;j++)
        {
            for (int k=1;k<=8;k++)
            {
                printf("%c",b[j][k]);
                a[j][k]=b[j][k];
            }
            printf("\n");
        }
    }
    return(0);
}

