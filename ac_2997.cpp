#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
struct date
{
    int year,month,day;
    date(){}
    date(int x):year(x/10000),month(x%10000/100),day(x%100){}
    bool leap() const
    {
        if (year%400==0)
            return(true);
        if (year%100==0)
            return(false);
        return(year%4==0);
    }
    int last() const
    {
        if (month==2)
            return(28+leap());
        if (month==4 || month==6 || month==9 || month==11)
            return(30);
        return(31);
    }
    date prev() const
    {
        date tmp=*this;
        tmp.day--;
        if (tmp.day==0)
        {
            tmp.month--;
            if (tmp.month==0)
            {
                tmp.year--;
                tmp.month=12;
            }
            tmp.day=tmp.last();
        }
        return(tmp);
    }
    date next() const
    {
        date tmp=*this;
        tmp.day++;
        if (tmp.day>tmp.last())
        {
            tmp.month++;
            tmp.day=1;
            if (tmp.month>12)
            {
                tmp.year++;
                tmp.month=1;
            }
        }
        return(tmp);
    }
    void print() const
    {
        printf("%d/%d/%d",month,day,year);
    }
};
inline bool operator <(const date &a,const date &b)
{
    if (a.year!=b.year)
        return(a.year<b.year);
    if (a.month!=b.month)
        return(a.month<b.month);
    return(a.day<b.day);
}
inline bool operator ==(const date &a,const date &b)
{
    return(a.year==b.year && a.month==b.month && a.day==b.day);
}
inline bool operator <=(const date &a,const date &b)
{
    return(a<b || a==b);
}
pair <date,date> a[110];
vector <pair <date,date> > b,ans;
int n;
void work(const date &l,const date &r,int dep)
{
    if (dep==n+1)
    {
        b.push_back(make_pair(l,r));
        return;
    }
    date x=a[dep].first,y=a[dep].second;
    if (l<x && x<=r)
        work(l,x.prev(),dep+1);
    if (l<=y && y<r)
        work(y.next(),r,dep+1);
    if (r<x || y<l)
        work(l,r,dep+1);
}
int main()
{
    while (1)
    {
        int m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i]=make_pair(x,y);
        }
        b.clear();
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            work(x,y,1);
        }
        sort(b.begin(),b.end());
        ans.clear();
        for (int i=0;i<b.size();i++)
            if (!ans.empty() && b[i].first<=ans.back().second.next())
                ans.back().second=max(ans.back().second,b[i].second);
            else
                ans.push_back(b[i]);
        static int id=0;
        if (id!=0)
            printf("\n");
        printf("Case %d:\n",++id);
        if (ans.empty())
            printf("    No additional quotes are required.\n");
        else
            for (int i=0;i<ans.size();i++)
            {
                printf("    ");
                if (ans[i].first==ans[i].second)
                    ans[i].first.print();
                else
                {
                    ans[i].first.print();
                    printf(" to ");
                    ans[i].second.print();
                }
                printf("\n");
            }
    }
    return(0);
}

