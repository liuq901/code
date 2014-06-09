#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct event
{
    int l,r,value;
    event(int l,int r,int value):l(l),r(r),value(value){}
};
inline bool operator <(const event &a,const event &b)
{
    return(a.value<b.value || a.value==b.value && a.l<b.l);
}
unsigned c[510][510];
int n,a[510];
unsigned query(int x,int y)
{
    unsigned ret=0;
    for (int i=x;i;i-=i&-i)
        for (int j=y;j;j-=j&-j)
            ret+=c[i][j];
    return(ret);
}
void insert(int x,int y,unsigned value)
{
    for (int i=x;i<=n;i+=i&-i)
        for (int j=y;j<=n;j+=j&-j)
            c[i][j]+=value;
}
unsigned calc(int l,int r)
{
    return(query(r,r)-query(l-1,r)-query(r,l-1)+query(l-1,l-1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        vector <event> e;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                e.push_back(event(i,j,a[i]+a[j]));
        sort(e.begin(),e.end());
        memset(c,0,sizeof(c));
        unsigned ans=0;
        for (int i=0;i<e.size();i++)
        {
            unsigned value=calc(e[i].l+1,e[i].r-1)+1;
            ans+=value;
            insert(e[i].l,e[i].r,value);
        }
        static int id=0;
        printf("Case %d: %u\n",++id,ans);
    }
    return(0);
}

