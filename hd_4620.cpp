#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
struct data
{
    bitset <200> f;
    int id,t;
};
inline bool operator <(const data &a,const data &b)
{
    return(a.t<b.t);
}
data a[40];
int lq,best,n,m,ans,now,p[40];
void dfs(int dep,const bitset <200> &f,int cur)
{
    if (n-dep+1+now<=ans)
        return;
    if (now>ans)
    {
        ans=now;
        lq=best;
    }
    if (dep==n+1)
        return;
    for (int i=dep;i<=n;i++)
    {
        if (cur!=-1 && cur+m<a[i].t)
            break;
        if (a[i].f.count()-(a[i].f&f).count()<3)
            continue;
        now++;
        best^=1<<a[i].id-1;
        dfs(i+1,f|a[i].f,a[i].t);
        now--;
        best^=1<<a[i].id-1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%*d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            int K;
            scanf("%d%d",&K,&a[i].t);
            a[i].id=i;
            a[i].f.reset();
            for (int j=1;j<=K;j++)
            {
                int x;
                scanf("%d",&x);
                a[i].f[x]=1;
            }
        }
        sort(a+1,a+n+1);
        bitset <200> tmp;
        tmp.reset();
        ans=0;
        dfs(1,tmp,-1);
        printf("%d\n",ans);
        bool first=true;
        for (int i=1;i<=n;i++)
            if (lq>>i-1&1)
            {
                if (!first)
                    printf(" ");
                first=false;
                printf("%d",i);
            }
        if (ans!=0)
            printf("\n");
    }
    return(0);
}

