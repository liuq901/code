#include <cstdio>
struct Time
{
    int h,m,s;
    Time(int h,int m,int s):h(h),m(m),s(s){}
    void next()
    {
        s++;
        if (s==60)
            m++,s=0;
        if (m==60)
            h++,m=0;
    }
};
inline bool operator !=(const Time &a,const Time &b)
{
    return(a.h!=b.h || a.m!=b.m || a.s!=b.s);
}
int main()
{
    Time begin(0,0,0),end(12,0,0);
    for (Time now=begin;now!=end;now.next())
    {
        int a=now.s,b=now.m,c=now.h*5+now.m/12;
        int x=b-a,y=c-b,z=a-c;
        if (x<0)
            x+=60;
        if (y<0)
            y+=60;
        if (z<0)
            z+=60;
        if (x==y || x==z || y==z)
            printf("%02d:%02d:%02d\n",now.h,now.m,now.s);
    }
    return(0);
}

