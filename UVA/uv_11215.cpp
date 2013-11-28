#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct frac
{
    int x,y;
    frac(int _x,int _y)
    {
        x=_x,y=_y;
        int p=__gcd(abs(x),abs(y));
        x/=p,y/=p;
        if (y<0)
            x*=-1,y*=-1;
    }
    bool zero() const
    {
        return(x==0);
    }
};
inline frac operator +(const frac &a,const frac &b)
{
    return(frac(a.x*b.y+a.y*b.x,a.y*b.y));
}
inline frac operator -(const frac &a,const frac &b)
{
    return(frac(a.x*b.y-a.y*b.x,a.y*b.y));
}
inline frac operator *(const frac &a,const frac &b)
{
    return(frac(a.x*b.x,a.y*b.y));
}
inline frac operator /(const frac &a,const frac &b)
{
    return(frac(a.x*b.y,a.y*b.x));
}
inline bool operator <(const frac &a,const frac &b)
{
    return(a.x*b.y<b.x*a.y);
}
inline bool operator ==(const frac &a,const frac &b)
{
    return(a.x==b.x && a.y==b.y);
}
set <vector <frac> > S;
int ans;
void dfs(vector <frac> a)
{
    sort(a.begin(),a.end());
    if (S.count(a))
        return;
    S.insert(a);
    if (a.size()==1)
    {
        ans++;
        return;
    }
    for (int i=0;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
        {
            frac x=a[i],y=a[j];
            vector <frac> b=a;
            b.erase(b.begin()+j);
            b[i]=x+y;
            dfs(b);
            b[i]=x-y;
            dfs(b);
            b[i]=y-x;
            dfs(b);
            b[i]=x*y;
            dfs(b);
            if (!y.zero())
            {
                b[i]=x/y;
                dfs(b);
            }
            if (!x.zero())
            {
                b[i]=y/x;
                dfs(b);
            }
        }
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        vector <frac> a;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a.push_back(frac(x,1));
        }
        ans=0;
        S.clear();
        dfs(a);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

