#include <cstdio>
#include <set>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    set <int> S;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        S.insert(x);
    }
    int ans=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans+=S.count(x);
    }
    printf("%d\n",ans);
    return(0);
}

