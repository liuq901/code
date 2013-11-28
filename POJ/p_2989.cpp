#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
int n,ans,d[130],c[130],p[130];
bitset <128> in,out,a[130];
vector <int> now;
vector <bitset <128> > must;
bool dfs(int dep,int t)
{
    if (dep==now.size())
    {
        ans++;
        return(ans>1000);
    }
    int x=now[dep];
    if ((in&a[x])==in)
    {
        in.set(x);
        if (dfs(dep+1,t))
            return(true);
        in.reset(x);
    }
    must.push_back(~a[x]);
    out.set(x);
    bool flag=true;
    for (int i=0;i<must.size();i++)
        if ((must[i]&out)==must[i])
        {
            flag=false;
            break;
        }
    if (flag && dfs(dep+1,t))
        return(true);
    must.pop_back();
    out.reset(x);
    return(false);
}
bool calc(int x)
{
    must.clear();
    now.clear();
    in.reset();
    out.reset();
    for (int i=n;i<128;i++)
        out.set(i);
    for (int i=0;i<n;i++)
    {
        if (!a[x].test(i))
        {
            out.set(i);
            continue;
        }
        if (p[i]<p[x])
        {
            must.push_back(~a[i]);
            out.set(i);
        }
        else
            now.push_back(i);
    }
    in.set(x);
    for (int i=0;i<must.size();i++)
        if ((must[i]&out)==must[i])
            return(false);
    return(dfs(0,x));
}
inline bool cmp(int x,int y)
{
    return(d[x]<d[y]);
}
int main()
{
    int m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=0;i<n;i++)
            a[i].reset();
        memset(d,0,sizeof(d));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--,y--;
            a[x].set(y);
            a[y].set(x);
            d[x]++,d[y]++;
        }
        for (int i=0;i<n;i++)
            c[i]=i;
        sort(c,c+n,cmp);
        for (int i=0;i<n;i++)
            p[c[i]]=i;
        ans=0;
        for (int i=0;i<n;i++)
            if (calc(c[i]))
                break;
        if (ans>1000)
            printf("Too many maximal sets of friends.\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

