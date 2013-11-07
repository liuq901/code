#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
struct state
{
    int time,capacity;
};
inline bool operator <(const state &a,const state &b)
{
    return(a.capacity<b.capacity);
}
inline bool cmp(const state &a,const state &b)
{
    return(a.time<b.time);
}
state a[1010],b[1010];
multiset <state> s;
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].capacity,&a[i].time);
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d:%d",&b[i].capacity,&x,&y);
            b[i].time=(x-14)*60+y;
        }
        m++;
        b[m].capacity=0;
        b[m].time=1<<30;
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+m+1,cmp);
        int now=1;
        s.clear();
        for (int i=1;i<=m;i++)
        {
            while (now<=n && a[now].time<=b[i].time)
                s.insert(a[now++]);
            set <state>::iterator k=s.upper_bound(b[i]);
            if (k==s.begin())
                continue;
            s.erase(--k);
        }
        int sum=0;
        for (set <state>::iterator k=s.begin();k!=s.end();k++)
            sum+=k->capacity;
        static int id=0;
        printf("Trial %d: %d %d\n\n",++id,s.size(),sum);
    }
    return(0);
}

