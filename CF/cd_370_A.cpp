#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int x0,y0,x1,y1;
int calc1()
{
    if (x0==x1 || y0==y1)
        return(1);
    return(2);
}
int calc2()
{
    if ((x0+y0)%2!=(x1+y1)%2)
        return(0);
    if (x0+y0==x1+y1 || x0-y0==x1-y1)
        return(1);
    return(2);
}
int calc3()
{
    int dx=abs(x0-x1),dy=abs(y0-y1);
    return(dx+dy-min(dx,dy));
}
int main()
{
    scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
    printf("%d %d %d\n",calc1(),calc2(),calc3());
    return(0);
}

