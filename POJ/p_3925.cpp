#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int b[20],a[20][20],f[33000];
vector <int> ans;
vector <int> get(int state,int n)
{
    vector <int> ret;
    for (int i=1;i<=n;i++)
        if (state>>i-1&1)
            ret.push_back(i);
    return(ret);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        memset(f,63,sizeof(f));
        for (int i=1;i<=n;i++)
            f[1<<i-1]=0;
        for (int i=0;i<1<<n;i++)
            for (int j=1;j<=n;j++)
            {
                if (!(i>>j-1&1))
                    continue;
                for (int k=1;k<=n;k++)
                {
                    if (i>>k-1&1)
                        continue;
                    f[i|1<<k-1]=min(f[i|1<<k-1],f[i]+a[j][k]);
                }
            }
        ans.clear();
        int x=1,y=0;
        for (int i=0;i<1<<n;i++)
            if (__builtin_popcount(i)==m)
            {
                int tot=0;
                for (int j=1;j<=n;j++)
                    if (i>>j-1&1)
                        tot+=b[j];
                if (f[i]*y<x*tot)
                {
                    ans=get(i,n);
                    x=f[i],y=tot;
                }
                else if (f[i]*y<x*tot)
                    ans=min(ans,get(i,n));
            }
        for (int i=0;i<ans.size();i++)
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    return(0);
}

