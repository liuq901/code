#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int ans[50010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        vector <pair <int,int> > a;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a.push_back(make_pair(x,0));
            a.push_back(make_pair(y,Q+1));
        }
        for (int i=1;i<=Q;i++)
        {
            int x;
            scanf("%d",&x);
            a.push_back(make_pair(x,i));
        }
        sort(a.begin(),a.end());
        int sum=0;
        for (int i=0;i<a.size();i++)
            if (a[i].second==0)
                sum++;
            else if (a[i].second==Q+1)
                sum--;
            else
                ans[a[i].second]=sum;
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=Q;i++)
            printf("%d\n",ans[i]);
    }
    return(0);
}

