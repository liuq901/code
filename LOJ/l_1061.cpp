#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> all[100][8];
int tot,cnt[260];
bool f1[10],f2[20],f3[20];
void dfs(int dep)
{
    if (dep==9)
    {
        tot++;
        for (int i=0;i<8;i++)
            all[tot][i]=all[0][i];
        return;
    }
    for (int i=1;i<=8;i++)
    {
        if (f1[i] || f2[i+dep] || f3[i-dep+8])
            continue;
        f1[i]=f2[i+dep]=f3[i-dep+8]=true;
        all[0][dep-1]=make_pair(dep,i);
        dfs(dep+1);
        f1[i]=f2[i+dep]=f3[i-dep+8]=false;
    }
}
void init()
{
    for (int i=0;i<1<<8;i++)
        cnt[i]=__builtin_popcount(i);
    dfs(1);
}
char a[10][10];
pair <int,int> b[8];
int f[260];
inline int dist(int x1,int y1,int x2,int y2)
{
    if (x1==x2 && y1==y2)
        return(0);
    if (x1==x2 || y1==y2 || x1+y1==x2+y2 || x1-y1==x2-y2)
        return(1);
    return(2);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=8;i++)
            scanf("%s",a[i]+1);
        int t=0;
        for (int i=1;i<=8;i++)
            for (int j=1;j<=8;j++)
                if (a[i][j]=='q')
                    b[t++]=make_pair(i,j);
        int ans=1<<30;
        for (int i=1;i<=92;i++)
        {
            memset(f,63,sizeof(f));
            f[0]=0;
            for (int j=0;j<1<<8;j++)
            {
                int now=cnt[j];
                for (int k=0;k<8;k++)
                {
                    if (j>>k&1)
                        continue;
                    f[j|1<<k]=min(f[j|1<<k],f[j]+dist(all[i][now].first,all[i][now].second,b[k].first,b[k].second));
                }
            }
            ans=min(ans,f[(1<<8)-1]);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

