#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010];
inline bool cmp(int x,int y)
{
    return(x%10<y%10 || x%10==y%10 && x>y);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++)
            printf("%d%c",a[i],i==n?'\n':' ');
    }
    return(0);
}

