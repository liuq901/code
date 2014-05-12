#include <cstdio>
#include <cstring>
int a[10],cnt[260],f[10][260][260];
void update(int &x,int y)
{
    if (x==-1 || y<x)
        x=y;
}
void init(int m)
{
    memset(cnt,-1,sizeof(cnt));
    for (int i=0;i<1<<m;i++)
    {
        int a[10]={0},p=0;
        for (int j=1;j<=m;j++)
        {
            if (!(i>>j-1&1))
                continue;
            p++;
            for (int k=j-1;k<=j+1;k++)
                if (k>0 && k<=m)
                    a[k]^=1;
        }
        int state=0;
        for (int j=1;j<=m;j++)
            state|=a[j]<<j-1;
        update(cnt[state],p);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            char s[10];
            scanf("%s",s+1);
            for (int j=1;j<=m;j++)
                a[i]|=(s[j]=='.')<<j-1;
        }
        init(m);
        int ans=-1;
        if (n==1)
            ans=cnt[a[1]];
        else
        {
            memset(f,-1,sizeof(f));
            for (int i=0;i<1<<m;i++)
                if (cnt[i]!=-1)
                    update(f[2][a[1]^i][a[2]^i],cnt[i]);
            for (int i=3;i<=n;i++)
                for (int j=0;j<1<<m;j++)
                    for (int k=0;k<1<<m;k++)
                    {
                        if (f[i-1][j][k]==-1 || cnt[j]==-1)
                            continue;
                        update(f[i][k^j][a[i]^j],f[i-1][j][k]+cnt[j]);
                    }
            for (int i=0;i<1<<m;i++)
                if (f[n][i][i]!=-1 && cnt[i]!=-1)
                    update(ans,f[n][i][i]+cnt[i]);
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

