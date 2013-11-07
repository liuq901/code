#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const ll mod=1000000000000000LL*24;
const int p[3][9]={{0,5,1,7,3,6,2,8,4},{0,3,4,7,8,1,2,5,6},{0,3,1,4,2,7,5,8,6}};
set <vector <int> > s;
vector <int> a;
vector <int> change(const vector <int> &b,const int *p)
{
    vector <int> c;
    c.resize(9);
    for (int i=1;i<=8;i++)
        c[i]=b[p[i]];
    return(c);
}
void init()
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            for (int k=0;k<4;k++)
            {
                vector <int> b;
                for (int l=0;l<=8;l++)
                    b.push_back(l);
                for (int l=1;l<=i;l++)
                    b=change(b,p[0]);
                for (int l=1;l<=j;l++)
                    b=change(b,p[1]);
                for (int l=1;l<=k;l++)
                    b=change(b,p[2]);
                if (s.count(b))
                    continue;
                s.insert(b);
                bool f[10]={0};
                int t=0;
                for (int l=1;l<=8;l++)
                {
                    if (f[l])
                        continue;
                    t++;
                    for (int x=l;!f[x];x=b[x])
                        f[x]=true;
                }
                a.push_back(t);
            }
}
ll mulmod(ll x,ll y)
{
    ll ret=0,tmp=x;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=(ret+tmp)%mod;
        tmp=(tmp+tmp)%mod;
    }
    return(ret);
}
ll power(int x,int n)
{
    if (n==0)
        return(1);
    ll ret=power(x,n>>1);
    ret=mulmod(ret,ret);
    if (n&1)
        ret=mulmod(ret,x);
    return(ret);
}
int Log(ll x)
{
    int ret=0;
    while (x)
    {
        ret++;
        x/=10;
    }
    return(max(ret,1));
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        ll ans=0;
        double now=0;
        for (int i=0;i<a.size();i++)
        {
            ans=(ans+power(n,a[i]))%mod;
            now+=pow(double(n),double(a[i]));
        }
        ans/=24;
        now/=24;
        static int id=0;
        printf("Case %d: ",++id);
        if (now>=1e15)
            for (int i=1;i<=15-Log(ans);i++)
                printf("0");
        printf("%I64d\n",ans);
    }
    return(0);
}

