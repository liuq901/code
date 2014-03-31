#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int lq=10007;
ull ha[2010],hb[2010],p[2010];
char a[2010],b[2010];
int n,m;
void init()
{
    for (int i=1;i<=n;i++)
        ha[i]=ha[i-1]*lq+a[i];
    for (int i=1;i<=m;i++)
        hb[i]=hb[i-1]*lq+b[i];
    p[0]=1;
    for (int i=1;i<=max(n,m);i++)
        p[i]=p[i-1]*lq;
}
ull hash(ull *a,int start,int len)
{
    return(a[start+len-1]-a[start-1]*p[len]);
}
bool check(int l1,int l2,const vector <int> &c)
{
    int t1=1,t2=1;
    ull now=hash(hb,c[0],l2);
    for (int i=0;i<c.size();i++)
    {
        int delta=c[i]-t1;
        if (hash(ha,t1,delta)!=hash(hb,t2,delta) || hash(hb,t2+delta,l2)!=now)
            return(false);
        t1+=delta+l1;
        t2+=delta+l2;
    }
    return(hash(ha,t1,n-t1+1)==hash(hb,t2,m-t2+1));
}
int main()
{
    freopen("curiosity.in","r",stdin);
    freopen("curiosity.out","w",stdout);
    gets(a+1);
    gets(b+1);
    n=strlen(a+1);
    m=strlen(b+1);
    init();
    int l1,l2,pos;
    l1=l2=10000000;
    for (int i=1;i<=n;i++)
    {
        vector <pair <ull,int> > f;
        for (int j=1;j<=n-i+1;j++)
            f.push_back(make_pair(hash(ha,j,i),j));
        sort(f.begin(),f.end());
        for (int j=0,k;j<f.size();j=k)
        {
            vector <int> c;
            int next=0;
            for (k=j;k<f.size() && f[j].first==f[k].first;k++)
                if (f[k].second>=next)
                {
                    c.push_back(f[k].second);
                    next=f[k].second+i;
                }
            int delta=n-i*c.size();
            if (delta>m || (m-delta)%c.size()!=0)
                continue;
            int len=(m-delta)/c.size();
            if (check(i,len,c) && i+len<l1+l2)
            {
                l1=i;
                l2=len;
                pos=c[0];
            }
        }
    }
    printf("s/");
    for (int i=0;i<l1;i++)
        printf("%c",a[pos+i]);
    printf("/");
    for (int i=0;i<l2;i++)
        printf("%c",b[pos+i]);
    printf("/g\n");
    return(0);
}

