#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector <pair <double,int> > g[1010];
set <pair <int,int> > flag;
pair <int,int> r[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            g[i].clear();
        for (int i=1;i<=n;i++)
        {
            int k,s;
            scanf("%d",&k);
            scanf("%d%d%d",&r[k].first,&r[k].second,&s);
            for (int j=0;j<s;j++)
            {
                int x;
                scanf("%d",&x);
                g[k].push_back(make_pair(0,x));
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<g[i].size();j++)
                g[i][j]=make_pair(atan2(r[g[i][j].second].second-r[i].second,r[g[i][j].second].first-r[i].first),g[i][j].second);
            sort(g[i].begin(),g[i].end());
        }
        int q;
        scanf("%d",&q);
        int ans=0;
        flag.clear();
        for (int i=1;i<=n;i++)
            for (int j=0;j<g[i].size();j++)
            {
                int last=g[i][j].second,now=i,area=0,cnt=0;
                while (!flag.count(make_pair(last,now)))
                {
                    flag.insert(make_pair(last,now));
                    cnt++;
                    int x=lower_bound(g[now].begin(),g[now].end(),make_pair(atan2(r[last].second-r[now].second,r[last].first-r[now].first),last))-g[now].begin();
                    x=x==0?g[now].size()-1:x-1;
                    area+=r[last].first*r[now].second-r[now].first*r[last].second;
                    last=now;
                    now=g[now][x].second;
                }
                if (area>0 && cnt==q)
                    ans++;
            }
        printf("%d\n",ans);
    }
    return(0);
}

