#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair <int,int> rect;
rect a[110];
int area[110];
inline int calc(const rect &a)
{
    return(a.first*a.second);
}
void cut(rect now,int p,rect &small,rect &big)
{
    p%=(now.first+now.second);
    if (p<=now.first)
    {
        small=make_pair(p,now.second);
        big=make_pair(now.first-p,now.second);
    }
    else
    {
        p-=now.first;
        small=make_pair(now.first,p);
        big=make_pair(now.first,now.second-p);
    }
    if (calc(small)>calc(big))
        swap(small,big);
}
int main()
{
    while (1)
    {
        int n,w,d;
        scanf("%d%d%d",&n,&w,&d);
        if (!n && !w && !d)
            break;
        a[1]=make_pair(w,d);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            rect now=a[x];
            for (int j=x;j<i;j++)
                a[j]=a[j+1];
            cut(now,y,a[i],a[i+1]);
        }
        for (int i=1;i<=n+1;i++)
            area[i]=calc(a[i]);
        sort(area+1,area+n+2);
        for (int i=1;i<=n+1;i++)
            printf("%d%c",area[i],i==n+1?'\n':' ');
    }
    return(0);
}

