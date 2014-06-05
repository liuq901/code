#include <cstdio>
#include <cstdlib>
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
    void in()
    {
        scanf("%d%d",&x,&y);
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point a,b,c;
        a.in(),b.in(),c.in();
        point d=c+a-b;
        static int id=0;
        printf("Case %d: %d %d %d\n",++id,d.x,d.y,abs(det(b-a,c-a)));
    }
    return(0);
}

