#include <cstdio>
const int m=320;
int n,p[100010],a[100010],b[100010],ans[100010],last[100010];
void work(int x)
{
    for (int i=x+m-1;i>=x;i--)
    {
        if (i>n)
            continue;
        int y=i+a[i];
        if (y>n)
        {
            b[i]=n+1;
            ans[i]=1;
            last[i]=i;
        }
        else if (y<x+m)
        {
            b[i]=b[y];
            ans[i]=ans[y]+1;
            last[i]=last[y];
        }
        else
        {
            b[i]=y;
            ans[i]=1;
        }
    }
}
int main()
{
    int Q;
    scanf("%d%d",&n,&Q);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i+=m)
        work(i);
    for (int i=1;i<=n;i++)
    {
        p[i]=p[i-1];
        if (i%m==1)
            p[i]=i;
    }
    while (Q--)
    {
        int op;
        scanf("%d",&op);
        if (op==0)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
            work(p[x]);
        }
        else
        {
            int x,t=0,k;
            scanf("%d",&x);
            for (int i=x;i<=n;i=b[i])
                t+=ans[i],k=last[i];
            printf("%d %d\n",k,t);
        }
    }
    return(0);
}

