#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
bool f[1000010];
int c[10000],a[1000010];
vector <ll> p;
void init()
{
    for (int i=2;i<=1000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=1000000;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=1000000;i++)
        if (!f[i])
            a[++a[0]]=i;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n,k;
        cin>>n>>k;
        p.clear();
        for (int i=1;i<=a[0];i++)
        {
            if (k%a[i])
                continue;
            p.push_back(a[i]);
            c[p.size()-1]=0;
            while (!(k%a[i]))
            {
                k/=a[i];
                c[p.size()-1]++;
            }
        }
        if (k!=1)
        {
            p.push_back(k);
            c[p.size()-1]=1;
        }
        ll ans=1LL<<60;
        for (int i=0;i<p.size();i++)
        {
            ll now=0,x=n;
            while (x)
            {
                now+=x/p[i];
                x/=p[i];
            }
            now/=c[i];
            ans=min(ans,now);
        }
        cout<<ans<<endl;
    }
    return(0);
}

