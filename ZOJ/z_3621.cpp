#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
char buf[100];
vector <pair <int,int> > a[100];
int get(char ch)
{
    if (isdigit(ch))
        return(ch-'0');
    else if (isupper(ch))
        return(ch-'A'+10);
    return(ch-'a'+36);
}
bool prime(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return(false);
    return(true);
}
void init()
{
    for (int i=2;i<=62;i++)
    {
        int t=i;
        for (int j=i;j>1;j--)
            if (prime(j) && t%j==0)
            {
                a[i].push_back(make_pair(j,0));
                while (t%j==0)
                {
                    t/=j;
                    a[i].back().second++;
                }
            }
    }
}
int main()
{
    init();
    int base;
    while (scanf("%s%d",buf,&base)==2)
    {
        ll n=0;
        int len=strlen(buf);
        for (int i=0;i<len;i++)
            n=n*base+get(buf[i]);
        ll ans=9223372036854775807LL;
        for (int i=0;i<a[base].size();i++)
        {
            ll t=n,now=0;
            while (t)
            {
                now+=t/a[base][i].first;
                t/=a[base][i].first;
            }
            now/=a[base][i].second;
            ans=min(ans,now);
        }
        printf("%lld\n",ans);
        
    }
    return(0);
}

