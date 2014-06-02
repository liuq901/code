#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int n=50000;
vector <int> a[50010];
int q[50010],d[50010],pre[50010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=n;i++)
            a[i].clear();
        int m,S,T;
        scanf("%d%d",&m,&S);
        T=S;
        for (int i=2;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            a[T].push_back(x);
            a[x].push_back(T);
            T=x;
        }
        for (int i=1;i<=n;i++)
            sort(a[i].begin(),a[i].end());
        memset(d,-1,sizeof(d));
        d[S]=0;
        int l,r;
        q[l=r=1]=S;
        while (l<=r)
        {
            int x=q[l++];
            for (int i=0;i<a[x].size();i++)
            {
                int y=a[x][i];
                if (d[y]==-1)
                {
                    d[y]=d[x]+1;
                    pre[y]=x;
                    q[++r]=y;
                }
            }
        }
        static int id=0;
        printf("Case %d:\n%d",++id,S);
        vector <int> ans;
        for (int i=T;i!=S;i=pre[i])
            ans.push_back(i);
        reverse(ans.begin(),ans.end());
        for (int i=0;i<ans.size();i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return(0);
}

