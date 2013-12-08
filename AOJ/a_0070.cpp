#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
map <int,int> ans[10];
void calc(int *a)
{
    int sum=0;
    for (int i=0;i<10;i++)
    {
        sum+=(i+1)*a[i];
        ans[i][sum]++;
    }
}
int f[10];
void init()
{
    int a[10];
    for (int i=0;i<10;i++)
        a[i]=i;
    while (1)
    {
        calc(a);
        if (!next_permutation(a,a+10))
            break;
    }
    f[0]=1;
    for (int i=1;i<10;i++)
        f[i]=f[i-1]*i;
}
int main()
{
    init();
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
        printf("%d\n",ans[n-1][m]/f[10-n]);
    return(0);
}

