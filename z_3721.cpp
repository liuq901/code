#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[100010];
int c[100010],l[100010],r[100010];
vector <int> ans[100010];
inline bool cmp(int x,int y)
{
    return(a[x]<a[y]);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].first,&a[i].second);
            c[i]=i;
        }
        sort(c+1,c+n+1,cmp);
        int tot=1;
        ans[1].clear();
        ans[1].push_back(c[1]);
        l[1]=a[c[1]].first,r[1]=a[c[1]].second;
        for (int i=2;i<=n;i++)
        {
            int x=c[i],L=a[x].first,R=a[x].second;
            if (r[tot]<=L || R<=l[tot])
            {
                ans[++tot].clear();
                ans[tot].push_back(x);
                l[tot]=L,r[tot]=R;
            }
            else
            {
                l[tot]=max(l[tot],L);
                r[tot]=min(r[tot],R);
                ans[tot].push_back(x);
            }
        }
        printf("%d\n",tot);
        for (int i=1;i<=tot;i++)
            for (int j=0;j<ans[i].size();j++)
                printf("%d%c",ans[i][j],j==ans[i].size()-1?'\n':' ');
        printf("\n");
    }
    return(0);
}

