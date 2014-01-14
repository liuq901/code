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
    point A,B;
    A.in(),B.in();
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        point P;
        P.in();
        int sgn=det(B-A,P-A);
        if (sgn>0)
            printf("COUNTER_CLOCKWISE\n");
        else if (sgn<0)
            printf("CLOCKWISE\n");
        else if (dot(B-A,P-A)<0)
            printf("ONLINE_BACK\n");
        else if (dot(A-B,P-B)<0)
            printf("ONLINE_FRONT\n");
        else
            printf("ON_SEGMENT\n");
    }
    return(0);
}

