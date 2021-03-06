#include <cstdio>
#include <set>
using namespace std;
multiset <int> S;
int a[100010],pos[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        pos[x]=i;
    }
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=i-pos[x];
        S.insert(a[i]);
    }
    for (int i=1;i<=n;i++)
    {
        multiset <int>::iterator k=S.lower_bound(i-1);
        int ans=1<<30;
        if (k!=S.end())
            ans=min(ans,*k-(i-1));
        if (k!=S.begin())
            ans=min(ans,(i-1)-*--k);
        printf("%d\n",ans);
        S.erase(S.find(a[i]));
        S.insert(a[i]+n);
    }
    return(0);
}

