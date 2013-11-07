#include <cstdio>
#include <cstring>
int f[10010];
inline void update(int &x,int y)
{
    if (x==-1 || y<x)
        x=y;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        m-=n;
        scanf("%d",&n);
        memset(f,-1,sizeof(f));
        f[0]=0;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for (int j=y;j<=m;j++)
                if (f[j-y]!=-1)
                    update(f[j],f[j-y]+x);
        }
        if (f[m]==-1)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",f[m]);
    }
    return(0);
}

