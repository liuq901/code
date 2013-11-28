#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[110],f[110][100010];
ll solve(int m,ll n)
{
    if (m==0 || n==0)
        return(n);
    if (n<=100000 && f[m][n]!=-1)
        return(f[m][n]);
    ll ret=solve(m-1,n)-solve(m-1,n/a[m]);
    if (n<=100000)
        f[m][n]=ret;
    return(ret);
}
int main()
{
    ll n;
    int m;
    scanf("%I64d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    memset(f,-1,sizeof(f));
    printf("%I64d\n",solve(m,n));
    return(0);
}

