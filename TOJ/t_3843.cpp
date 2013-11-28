#include <cstdio>
#include <set>
using namespace std;
set <int> s;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        s.insert(x);
    }
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        if (s.count(x))
        {
            ans++;
            s.erase(x);
        }
    }
    printf("%d\n",ans);
    return(0);
}

