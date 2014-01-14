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
inline bool online(const point &p,const point &a,const point &b)
{
    return(det(p-a,b-a)==0 && dot(p-a,p-b)<=0);
}
inline int side(const point &p,const point &a,const point &b)
{
    int x=det(p-a,b-a);
    return(x<0?-1:x>0);
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
            printf("%d\n",online(a,c,d) || online(b,c,d) || online(c,a,b) || online(d,a,b));
        else
            printf("%d\n",side(a,c,d)!=side(b,c,d) && side(c,a,b)!=side(d,a,b));
    }
    return(0);
}

