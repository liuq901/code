#include <cstdio>
#include <cstring>
#include <bitset>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int b[5010],d[5010],q[5010],a[100010][2];
bitset <5010> in[5010],out[5010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            d[y]++;
        }
        int l=1,r=0;
        for (int i=1;i<=n;i++)
            if (!d[i])
                q[++r]=i;
        while (l<=r)
        {
            int x=q[l++];
            for (int i=b[x];i;i=a[i][1])
            {
                int y=a[i][0];
                if (--d[y]==0)
                    q[++r]=y;
            }
        }
        for (int i=1;i<=n;i++)
        {
            in[i].reset();
            out[i].reset();
            in[i].set(i);
            out[i].set(i);
        }
        for (int i=1;i<=n;i++)
        {
            int x=q[i];
            for (int j=b[x];j;j=a[j][1])
            {
                int y=a[j][0];
                in[y]|=in[x];
            }
        }
        for (int i=n;i;i--)
        {
            int x=q[i];
            for (int j=b[x];j;j=a[j][1])
            {
                int y=a[j][0];
                out[x]|=out[y];
            }
        }
        vector <pair <int,int> > ans;
        for (int i=1;i<=n;i++)
            for (int j=b[i];j;j=a[j][1])
            {
                int x=a[j][0];
                if ((out[i]&in[x]).count()==2)
                    ans.push_back(make_pair(i,x));
            }
        sort(ans.begin(),ans.end());
        static int id=0;
        printf("Case %d: %d\n",++id,ans.size());
        for (int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return(0);
}

