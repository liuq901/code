#include <cstdio>
#include <string>
using namespace std;
const string name[]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
int get(const string &s)
{
    for (int i=1;i<=12;i++)
        if (s==name[i])
            return(i);
}
int leap(int x)
{
    if (x%400==0)
        return(true);
    if (x%100==0)
        return(false);
    return(x%4==0);
}
int calc(int y,int m,int d)
{
    return(y/4-y/100+y/400-(leap(y) && (m==1 || m==2 && d<29)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        char buf[20];
        int y1,y2,m1,m2,d1,d2;
        scanf("%s%d,%d",buf,&d1,&y1);
        m1=get(buf);
        scanf("%s%d,%d",buf,&d2,&y2);
        m2=get(buf);
        static int id=0;
        printf("Case %d: %d\n",++id,calc(y2,m2,d2)-calc(y1,m1,d1)+(m1==2 && d1==29));
    }
    return(0);
}

