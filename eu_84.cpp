#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int random(int x)
{
    return(rand()%x+1);
}
int cnt[40],a[40];
inline bool cmp(int x,int y)
{
    return(cnt[x]>cnt[y]);
}
int CH(int now)
{
    int x=random(16);
    if (x==1)
        return(0);
    else if (x==2)
        return(10);
    else if (x==3)
        return(11);
    else if (x==4)
        return(24);
    else if (x==5)
        return(39);
    else if (x==6)
        return(5);
    else if (x==7 || x==8)
        return(now==7?15:now==22?25:5);
    else if (x==9)
        return(now==22?28:12);
    else if (x==10)
        return((now+37)%40);
    return(now);
}
int CC(int now)
{
    int x=random(16);
    if (x==1)
        return(0);
    else if (x==2)
        return(10);
    return(now);
}
int main()
{
    int now=0,doubles=0;
    for (int T=1;T<=1000000;T++)
    {
        int x=random(4),y=random(4);
        if (x==y)
            doubles++;
        else
            doubles=0;
        if (doubles==3)
        {
            now=10;
            doubles=0;
        }
        else
        {
            now=(now+x+y)%40;
            if (now==7 || now==22 || now==36)
                now=CH(now);
            if (now==2 || now==17 || now==33)
                now=CC(now);
            if (now==30)
                now=10;
        }
        cnt[now]++;
    }
    for (int i=0;i<40;i++)
        a[i]=i;
    sort(a,a+40,cmp);
    printf("%02d%02d%02d\n",a[0],a[1],a[2]);
    return(0);
}

