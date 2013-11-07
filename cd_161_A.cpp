#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int a[100010],b[100010];
vector <pair <int,int> > ans;
inline bool ok(int a,int b,int x,int y)
{
    return(b>=a-x && b<=a+y);
}
int main()
{
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    int t=1;
    for (int i=1;i<=n;i++)
    {
        while (t<=m && b[t]<a[i]-x)
            t++;
        if (t<=m && ok(a[i],b[t],x,y))
            ans.push_back(make_pair(i,t++));
    }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return(0);
}

