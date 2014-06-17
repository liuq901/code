#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
char a[2010][2010];
int h[2010],l[2010],r[2010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        memset(h,0,sizeof(h));
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                h[j]=a[i][j]=='1'?0:h[j]+1;
            stack <int> s;
            for (int j=1;j<=m;j++)
            {
                while (!s.empty() && h[j]<=h[s.top()])
                    s.pop();
                l[j]=s.empty()?1:s.top()+1;
                s.push(j);
            }
            while (!s.empty())
                s.pop();
            for (int j=m;j;j--)
            {
                while (!s.empty() && h[j]<=h[s.top()])
                    s.pop();
                r[j]=s.empty()?m:s.top()-1;
                s.push(j);
            }
            for (int j=1;j<=m;j++)
                ans=max(ans,(r[j]-l[j]+1)*h[j]);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

