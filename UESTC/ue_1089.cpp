#include <cstdio>
#include <set>
using namespace std;
set <int> S;
int a[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            S.insert(x);
        }
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            set <int>::iterator k=S.upper_bound(a[i]);
            if (k!=S.begin())
                cnt++;
            else
                k=S.end();
            S.erase(--k);
        }
        printf("%s\n",cnt*2>n?"Beautiful girl is smiling again~~~":"What a stupid guy!");
    }
    return(0);
}

