#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
    void in()
    {
        scanf("%d%d",&x,&y);
    }
};
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline bool check(const point &a,const point &b,const point &c,const point &d)
{
    vector <point> p;
    p.push_back(a);
    p.push_back(b);
    p.push_back(c);
    p.push_back(d);
    sort(p.begin(),p.end());
    if (p[0].x!=p[1].x || p[2].x!=p[3].x)
        return(false);
    if (p[0].y!=p[2].y || p[1].y!=p[3].y)
        return(false);
    if (p[2].x==p[0].x || p[1].y==p[0].y)
        return(false);
    return(p[2].x-p[0].x==p[1].y-p[0].y);
}
point a[30];
bool f[1100000];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==-1)
            break;
        for (int i=1;i<=n;i++)
            a[i].in();
        int limit=1<<n;
        for (int i=0;i<limit;i++)
            f[i]=false;
        vector <int> lq;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                for (int k=j+1;k<=n;k++)
                    for (int l=k+1;l<=n;l++)
                        if (check(a[i],a[j],a[k],a[l]))
                            lq.push_back(1<<i-1|1<<j-1|1<<k-1|1<<l-1);
        f[0]=true;
        int ans=0;
        for (int i=0;i<limit;i++)
        {
            if (!f[i])
                continue;
            ans=max(ans,__builtin_popcount(i));
            for (int j=0;j<lq.size();j++)
            {
                int x=lq[j];
                if (i&x)
                    continue;
                f[i|x]=true;
            }
        }
        printf("%d\n",ans);
    }
    return(0);
}

