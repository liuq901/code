#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010],c[1010];
inline bool cmp(int x,int y)
{
    return(a[x]<a[y] || a[x]==a[y] && x>y);
}
void init()
{
    const int n=1000;
    for (int i=1;i<=n;i++)
    {
        c[i]=i;
        for (int j=1;j<=i;j++)
            a[i]+=i%j==0;
    }
    sort(c+1,c+n+1,cmp);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        static int id=0;
        printf("Case %d: %d\n",++id,c[n]);
    }
    return(0);
}

