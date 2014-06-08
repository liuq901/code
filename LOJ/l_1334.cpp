#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int lq=1000000007;
char a[50010],b[50010];
ull ha[50010],hb[50010],p[50010];
void init(ull h[],char a[],int n)
{
    for (int i=1;i<=n;i++)
        h[i]=h[i-1]*lq+a[i];
}
ull get(ull h[],int pos,int len)
{
    return(h[pos]-h[pos-len]*p[len]);
}
int pre[50010],suf[50010];
int main()
{
    p[0]=1;
    for (int i=1;i<=50000;i++)
        p[i]=p[i-1]*lq;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a+1,b+1);
        int n=strlen(a+1),m=strlen(b+1);
        init(ha,a,n);
        init(hb,b,m);
        memset(pre,0,sizeof(pre));
        memset(suf,0,sizeof(suf));
        for (int i=1;i<=n;i++)
        {
            int l=1,r=min(n-i+1,m-1),ans=0;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (get(ha,i+mid-1,mid)==get(hb,mid,mid))
                    ans=mid,l=mid+1;
                else
                    r=mid-1;
            }
            pre[i]++;
            pre[i+ans]--;
            l=1,r=min(i,m-1),ans=0;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (get(ha,i,mid)==get(hb,m,mid))
                    ans=mid,l=mid+1;
                else
                    r=mid-1;
            }
            suf[i]++;
            suf[i-ans]--;
        }
        for (int i=1;i<=n;i++)
            pre[i]+=pre[i-1];
        for (int i=n;i;i--)
            suf[i]+=suf[i+1];
        ull ans=0;
        for (int i=2;i<=n;i++)
            ans+=ull(pre[i-1])*suf[i];
        static int id=0;
        printf("Case %d: %llu\n",++id,ans);
    }
    return(0);
}

