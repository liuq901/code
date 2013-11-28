#include <cstdio>
#include <algorithm>
using namespace std;
int l[60],r[60];
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int lim=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            lim=max(lim,r[i]);
        }
        int ans=0;
        for (int i=2;i<=lim;i++)
        {
            int cnt=0;
            for (int j=1;j<=n;j++)
                if (l[j]<r[j] && l[j]<i)
                {
                    l[j]++;
                    cnt++;
                }
            ans+=max(1,cnt);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

