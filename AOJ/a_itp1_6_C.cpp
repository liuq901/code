#include <cstdio>
int a[100][100][100];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y,z,p;
        scanf("%d%d%d%d",&x,&y,&z,&p);
        a[x][y][z]+=p;
    }
    for (int i=1;i<=4;i++)
    {
        for (int j=1;j<=3;j++)
        {
            for (int k=1;k<=10;k++)
                printf(" %d",a[i][j][k]);
            printf("\n");
        }
        if (i!=4)
            printf("####################\n");
    }
    return(0);
}

