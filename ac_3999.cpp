#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned long long ull;
const int mod=1000007;
const int lq=2131,LQ=1235;
struct hash
{
    ull h1,h2;
    int opt;
    hash(ull h1,ull h2,int opt):h1(h1),h2(h2),opt(opt){}
};
vector <hash> f[mod];
char s[7][1000010];
int n,t,a[7];
bool get(int id,int len)
{
    ull now=0,now1=0,p=1,q=1;
    for (int i=0;i<len;i++)
    {
        now=now*lq+s[id][i]-'A';
        p*=lq;
        now1=now1*LQ+s[id][i]-'A';
        q*=LQ;
    }
    int x=now%mod;
    bool flag=false;
    for (int i=0;i<f[x].size();i++)
        if (now==f[x][i].h1 && now1==f[x][i].h2)
        {
            f[x][i].opt|=1<<id-1;
            if (f[x][i].opt==(1<<n)-1)
                return(true);
            flag=true;
            break;
        }
    if (!flag && id==1)
        f[x].push_back(hash(now,now1,1));
    for (int i=len;i<a[id];i++)
    {
        now=now*lq+s[id][i]-'A'-p*(s[id][i-len]-'A');
        now1=now1*LQ+s[id][i]-'A'-q*(s[id][i-len]-'A');
        int x=now%mod;
        flag=false;
        for (int j=0;j<f[x].size();j++)
            if (now==f[x][j].h1 && now1==f[x][j].h2)
            {
                f[x][j].opt|=1<<id-1;
                if (f[x][j].opt==(1<<n)-1)
                    return(true);
                flag=true;
                break;
            }
        if (!flag && id==1)
            f[x].push_back(hash(now,now1,1));
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%s",s[i]);
        int r=1<<30;
        for (int i=1;i<=n;i++)
        {
            a[i]=strlen(s[i]);
            r=min(r,a[i]);
        }
        int l=0,ans=0;
        t=0;
        while (l<=r)
        {
            int mid=l+r>>1;
            t++;
            bool flag=false;
            for (int i=0;i<mod;i++)
                f[i].clear();
            for (int i=1;i<=n;i++)
                if (get(i,mid))
                    flag=true;
            if (flag)
                ans=mid,l=mid+1;
            else
                r=mid-1;
        }
        printf("%d\n",ans);
    }
    return(0);
}

