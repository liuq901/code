#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> c;
int s,ans0,ans1,a[50];
void dfs(int dep,int limit,int now,bool first,int mi,int ma)
{
    if (first && (now<0 || now>s))
        return;
    else
    {
        mi=min(mi,now);
        ma=max(ma,now);
    }
    if (dep==limit+1)
    {
        if (first)
            c.push_back(now);
        else
        {
            int l=-mi,r=s-ma;
            int x=lower_bound(c.begin(),c.end(),l)-c.begin(),y=upper_bound(c.begin(),c.end(),r)-c.begin()-1;
            if (x<=y)
            {
                ans0=min(ans0,c[x]+now);
                ans1=max(ans1,c[y]+now);
            }
        }
        return;
    }
    dfs(dep+1,limit,now+a[dep],first,mi,ma);
    dfs(dep+1,limit,now-a[dep],first,mi,ma);
}
int main()
{
    int n,m;
    scanf("%d%d%d",&s,&n,&m);
    int m1=m>>1;
    for (int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    ans0=1<<30,ans1=-1;
    dfs(1,m1,n,true,0,0);
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    dfs(m1+1,m,0,false,0,0);
    printf("%d %d\n",ans0,ans1);
    return(0);
}

