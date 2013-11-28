#include <cstdio>
int a[1010][1010],b[1010][1010];
char op[10];
void move(int n,int m,int op)
{
    if (!op)
        return;
    if (op==1)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                b[m-j+1][i]=a[i][j];
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                a[i][j]=b[i][j];
    }
    else if (op==2)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                b[n-i+1][m-j+1]=a[i][j];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                a[i][j]=b[i][j];
    }
    else
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                b[j][n-i+1]=a[i][j];
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                a[i][j]=b[i][j];
    }
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        int now=0,Q;
        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%s",op);
            if (op[0]=='L')
            {
                int x;
                scanf("%d",&x);
                now+=x;
            }
            else if (op[0]=='R')
            {
                int x;
                scanf("%d",&x);
                now-=x;
            }
            else
            {
                now&=3;
                if (now<0)
                    now+=4;
                move(n,m,now);
                if (now&1)
                {
                    int t;
                    t=n,n=m,m=t;
                }
                for (int i=1;i<=n;i++)
                    for (int j=1;j<=m;j++)
                        printf("%d%c",a[i][j],j==m?'\n':' ');
                now=0;
            }
        }
    }
    return(0);
}

