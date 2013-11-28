#include <cstdio>
#include <map>
using namespace std;
map <int,int> a;
int main()
{
    for (int T=1;T<=3;T++)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }
    }
    int ans=0;
    for (map <int,int>::iterator k=a.begin();k!=a.end();k++)
        ans+=k->second==3;
    printf("%d\n",ans);
    return(0);
}

