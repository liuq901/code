#include <cstdio>
#include <algorithm>
using namespace std;
int a[20010],b[20010];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=m;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        bool flag=true;
        int now=1,ans=0;
        for (int i=1;i<=n;i++)
        {
            while (now<=m && b[now]<a[i])
                now++;
            if (now>m)
            {
                flag=false;
                break;
            }
            ans+=b[now++];
        }
        if (!flag)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

