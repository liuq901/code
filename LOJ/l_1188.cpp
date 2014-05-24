#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct event
{
    int id,l,r;
};
inline bool operator <(const event &a,const event &b)
{
    return(a.r>b.r);
}
event e[50010];
int n,ans[100010],c[100010],pos[100010],prev[100010];
void insert(int x,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]+=value;
}
int query(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        memset(pos,0,sizeof(pos));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            prev[i]=pos[x];
            pos[x]=i;
        }
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&e[i].l,&e[i].r);
            e[i].id=i;
        }
        sort(e+1,e+m+1);
        memset(c,0,sizeof(c));
        for (int i=0;i<=100000;i++)
            if (pos[i])
                insert(pos[i],1);
        int last=n;
        for (int i=1;i<=m;i++)
        {
            while (last>e[i].r)
            {
                insert(last,-1);
                if (prev[last])
                    insert(prev[last],1);
                last--;
            }
            ans[e[i].id]=query(e[i].r)-query(e[i].l-1);
        }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=m;i++)
            printf("%d\n",ans[i]);
    }
    return(0);
}

