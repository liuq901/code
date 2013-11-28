#include <cstdio>
#include <cstdlib>
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
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
point A,B,C,O(0,0);
int main()
{
    int ans=0;
    while (scanf("%d,%d,%d,%d,%d,%d",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y)==6)
        ans+=area(A,B,C)==area(A,B,O)+area(A,C,O)+area(B,C,O);
    printf("%d\n",ans);
    return(0);
}

