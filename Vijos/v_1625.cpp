#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10010;
int f[N];
int main()
{
    int limit,n,m;
    scanf("%d%d%d",&limit,&n,&m);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for (int j=m;j>=y;j--)
            f[j]=min(max(f[j],f[j-y]+x),limit);
    }
    int ans=-1;
    for (int i=0;i<=m;i++)
        if (f[i]==limit)
        {
            ans=i;
            break;
        }
    if (ans==-1)
        printf("Impossible\n");
    else
        printf("%d\n",m-ans);
    return(0);
}

