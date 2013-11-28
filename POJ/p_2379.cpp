#include <cstdio>
#include <algorithm>
using namespace std;
struct submit
{
    int team,num,time;
    bool ac;
};
struct team
{
    int id,solve,pen,ac[30];
};
inline bool operator <(const submit &a,const submit &b)
{
    return(a.time<b.time);
}
inline bool operator <(const team &a,const team &b)
{
    if (a.solve!=b.solve)
        return(a.solve>b.solve);
    return(a.pen<b.pen || a.pen==b.pen && a.id<b.id);
}
submit a[1010];
team b[1010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d%d%d",&a[i].team,&a[i].num,&a[i].time,&a[i].ac);
    sort(a+1,a+m+1);
    for (int i=1;i<=n;i++)
        b[i].id=i;
    for (int i=1;i<=m;i++)
    {
        int x=a[i].team,y=a[i].num;
        if (b[x].ac[y]==-1)
            continue;
        if (a[i].ac==1)
        {
            b[x].solve++;
            b[x].pen+=a[i].time+b[x].ac[y]*1200;
            b[x].ac[y]=-1;
        }
        else
            b[x].ac[y]++;
    }
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++)
        printf("%d%c",b[i].id,i==n?'\n':' ');
    return(0);
}

