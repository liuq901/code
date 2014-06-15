#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
pair <int,int> a[10010];
unsigned c[60][10010],f[60][10010],g[60][10010];
int n;
unsigned query(unsigned c[],int x)
{
    unsigned ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
void insert(unsigned c[],int x,unsigned value)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]+=value;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d%d",&n,&m);
        vector <int> value;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].first,&a[i].second);
            value.push_back(a[i].second);
        }
        sort(value.begin(),value.end());
        value.erase(unique(value.begin(),value.end()),value.end());
        for (int i=1;i<=n;i++)
            a[i].second=lower_bound(value.begin(),value.end(),a[i].second)-value.begin()+1;
        sort(a+1,a+n+1);
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for (int i=1;i<=n;i++)
            for (int j=0;j<=m;j++)
            {
                int x=a[i].second;
                unsigned F=query(f[j],x-1)+query(c[j],x-1),G=query(g[j],n)-query(g[j],x)+query(c[j],n)-query(c[j],x),C=0;
                F-=query(f[j],x)-query(f[j],x-1);
                G-=query(g[j],x)-query(g[j],x-1);
                C-=query(c[j],x)-query(c[j],x-1);
                if (j==0)
                    C++;
                else
                    F+=query(g[j-1],x-1),G+=query(f[j-1],n)-query(f[j-1],x);
                insert(f[j],x,F);
                insert(g[j],x,G);
                insert(c[j],x,C);
            }
        unsigned ans=query(f[m],n)+query(g[m],n)+query(c[m],n);
        if (m==0)
            ans++;
        static int id=0;
        printf("Case %d: %u\n",++id,ans);
    }
    return(0);
}

