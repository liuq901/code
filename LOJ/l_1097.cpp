#include <cstdio>
#include <vector>
using namespace std;
const int n=1429431;
int ans[100010],c[1430000];
void modify(int x,int value)
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
int find(int x)
{
    int l=1,r=n,ans;
    while (l<=r)
    {
        int mid=l+r>>1;
        if (query(mid)>=x)
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    return(ans);
}
void init()
{
    for (int i=1;i<=n;i++)
        modify(i,1);
    int cnt=2,t=2,tot=n;
    while (tot>100000)
    {
        vector <int> now;
        for (int i=t;i<=tot;i+=t)
            now.push_back(find(i));
        for (int i=0;i<now.size();i++)
            modify(now[i],-1);
        tot-=now.size();
        t=find(cnt++);
    }
    for (int i=1;i<=100000;i++)
        ans[i]=find(i);
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
        static int id=0;
        printf("Case %d: %d\n",++id,ans[n]);
    }
    return(0);
}

