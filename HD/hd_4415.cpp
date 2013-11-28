#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int a[100010],b[100010],s[100010];
inline pair <int,int> getans(int M,int n)
{
    int id=upper_bound(s+1,s+n+1,M)-s-1;
    return(make_pair(id,s[id]));
}
inline void update(pair <int,int> &a,const pair <int,int> &b)
{
    if (b.first>a.first || a.first==b.first && b.second<a.second)
        a=b;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        int n=0,m=0,sum=0;
        for (int i=1;i<=N;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (y==0)
                a[++n]=x;
            else
            {
                b[++m]=x;
                sum+=y;
            }
        }
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        for (int i=1;i<=n;i++)
            s[i]=min(M+1,s[i-1]+a[i]);
        pair <int,int> ans=getans(M,n);
        int tot=0;
        for (int i=1;i<=m;i++)
        {
            tot+=b[i];
            if (tot>M)
                break;
            int last=sum-m+i;
            pair <int,int> now=getans(M-tot,max(0,n-last));
            now.first+=m+min(n,last),now.second+=tot;
            update(ans,now);
        }
        static int id=0;
        printf("Case %d: %d %d\n",++id,ans.first,ans.second);
    }
    return(0);
}

