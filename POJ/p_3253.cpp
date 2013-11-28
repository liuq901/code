#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
multiset <int> a;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a.insert(x);
    }
    ll ans=0;
    while (a.size()>1)
    {
        int x=*a.begin();
        a.erase(a.begin());
        int y=*a.begin();
        a.erase(a.begin());
        ans+=x+y;
        a.insert(x+y);
    }
    printf("%I64d\n",ans);
    return(0);
}

