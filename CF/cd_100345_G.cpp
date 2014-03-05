#include <cstdio>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
FILE *in,*out;
typedef long long ll;
pair <int,int> a[100010];
int main()
{
    in=fopen("pulp.in","r");
    out=fopen("pulp.out","w");
    int n;
    fscanf(in,"%d",&n);
    for (int i=1;i<=n;i++)
        fscanf(in,"%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    multiset <int> S;
    ll now,ans=0;
    for (int i=1;i<=n;i++)
    {
        while (!S.empty())
        {
            int t=*S.begin();
            S.erase(S.begin());
            if (t>a[i].first-now)
            {
                S.insert(t-(a[i].first-now));
                break;
            }
            now+=t;
            ans+=now;
        }
        S.insert(a[i].second);
        now=a[i].first;
    }
    while (!S.empty())
    {
        now+=*S.begin();
        ans+=now;
        S.erase(S.begin());
    }
    fprintf(out,"%I64d\n",ans);
    return(0);
}

