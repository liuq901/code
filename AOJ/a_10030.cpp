#include <cstdio>
#include <set>
using namespace std;
set <int> s;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        s.insert(x);
    }
    scanf("%d",&n);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans+=s.count(x);
    }
    printf("%d\n",ans);
    return(0);
}

