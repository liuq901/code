#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector <pair <int,int> > s[10010];
int a[1010];
vector <pair <int,int> > work(const vector <pair <int,int> > &a)
{
    vector <pair <int,int> > b;
    if (a.empty())
        return(b);
    int l=a[0].first,r=a[0].second;
    for (int i=1;i<a.size();i++)
    {
        if (a[i].first<=r)
        {
            r=max(r,a[i].second);
            continue;
        }
        b.push_back(make_pair(l,r));
        l=a[i].first,r=a[i].second;
    }
    b.push_back(make_pair(l,r));
    return(b);
}
int calc(int l,int r,int x)
{
    int ans=0;
    for (int i=0;i<s[x].size();i++)
        ans+=max(0,min(s[x][i].second,r)-max(s[x][i].first,l));
    return(ans);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (!n && !m)
            break;
        for (int i=1;i<=m;i++)
            s[i].clear();
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int t,x,y,z;
            scanf("%d%d%d%d",&t,&x,&y,&z);
            if (z==1)
                a[x]=t;
            else
                s[y].push_back(make_pair(a[x],t));
        }
        for (int i=1;i<=m;i++)
        {
            sort(s[i].begin(),s[i].end());
            s[i]=work(s[i]);
        }
        scanf("%d",&Q);
        while (Q--)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",calc(x,y,z));
        }
    }
    return(0);
}

