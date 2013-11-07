#include <cstdio>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
const int mod=100000007;
set <pair <int,int> > S,T;
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
int main()
{
    int n,m,K;
    while (scanf("%d%d%d",&n,&m,&K)==3)
    {
        S.clear();
        T.clear();
        bool flag=false;
        int t=n%2==1?(n+1)/2:0;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            if (x==t && y==t)
            {
                flag=true;
                continue;
            }
            set <pair <int,int> > *now;
            if (x==t || y==t || x==y || x+y==n+1)
                now=&T;
            else
                now=&S;
            for (int j=1;j<=4;j++)
            {
                now->insert(make_pair(x,y));
                int t=n-y+1;
                y=x,x=t;
            }
            y=n-y+1;
            for (int j=1;j<=4;j++)
            {
                now->insert(make_pair(x,y));
                int t=n-y+1;
                y=x,x=t;
            }            
        }
        int cnt=0;
        if (n%2==1)
        {
            if (!flag)
                cnt++;
            cnt+=(n-1)-T.size()/4;
            cnt+=(((n-1)*(n-1)-2*(n-1))-S.size())/8;
        }
        else
        {
            cnt+=n/2-T.size()/4;
            cnt+=((n*n-2*n)-S.size())/8;
        }
        printf("%d\n",power(K,cnt));
    }
    return(0);
}

