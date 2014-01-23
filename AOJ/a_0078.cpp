#include <cstdio>
#include <cstring>
int n,a[20][20];
void next(int &x,int &y,int x0,int y0)
{
    x=x0,y=y0;
    if (x==0)
        x=n;
    if (x>n)
        x=1;
    if (y==0)
        y=n;
    if (y>n)
        y=1;
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        memset(a,0,sizeof(a));
        int x=n/2+2,y=n/2+1;
        for (int i=1;i<=n*n;i++)
        {
            a[x][y]=i;
            next(x,y,x+1,y+1);
            if (a[x][y]!=0)
                next(x,y,x+1,y-1);
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                printf("%4d",a[i][j]);
            printf("\n");
        }
    }
    return(0);
}

