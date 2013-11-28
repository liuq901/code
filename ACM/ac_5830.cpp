#include <cstdio>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
const string mon[]={"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
map <string,int> M;
struct date
{
    int year,month,day,hour;
    date(int y,string m,int d,int h):year(y),month(M[m]),day(d),hour(h){}
    void next()
    {
        if (++hour==24)
        {
            hour=0;
            nextDay();
        }
    }
    void nextDay()
    {
        if (++day==lastDay()+1)
        {
            day=1;
            nextMonth();
        }
    }
    void nextMonth()
    {
        if (++month==13)
        {
            month=1;
            ++year;
        }
    }
    int lastDay()
    {
        if (month==2)
            return(28+leap());
        if (month==4 || month==6 || month==9 || month==11)
            return(30);
        return(31);
    }
    bool leap()
    {
        if (year%400==0)
            return(true);
        if (year%100==0)
            return(false);
        return(year%4==0);
    }
};
inline bool operator !=(const date &a,const date &b)
{
    return(a.year!=b.year || a.month!=b.month || a.day!=b.day || a.hour!=b.hour);
}
struct tree
{
    int l,r,x;
};
int S,w[100010],order[2510][2];
char buf[100];
tree a[270000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r;
    if (l==r)
    {
        a[x].x=w[l]-S*l;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    a[x].x=min(a[ls].x,a[rs].x);
}
int query(int x,int l,int r)
{
    if (l==a[x].l && r==a[x].r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    return(min(query(ls,l,mid),query(rs,mid+1,r)));
}
int main()
{
    int n,m;
    for (int i=1;i<=12;i++)
        M[mon[i]]=i;
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        date now(2000,"Jan",1,0);
        int cnt=1;
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%s%d%d%d%d",buf,&x,&y,&z,&order[i][1]);
            date here(y,buf,x,z);
            while (now!=here)
            {
                now.next();
                cnt++;
            }
            order[i][0]=cnt;
        }
        int T;
        scanf("%d%d",&T,&S);
        for (int i=1;i<=m;i++)
            scanf("%d",&w[i]);
        build(1,1,m);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            int v=query(1,max(1,order[i][0]-T+1),order[i][0]);
            ans+=ll(S*order[i][0]+v)*order[i][1];
        }
        printf("%lld\n",ans);
    }
    return(0);
}

