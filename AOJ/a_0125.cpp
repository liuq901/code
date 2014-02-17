#include <cstdio>
struct date
{
    int year,month,day;
    date(int y,int m,int d):year(y),month(m),day(d){}
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
    return(a.year!=b.year || a.month!=b.month || a.day!=b.day);
}
int main()
{
    while (1)
    {
        int y1,m1,d1,y2,m2,d2;
        scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2);
        if (y1==-1 && m1==-1 && d1==-1 && y2==-1 && m2==-1 && d2==-1)
            break;
        date a(y1,m1,d1),b(y2,m2,d2);
        int ans=0;
        while (a!=b)
        {
            ans++;
            a.nextDay();
        }
        printf("%d\n",ans);
    }
    return(0);
}

