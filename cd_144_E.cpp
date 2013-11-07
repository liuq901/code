#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct data
{
    int x,y,id;
};
vector <int> ans;
multiset <data> S;
data a[100010];
inline bool operator <(const data &a,const data &b)
{
    return(a.y<b.y);
}
inline bool cmp(const data &a,const data &b)
{
    return(a.x<b.x);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i].x=n-x+1,a[i].y=y,a[i].id=i;
    }
    sort(a+1,a+m+1,cmp);
    int t=1;
    for (int i=1;i<=n;i++)
    {
        while (t<=m && a[t].x<=i)
            S.insert(a[t++]);
        while (!S.empty() && S.begin()->y<i)
            S.erase(S.begin());
        if (!S.empty())
        {
            ans.push_back(S.begin()->id);
            S.erase(S.begin());
        }
    }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return(0);
}

