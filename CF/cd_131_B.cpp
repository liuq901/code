#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
map <int,int> a;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x=0;
        scanf("%d",&x);
        a[x]++;
    }
    ll ans=0;
    for (int i=1;i<=10;i++)
        ans+=ll(a[i])*a[-i];
    ans+=ll(a[0])*(a[0]-1)/2;
    printf("%I64d\n",ans);
    return(0);
}

