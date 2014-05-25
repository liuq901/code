#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int a[60];
multiset <int> s;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        sort(a+1,a+n+1);
        int draw,cnt=0,ans=0;
        for (int i=1;i<=n;i++)
        {
            int x=a[i];
            multiset <int>::iterator k=s.lower_bound(x);
            if (k!=s.begin())
            {
                ans+=2;
                s.erase(--k);
            }
            else if (cnt>0 && x>draw)
            {
                ans++;
                cnt--;
                k=s.end();
                s.erase(--k);
            }
            else if (*k==x)
            {
                ans++;
                draw=x;
                cnt++;
                s.erase(k);
            }
            else
            {
                k=s.end();
                s.erase(--k);
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

