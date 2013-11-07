#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[50][10];
char a[50];
ll get(int l,int r)
{
    ll ret=0;
    for (int i=l;i<=r;i++)
        ret=ret*10+a[i]-'0';
    return(ret);
}
int main()
{
    int n,K;
    scanf("%d%d%s",&n,&K,a+1);
    K++;
    f[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=K;j++)
            for (int p=0;p<i;p++)
                f[i][j]=max(f[i][j],f[p][j-1]*get(p+1,i));
    printf("%I64d\n",f[n][K]);
    return(0);
}

