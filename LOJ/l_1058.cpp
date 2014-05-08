#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[1010],b[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i]=x<<1,b[i]=y<<1;
        }
        vector <pair <int,int> > c;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                int p=a[i]+a[j]>>1,q=b[i]+b[j]>>1;
                c.push_back(make_pair(p,q));
            }
        sort(c.begin(),c.end());
        ll ans=0;
        for (int i=0,j;i<c.size();i=j)
        {
            int cnt=0;
            for (j=i;j<c.size() && c[i]==c[j];j++)
                cnt++;
            ans+=ll(cnt)*(cnt-1)/2;
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

