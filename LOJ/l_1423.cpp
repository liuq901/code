#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
typedef unsigned long long ull;
const int lq=1000000007;
int a[40][50010],s[40][50010];
ull hash(int m,int pos)
{
    ull ret=0;
    for (int i=1;i<m;i++)
        ret=ret*lq+s[i][pos];
    return(ret);
}
void calc(int id,int n)
{
    for (int i=1;i<=n;i++)
        s[id][i]=s[id][i-1]+a[id][i]-a[id+1][i];
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for (int i=1;i<=m;i++)
        {
            int K;
            scanf("%d",&K);
            for (int j=0;j<K;j++)
            {
                int x;
                scanf("%d",&x);
                a[i][x+1]++;
            }
        }
        int ans=0;
        for (int i=1;i<m;i++)
            calc(i,n);
        map <ull,int> M;
        for (int i=0;i<=n;i++)
        {
            ull tmp=hash(m,i);
            if (M.count(tmp))
                ans=max(ans,i-M[tmp]);
            else
                M[tmp]=i;
        }
        static int id=0;
        printf("Case %d: %d meter(s)\n",++id,ans);
    }
    return(0);
}

