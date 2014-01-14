#include <cstdio>
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
inline int dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        point a,b,c,d;
        a.in(),b.in(),c.in(),d.in();
        if (det(b-a,d-c)==0)
            printf("2\n");
        else if (dot(b-a,d-c)==0)
            printf("1\n");
        else
            printf("0\n");
    }
    return(0);
}

