#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int l[110],a[110][10];
struct packet
{
    int s,d,t,id,finish;
    void calc(int limit)
    {
        int x=s,now=t;
        for (int i=0;i<=limit;i++)
        {
            if (x==d)
            {
                finish=now;
                return;
            }
            x=a[x][now%l[x]];
            now++;
        }
        finish=inf;
    }
};
inline bool operator <(const packet &a,const packet &b)
{
    return(a.finish<b.finish);
}
packet p[110];
bool vis[110][85010];
bool go(const packet &p,bool first)
{
    int x=p.s,now=p.t;
    while (1)
    {
        if (first && vis[x][now])
            return(false);
        if (!first)
            vis[x][now]=true;
        if (x==p.d)
            break;
        x=a[x][now%l[x]];
        now++;
    }
    return(true);
}
int main()
{
    freopen("hot.in","r",stdin);
    freopen("hot.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&l[i]);
        for (int j=0;j<l[i];j++)
            scanf("%d",&a[i][j]);
    }
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&p[i].s,&p[i].d,&p[i].t);
        p[i].id=i;
        p[i].calc(n*840+26);
    }
    sort(p+1,p+m+1);
    vector <int> ans;
    for (int i=1;i<=m;i++)
    {
        if (p[i].finish==inf)
            break;
        if (go(p[i],true))
        {
            ans.push_back(p[i].id);
            go(p[i],false);
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
    return(0);
}

