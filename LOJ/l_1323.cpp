#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[1010];
int get(int x,int n)
{
    int t=x/n;
    x%=n;
    if (x<0)
        t--,x+=n;
    return(t&1?n-x:x);
}
pair <int,int> calc(int x,int y,int L,int W)
{
    return(make_pair(get(x,L),get(y,W)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int L,W,n,K;
        scanf("%d%d%d%d",&L,&W,&n,&K);
        for (int i=1;i<=n;i++)
        {
            char s[10];
            int x,y;
            scanf("%d%d%s",&x,&y,s);
            if (s[0]=='N')
                y+=K;
            else
                y-=K;
            if (s[1]=='E')
                x+=K;
            else
                x-=K;
            a[i]=calc(x,y,L,W);
        }
        sort(a+1,a+n+1);
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
            printf("%d %d\n",a[i].first,a[i].second);
    }
    return(0);
}

