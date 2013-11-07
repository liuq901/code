#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int N=1000010;
int a[N];
map <int,int> M;
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
        M.clear();
        int ans=0,now=0;
        for (int i=1;i<=n;i++)
        {
            now++;
            if (M.count(a[i]))
                now=min(now,i-M[a[i]]);
            M[a[i]]=i;
            ans=max(ans,now);
        }
        printf("%d\n",ans);
    }
    return(0);
}

