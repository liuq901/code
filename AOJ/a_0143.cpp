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
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int area(const point &a,const point &b,const point &c)
{
    return(abs(det(b-a,c-a)));
}
inline bool in(const point &p,const point &a,const point &b,const point &c)
{
    return(area(p,a,b)+area(p,a,c)+area(p,b,c)==area(a,b,c));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point a,b,c,p,q;
        a.in(),b.in(),c.in(),p.in(),q.in();
        printf("%s\n",in(p,a,b,c)!=in(q,a,b,c)?"OK":"NG");
    }
    return(0);
}

