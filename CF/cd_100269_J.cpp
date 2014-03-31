#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000000;
int tot[11];
struct data
{
    int n,a[11];
    data(int x=0)
    {
        memset(a,0,sizeof(a));
        if (x==-1)
            a[n=1]=1;
        else
            a[n=0]=x;
    }
    void negative()
    {
        for (int i=0;i<=n;i++)
            a[i]=(mod-a[i])%mod;
    }
    void sum()
    {
        int now=0;
        for (int i=0;i<=n;i++)
            now=(now+ll(a[i])*tot[i])%mod;
        memset(a,0,sizeof(a));
        a[n=0]=now;
    }
    int &operator [](int x)
    {
        return(a[x]);
    }
    int operator [](int x) const
    {
        return(a[x]);
    }
};
inline data operator +(const data &a,const data &b)
{
    data c;
    c.n=max(a.n,b.n);
    for (int i=0;i<=c.n;i++)
        c[i]=(a[i]+b[i])%mod;
    return(c);
}
inline data operator -(const data &a,const data &b)
{
    data c;
    c.n=max(a.n,b.n);
    for (int i=0;i<=c.n;i++)
        c[i]=(a[i]-b[i]+mod)%mod;
    return(c);
}
inline data operator *(const data &a,const data &b)
{
    data c;
    c.n=a.n+b.n;
    for (int i=0;i<=a.n;i++)
        for (int j=0;j<=b.n;j++)
            c[i+j]=(c[i+j]+ll(a[i])*b[j])%mod;
    return(c);
}
inline int power(int x,int y)
{
    int ret=1;
    for (int i=1;i<=y;i++)
        ret=ll(ret)*x%mod;
    return(ret);
}
inline data calc(const data &a,char op,const data &b)
{
    if (op=='+')
        return(a+b);
    if (op=='-')
        return(a-b);
    return(a*b);
}
data ans[100010];
char buf[100010],op[100010];
string s;
int ansn,opn,a[100010];
int main()
{
    freopen("j.in","r",stdin);
    freopen("j.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<=10;i++)
        for (int j=1;j<=n;j++)
            tot[i]=(tot[i]+power(a[j],i))%mod;
    scanf("%s",buf);
    int len=strlen(buf);
    for (int i=0;i<len;i++)
        if (buf[i]=='+' && buf[i+1]=='/')
        {
            s+='#';
            i++;
        }
        else if (buf[i]=='*' && buf[i+1]==':')
        {
            s+='^';
            i++;
        }
        else if (buf[i]=='-' && (i==0 || buf[i-1]!=')' && !isalnum(buf[i-1])))
            s+='~';
        else
            s+=buf[i];
    reverse(s.begin(),s.end());
    for (int i=0;i<s.size();i++)
    {
        if (s[i]==')')
        {
            op[++opn]=s[i];
            continue;
        }
        if (s[i]=='^')
        {
            ans[ansn]=ans[ansn]*ans[ansn];
            continue;
        }
        else if (s[i]=='~')
        {
            ans[ansn].negative();
            continue;
        }
        else if (s[i]=='#')
        {
            ans[ansn].sum();
            continue;
        }
        else if (s[i]=='+' || s[i]=='-' || s[i]=='*')
        {
            op[++opn]=s[i];
            continue;
        }
        else if (isdigit(s[i]))
        {
            int p=1,now=0;
            while (1)
            {
                now+=p*(s[i]-'0');
                if (i+1==s.size() || !isdigit(s[i+1]))
                    break;
                i++;
                p*=10;
            }
            ans[++ansn]=now;
        }
        else if (s[i]=='X')
            ans[++ansn]=-1;
        else if (s[i]=='N')
            ans[++ansn]=n;
        else
            opn--;
        if (opn!=0 && op[opn]!=')')
        {
            ansn--;
            ans[ansn]=calc(ans[ansn+1],op[opn--],ans[ansn]);
        }
    }
    printf("%d\n",ans[ansn][0]);
    return(0);
}

