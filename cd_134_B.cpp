#include <cstdio>
#include <algorithm>
using namespace std;
int calc(int a,int b)
{
    if (b==1)
        return(a-1);
    if (a%b==0)
        return(1<<30);
    return(calc(b,a%b)+a/b);
}
int main()
{
    int n,ans=1<<30;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        ans=min(ans,calc(n,i));
    printf("%d\n",ans);
    return(0);
}

