#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct data
{
    int a,b,id;
    ll dead;
};
inline bool operator <(const data &a,const data &b)
{
    return(a.dead<b.dead);
}
data a[200010];
vector <int> b;
bool check(ll delay,int n,int F,bool print)
{
    ll now=0;
    for (int i=1,j;i<=n;i=j)
    {
        now+=F;
        ll ma=-1LL<<60;
        vector <int> p;
        for (j=i;j<=n;j++)
        {
            ma=max(ma+a[j].a,now+a[j].a+a[j].b-a[j].dead);
            if (ma>delay)
                break;
            if (print)
                p.push_back(a[j].id);
            now+=a[j].a+a[j].b;
        }
        if (print)
        {
            for (int i=0;i<p.size();i++)
                b.push_back(-p[i]);
            for (int i=0;i<p.size();i++)
                b.push_back(p[i]);
        }
        if (i==j)
            return(false);
    }
    return(true);
}
int main()
{
    int n,F,f;
    scanf("%d%d%d",&n,&F,&f);
    F+=f;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%I64d",&a[i].a,&a[i].b,&a[i].dead);
        a[i].id=i;
    }
    sort(a+1,a+n+1);
    ll l=0,r=1LL<<60,ans=-1;
    while (l<=r)
    {
        ll mid=l+r>>1;
        if (check(mid,n,F,false))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    printf("%I64d\n",ans);
    check(ans,n,F,true);
    for (int i=0;i<b.size();i++)
        printf("%d%c",b[i],i+1==b.size()?'\n':' ');
    return(0);
}

