#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110],l[5010],r[5010],b[5010];
int calc(int n)
{
    int ret=0;
    for (int i=1;i<=n;i++)
        ret+=l[i]!=r[i];
    return(ret);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    int now=1;
    for (int i=1;i<=n;i++)
    {
        while (a[now]==0)
            now++;
        r[i]=l[i]=now;
        a[now]--;
    }
    int ans=-1;
    for (int i=1;i<=n;i++)
    {
        int now=calc(n);
        if (now>ans)
        {
            ans=now;
            memcpy(b,r,sizeof(r));
        }
        rotate(r+1,r+2,r+n+1);
    }
    printf("%d\n",ans);
    for (int i=1;i<=n;i++)
        printf("%d %d\n",l[i],b[i]);
    return(0);
}

