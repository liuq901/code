#include <cstdio>
bool a[110];
int main()
{
    while (1)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        if (n==0 && m==0 && K==0)
            break;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int id,x,y;
            scanf("%d%d%d",&id,&x,&y);
            ans+=x+y;
            a[i]=true;
        }
        for (int i=1;i<=m;i++)
        {
            int id,x;
            scanf("%d%d",&id,&x);
            if (x>=K && a[id])
            {
                ans++;
                a[id]=false;
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

