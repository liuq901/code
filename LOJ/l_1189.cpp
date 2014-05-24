#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <pair <ll,int> > ans;
void init()
{
    ll f[20];
    f[0]=1;
    for (int i=1;i<20;i++)
        f[i]=f[i-1]*i;
    for (int i=0;i<1<<20;i++)
    {
        ll sum=0;
        for (int j=0;j<20;j++)
            if (i>>j&1)
                sum+=f[j];
        ans.push_back(make_pair(sum,i));
    }
    sort(ans.begin(),ans.end());
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        scanf("%lld",&n);
        static int id=0;
        printf("Case %d: ",++id);
        int t=lower_bound(ans.begin(),ans.end(),make_pair(n,-1))-ans.begin();
        if (t<ans.size() && ans[t].first==n)
        {
            int state=ans[t].second;
            bool first=true;
            for (int i=0;i<20;i++)
                if (state>>i&1)
                {
                    if (!first)
                        printf("+");
                    first=false;
                    printf("%d!",i);
                }
            printf("\n");
        }
        else
            printf("impossible\n");
    }
    return(0);
}

