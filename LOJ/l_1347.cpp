#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int lq=1000000007;
char buf[5010];
int len[3];
ull p[5010],h[3][5010];
void gen(ull h[],char a[],int n)
{
    for (int i=1;i<=n;i++)
        h[i]=h[i-1]*lq+a[i];
}
ull get(ull h[],int pos,int len)
{
    return(h[pos]-h[pos-len]*p[len]);
}
pair <ull,int> a[15010];
bool check(int mid)
{
    int t=0;
    for (int i=0;i<3;i++)
        for (int j=mid;j<=len[i];j++)
            a[++t]=make_pair(get(h[i],j,mid),i);
    sort(a+1,a+t+1);
    for (int i=1,j;i<=t;i=j)
    {
        int state=0;
        for (j=i;j<=t && a[i].first==a[j].first;j++)
            state|=1<<a[j].second;
        if (state==7)
            return(true);
    }
    return(false);
}
int main()
{
    p[0]=1;
    for (int i=1;i<=5000;i++)
        p[i]=p[i-1]*lq;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<3;i++)
        {
            scanf("%s",buf+1);
            len[i]=strlen(buf+1);
            gen(h[i],buf,len[i]);
        }
        int l=0,r=len[0],ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(mid))
                ans=mid,l=mid+1;
            else
                r=mid-1;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

