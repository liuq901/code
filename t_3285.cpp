#include <cstdio>
#include <algorithm>
using namespace std;
int N,n,a[100010];
int work()
{
    int ans=N;
    for (int i=1;i<=n;i++)
    {
        int now=a[i];
        if (now<0)
            now+=N;
        if (i!=n)
        {
            int p=a[i]-a[i+1];
            if (p<0)
                p+=N;
            now+=p;
        }
        ans=min(ans,now);
    }
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int start;
        scanf("%d%d%d",&N,&start,&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]-=start;
            if (a[i]<0)
                a[i]+=N;
        }
        sort(a+1,a+n+1);
        n=unique(a+1,a+n+1)-a-1;
        int ans=work();
        for (int i=1;i<=n;i++)
            a[i]=N-a[i];
        start=N-start;
        reverse(a+1,a+n+1);
        ans=min(ans,work());
        printf("%d\n",ans);
    }
    return(0);
}

