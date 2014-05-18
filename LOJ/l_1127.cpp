#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <int> value;
int a[40];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,W;
        scanf("%d%d",&n,&W);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        value.clear();
        int m=n/2;
        for (int i=0;i<1<<m;i++)
        {
            ll sum=0;
            for (int j=1;j<=m;j++)
                if (i>>j-1&1)
                    sum+=a[j];
            if (sum<=W)
                value.push_back(sum);
        }
        sort(value.begin(),value.end());
        int k=n-m,ans=0;
        for (int i=0;i<1<<k;i++)
        {
            ll sum=0;
            for (int j=1;j<=k;j++)
                if (i>>j-1&1)
                    sum+=a[m+j];
            if (sum<=W)
                ans+=upper_bound(value.begin(),value.end(),W-sum)-value.begin();
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

