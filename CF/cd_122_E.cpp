#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int c[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int a[10010];
vector <int> b;
void dfs(ll x)
{
    if (x>=1000000000)
        return;
    a[++a[0]]=int(x);
    dfs(x*10+4);
    dfs(x*10+7);
}
bool check(int x)
{
    while (x)
    {
        int p=x%10;
        x/=10;
        if (p!=4 && p!=7)
            return(false);
    }
    return(true);
}
int main()
{
    int n,K;
    scanf("%d%d",&n,&K);
    ll now=1;
    int t=-1;
    for (int i=1;i<=n;i++)
    {
        now*=i;
        if (now>=K)
        {
            t=i;
            break;
        }
    }
    if (t==-1)
        printf("-1\n");
    else
    {
        dfs(4);
        dfs(7);
        sort(a+1,a+a[0]+1);
        for (int i=1;i<=t;i++)
            b.push_back(n-i+1);
        reverse(b.begin(),b.end());
        int ans=0;
        for (int i=1;i<=a[0];i++)
            ans+=a[i]<=n-t;
        int now=n-t;
        K--;
        for (int i=t;i;i--)
        {
            now++;
            int p=0;
            while (K>=c[i-1])
            {
                p++;
                K-=c[i-1];
            }
            ans+=check(now) && check(b[p]);
            b.erase(b.begin()+p);
        }
        printf("%d\n",ans);
    }
    return(0);
}

