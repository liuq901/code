#include <cstdio>
#include <cstdlib>
const int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(int x)
{
    if (x%400==0)
        return(true);
    if (x%100==0)
        return(false);
    return(x%4==0);
}
int calc(int y,int m,int d)
{
    int ret=d;
    for (int i=0;i<y;i++)
        ret+=365+leap(i);
    for (int i=1;i<m;i++)
    {
        ret+=a[i];
        if (i==2 && leap(y))
            ret++;
    }
    return(ret);
}
int main()
{
    int y1,m1,d1,y2,m2,d2;
    while (scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2)==6)
        printf("%d\n",abs(calc(y1,m1,d1)-calc(y2,m2,d2)));
    return(0);
}

