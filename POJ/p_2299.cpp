#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int inf=1<<30;
int a[500010];
ll merge(int l,int r)
{
    if (l==r)
        return(0);
    int mid=l+r>>1;
    ll ret=merge(l,mid)+merge(mid+1,r);
    vector <int> b,c;
    for (int i=l;i<=mid;i++)
        b.push_back(a[i]);
    for (int i=mid+1;i<=r;i++)
        c.push_back(a[i]);
    b.push_back(inf);
    c.push_back(inf);
    int t=l;
    for (int i=0,j=0;i<b.size()-1 || j<c.size()-1;)
    {
        if (b[i]<=c[j])
        {
            a[t++]=b[i++];
            continue;
        }
        ret+=b.size()-i-1;
        a[t++]=c[j++];
    }
    return(ret);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("%I64d\n",merge(1,n));
    }
    return(0);
}

