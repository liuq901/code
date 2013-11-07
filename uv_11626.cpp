#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point
{
    int x,y;
    point(int x,int y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline bool cmp(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
vector <point> a,b;
void work()
{
    int n;
    scanf("%d",&n);
    a.clear();
    for (int i=1;i<=n;i++)
    {
        int x,y;
        char ch;
        scanf("%d%d %c",&x,&y,&ch);
        if (ch=='Y')
            a.push_back(point(x,y));
    }
    sort(a.begin(),a.end(),cmp);
    b.clear();
    for (int i=0;i<a.size();i++)
    {
        while (b.size()>=2 && det(b.back()-b[b.size()-2],a[i]-b.back())<0)
            b.pop_back();
        b.push_back(a[i]);
    }
    int tmp=b.size();
    for (int i=a.size()-2;i;i--)
    {
        while (b.size()>tmp && det(b.back()-b[b.size()-2],a[i]-b.back())<0)
            b.pop_back();
        b.push_back(a[i]);
    }
    printf("%d\n",b.size());
    for (int i=0;i<b.size();i++)
        printf("%d %d\n",b[i].x,b[i].y);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
        work();
    return(0);
}

